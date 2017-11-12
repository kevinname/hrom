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

#include "n12_def.h"
#include "common.h"
		
	.global ANS_Int_Vectors
	.global ANS_Int_Vectors_End	
	
!********************************************************************************************************
! 	Interrupt Entry Table
!********************************************************************************************************

	.section .nds32_init, "ax"

ANS_Int_Vectors:
	b	OS_Init_Nds32			!  (0) Trap Reset/NMI
	VECTOR	HANDLE_TLB_Fill		        !  (1) Trap TLB fill
	VECTOR	HANDLE_PTE_Not_Present		!  (2) Trap PTE not present
	VECTOR	HANDLE_TLB_Misc		        !  (3) Trap TLB misc
	VECTOR	HANDLE_TLB_VLPT_Miss		!  (4) Trap TLB VLPT miss
	VECTOR	HANDLE_Machine_Error		!  (5) Trap Machine error
	VECTOR	HANDLE_Debug_Related		!  (6) Trap Debug related
	VECTOR	HANDLE_General_Exception	!  (7) Trap General exception
	VECTOR	HANDLE_Syscall			    !  (8) Syscall

    VECTOR  HANDLE_HW0           !  (9) Interrupt HW0   
    VECTOR  HANDLE_HW1           ! (10) Interrupt HW1
    VECTOR  HANDLE_HW2           ! (11) Interrupt HW2
    VECTOR  HANDLE_HW3           ! (12) Interrupt HW3
    VECTOR  HANDLE_HW4           ! (13) Interrupt HW4
    VECTOR  HANDLE_HW5           ! (14) Interrupt HW5
    VECTOR  HANDLE_HW6           ! (15) Interrupt HW6    
    VECTOR  HANDLE_HW7           ! (16) Interrupt HW7
    VECTOR  HANDLE_HW8           ! (17) Interrupt HW8
    VECTOR  HANDLE_HW9           ! (18) Interrupt HW9
    VECTOR  HANDLE_HW10          ! (19) Interrupt HW10
    VECTOR  HANDLE_HW11          ! (20) Interrupt HW11
    VECTOR  HANDLE_HW12          ! (21) Interrupt HW12
    VECTOR  HANDLE_HW13          ! (22) Interrupt HW13
    VECTOR  HANDLE_HW14          ! (23) Interrupt HW14
    VECTOR  HANDLE_HW15          ! (24) Interrupt HW15
    VECTOR  HANDLE_HW16          ! (25) Interrupt HW16
    VECTOR  HANDLE_HW17          ! (26) Interrupt HW17
    VECTOR  HANDLE_HW18          ! (27) Interrupt HW18
    VECTOR  HANDLE_HW19          ! (28) Interrupt HW19
    VECTOR  HANDLE_HW20          ! (29) Interrupt HW20
    VECTOR  HANDLE_HW21          ! (30) Interrupt HW21
    VECTOR  HANDLE_HW22          ! (31) Interrupt HW22
    VECTOR  HANDLE_HW23          ! (32) Interrupt HW23
    VECTOR  HANDLE_HW24          ! (33) Interrupt HW24
    VECTOR  HANDLE_HW25          ! (34) Interrupt HW25
    VECTOR  HANDLE_HW26          ! (35) Interrupt HW26
    VECTOR  HANDLE_HW27          ! (36) Interrupt HW27
    VECTOR  HANDLE_HW28          ! (37) Interrupt HW28
    VECTOR  HANDLE_HW29          ! (38) Interrupt HW29
    VECTOR  HANDLE_HW30          ! (39) Interrupt HW30
    VECTOR  HANDLE_HW31          ! (40) Interrupt HW31
ANS_Int_Vectors_End:


	.section .text
HANDLE_TLB_Fill:
HANDLE_PTE_Not_Present:
HANDLE_TLB_Misc:
HANDLE_TLB_VLPT_Miss:
HANDLE_Machine_Error:
HANDLE_Debug_Related:
HANDLE_General_Exception:
HANDLE_Syscall:
die:
	b die

! Interrupt wrapper function
HANDLE_HW5:
	IntJmp OTG_IRQHandler

HANDLE_HW0:
HANDLE_HW1:
HANDLE_HW2:
HANDLE_HW3:
HANDLE_HW4:
HANDLE_HW6:
HANDLE_HW7:
HANDLE_HW8:
HANDLE_HW9:
HANDLE_HW10:
HANDLE_HW11:
HANDLE_HW12:
HANDLE_HW13:
HANDLE_HW14:
HANDLE_HW15:
HANDLE_HW16:
HANDLE_HW17:
HANDLE_HW18:
HANDLE_HW19:
HANDLE_HW20:
HANDLE_HW21:
HANDLE_HW22:
HANDLE_HW23:
HANDLE_HW24:
HANDLE_HW25:
HANDLE_HW26:
HANDLE_HW27:
HANDLE_HW28:
HANDLE_HW29:
HANDLE_HW30:
HANDLE_HW31:  
	j HANDLE_HW31

