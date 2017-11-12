!********************************************************************************************************
!
!                               (c) Copyright 2005-2014, Andes Techonology
!                                          All Rights Reserved
!
!                                           NDS32 Generic Port
!                                            GNU C Compiler
!
!********************************************************************************************************

!********************************************************************************************************
! INCLUDE ASSEMBLY CONSTANTS
!********************************************************************************************************

#include <nds32_init.inc>
#include "n12_def.h"
		
	.global main
	.global __pre_c_init
	.global __post_c_init
	.global OS_Init_Nds32
	.global OS_Int_Vectors
	.global OS_Int_Vectors_End

	.macro CallFn fn
		push	$lp
		addi    $sp, $sp, -4 	! keep 8 byte align
		bal	\fn
		addi    $sp, $sp, 4
		pop	$lp
	.endm



!******************************************************************************************************
! 	Start Entry
!******************************************************************************************************
	.section .text
	.global _start
 OS_Init_Nds32:
	_start:

	!************************** Begin of do-not-modify **************************
	! Please don't modify this code
	! Initialize the registers used by the compiler

	nds32_init	! NDS32 startup initial macro in <nds32_init.inc>

	!*************************** End of do-not-modify ***************************

#ifdef XIP_MODE	
!	bal _nds32_init_mem
#endif
#ifdef CONFIG_OSC_SUPPORT
	bal	_osc_init
#endif
	bal __cpu_c_context
	bal	__pre_c_init
!	bal	__post_c_init
	bal	main


!********************************************************************************************************
!                   __pre_c_init
!
! Note(s) : 1) __pre_c_init init SP pointer, cache,
!
!********************************************************************************************************
	.align  2
	.type   __pre_c_init, @function
__pre_c_init:

	! Processor should be in Super User mode
	! Disable interrupts, change to interruption level 0

	mfsr	$r0, $PSW
	li	$r1, #~PSW_MSK
	and	$r0, $r0, $r1
	li	$r1, #PSW_INIT
	or	$r0, $r0, $r1
	mtsr	$r0, $PSW
	isb

	mfsr	$r0, $INT_MASK
	li	$r1, #~INT_MASK_MSK
	and	$r0, $r0, $r1
	li	$r1, #INT_MASK_INIT
	or	$r0, $r0, $r1
	mtsr	$r0, $INT_MASK

	mfsr	$r0, $IVB
	li	$r1, #~IVB_MSK
	and	$r0, $r0, $r1
	li	$r1, #IVB_INIT
	or	$r0, $r0, $r1
	mtsr	$r0, $IVB	

	! The C runtime initialization could have been done
	! or will be done somewhere else. But do it again
	! does not hurt.

	! We do this on a word basis.
	! Currently, the default linker script guarantee
	! the __bss_start/_end boundary word-aligned.

	! Clear bss
	la      $r0, __bss_start
	la      $r1, _end
        sub     $r2, $r1, $r0		! $r2: Size of .bss
	beqz    $r2, clear_end

        andi    $r7, $r2, 0x1f		! $r7 = $r2 mod 32
        movi    $r3, 0
        movi    $r4, 0
        movi    $r5, 0
        movi    $r6, 0
        movi    $r8, 0
        movi    $r9, 0
        movi    $r10, 0
        beqz    $r7, clear_loop         !if $r7 == 0, bss_size%32 == 0
        sub     $r2, $r2, $r7

first_clear:
	swi.bi  $r3, [$r0], #4		!clear each word
        addi    $r7, $r7, -4
        bnez    $r7, first_clear
        li      $r1, 0xffffffe0
        and     $r2, $r2, $r1           !check bss_size/32 == 0 or not
        beqz    $r2, clear_end          !if bss_size/32 == 0 , needless to clear

clear_loop:
        smw.bim $r3, [$r0], $r10        !clear each 8 words
        addi    $r2, $r2, -32
        bgez    $r2, clear_loop

clear_end:

	! Set-up the stack pointer
	la	$sp, _stack

__cache_enable:
	mfsr	$r0, $MMU_CTL
	li	$r1, #~MMU_CTL_MSK
	and	$r0, $r0, $r1
	li	$r1, #MMU_CTL_INIT_CACHE_ON
	or	$r0, $r0, $r1
	mtsr	$r0, $MMU_CTL

	mfsr	$r0, $CACHE_CTL
	li	$r1, #~CACHE_CTL_MSK
	and	$r0, $r0, $r1
	li	$r0, #CACHE_CTL_INIT

	push	$r0	
	CallFn	n12_icache_flush;	
	pop	$r0	
	li	$r1, (0x1 << CACHE_CTL_offIC_EN)	
	or	$r0, $r0, $r1

	push	$r0
	CallFn	n12_dcache_invalidate;
	pop	$r0
	li	$r1, (0x1 << CACHE_CTL_offDC_EN)
	or	$r0, $r0, $r1
	
	mtsr	$r0, $CACHE_CTL

	ret
	.size   __pre_c_init, .-__pre_c_init
	

#define PMU_PM_CON0		    0x400e001c
#define PMU_PM_CON1		    0x400e0020
#define PMU_PM_CON          PMU_PM_CON0
#define MEM_FLASH_BASE		0x80000000

	.align  2
	.type   __cpu_c_context, @function
__cpu_c_context:
	sethi $r1, hi20(PMU_PM_CON)
	ori   $r1, $r1, lo12(PMU_PM_CON)
	lw    $r0, [$r1]
	beqz  $r0, __c_context_exit

	bal __cache_enable
	
	sethi $r1, hi20(MEM_FLASH_BASE)
	ori   $r1, $r1, lo12(MEM_FLASH_BASE)

	jr $r1
	
__c_context_exit:
	ret
	
	.end

