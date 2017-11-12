#ifndef __N12_DEF_H__
#define __N12_DEF_H__

#define LITTLE  0x0
#define BIG 	0x1

#ifdef  __NDS32_EB__
	#define ENDIAN BIG
#else
	#ifdef __big_endian__
		#define ENDIAN BIG
	#else
		#define ENDIAN LITTLE
	#endif
#endif
	
#define XIP_MODE 1

#include "nds32_defs.h"

#ifndef __ASSEMBLER__

#include "nds32_regs.h"

#define TLBOP(op)		__asm__ volatile ("tlbop "#op);
#define MSYNC(subtype)		__asm__ volatile ("msync "#subtype);
#define STANDBY(cond)		__asm__ volatile ("standby "#cond);


#ifdef CONFIG_CPU_DCACHE_ENABLE

#define NDS_DCache_Flush                n12_dcache_flush
#define NDS_DCache_Invalidate_Flush     n12_dcache_invalidate
#define NDS_DCache_Writeback            n12_dcache_flush_range

#else

#define NDS_DCache_Flush()              ((void)0)
#define NDS_DCache_Invalidate_Flush()   ((void)0)
#define NDS_DCache_Writeback()          ((void)0)

#endif


/* 
 * Static inline function would be traded as macro function.
 * It would be inlined into caller text object and wouldn't 
 * create an independent text object. 
 */
static inline void ISB(void)
{
	__asm__ volatile ("isb");
}

static inline void DSB(void)
{
	__asm__ volatile ("dsb");
}

static inline void GIE_ENABLE(void)
{
	__asm__ volatile ("setgie.e \n\t"
			// Junior 2014.08.04
			// add isb for -flto
			// -flto would generate special code path
			// ex :
			// 	setgie.e	(no dsb cause mfsr get old value)
			// 	nop
			// 	mfsr $r0, $psw
			"	dsb	\n\t");
}

static inline void GIE_DISABLE(void)
{
        __asm__ volatile (
			"	setgie.d	\n\t"
			"	dsb		\n\t"
			);
}

static inline void GIE_SAVE(unsigned long *var)
{
	*var = GET_PSW();
	GIE_DISABLE();
}

static inline void GIE_RESTORE(unsigned long var)
{
	if (var & PSW_mskGIE)
		GIE_ENABLE();
}

extern void *OS_CPU_Vector_Table[32];
typedef void (*isr_t)(int vector);

static inline void register_isr(int vector, isr_t isr, isr_t *old)
{
	if (old)
		*old = OS_CPU_Vector_Table[vector];

	OS_CPU_Vector_Table[vector] = isr;
}

#endif /* __ASSEMBLER__ */

/***********************************
 * SYSTEM CONSTANTS
 ***********************************/
#define VECTOR_BASE             0x00000000

#define IRQ_STACK_SIZE		5120	/* Define the IRQ stack size */
#define SYS_STACK_SIZE		256	/* Define the system stack size */
/***********************************
 * TARGET INITIALIZATION CONSTANTS
 ***********************************/

#define PSW_INIT					\
	(0x0 << PSW_offGIE				\
	 | 0x0 << PSW_offINTL				\
	 | 0x1 << PSW_offPOM				\
	 | ENDIAN << PSW_offBE				\
	 | 0x0 << PSW_offIT				\
	 | 0x0 << PSW_offDT				\
	 | 0x0 << PSW_offIME				\
	 | 0x0 << PSW_offDME				\
	 | 0x0 << PSW_offDEX				\
	 | 0x0 << PSW_offHSS)

#define PSW_MSK						\
	(PSW_mskGIE					\
	  | PSW_mskINTL					\
	  | PSW_mskPOM					\
	  | PSW_mskBE					\
	  | PSW_mskIT					\
	  | PSW_mskDT					\
	  | PSW_mskIME					\
	  | PSW_mskDME					\
	  | PSW_mskDEX					\
	  | PSW_mskHSS)

#define INT_MASK_INIT					\
	(0x0 << INT_MASK_offH0IM			\
	  | 0x1 << INT_MASK_offH1IM			\
	  | 0x0 << INT_MASK_offH2IM			\
	  | 0x0 << INT_MASK_offH3IM			\
	  | 0x0 << INT_MASK_offH4IM			\
	  | 0x0 << INT_MASK_offH5IM			\
	  | 0x1 << INT_MASK_offSIM			\
	  | 0x1 << INT_MASK_offIDIVZE)

#define INT_MASK_MSK					\
	(INT_MASK_mskH0IM				\
	  | INT_MASK_mskH1IM				\
	  | INT_MASK_mskH2IM				\
	  | INT_MASK_mskH3IM				\
	  | INT_MASK_mskH4IM				\
	  | INT_MASK_mskH5IM				\
	  | INT_MASK_mskSIM				\
	  | INT_MASK_mskIDIVZE)


#if (NO_EXTERNAL_INT_CTL == 1)

#define IVB_MSK						\
	(IVB_mskEVIC					\
	  | IVB_mskESZ					\
	  | IVB_mskIVBASE				\
	  | IVB_mskNIVIC				\
	  | IVB_mskPROG_PRI_LVL)

	#define IVB_INIT				\
		(0x0 << IVB_offIVBASE			\
			| 0x1	<< IVB_offESZ		\
			| 0x5   << IVB_offNIVIC		\
			| 0x0 << IVB_offEVIC)
			
#else
	#define IVB_MSK					\
		(IVB_mskEVIC				\
	 		| IVB_mskESZ			\
	 		| IVB_mskIVBASE)

	#define IVB_INIT				\
		(0x0 << IVB_offIVBASE			\
			| 0x1 << IVB_offESZ		\
			| 0x0 << IVB_offEVIC)
#endif

#define MMU_CTL_MSK					\
	(MMU_CTL_mskD					\
	  | MMU_CTL_mskNTC0				\
	  | MMU_CTL_mskNTC1				\
	  | MMU_CTL_mskNTC2				\
	  | MMU_CTL_mskNTC3				\
	  | MMU_CTL_mskTBALCK				\
	  | MMU_CTL_mskMPZIU				\
	  | MMU_CTL_mskNTM0				\
	  | MMU_CTL_mskNTM1				\
	  | MMU_CTL_mskNTM2				\
	  | MMU_CTL_mskNTM3)

#define MMU_CTL_INIT					\
	(0x0 << MMU_CTL_offD				\
	  | 0x0 << MMU_CTL_offNTC0			\
	  | 0x0 << MMU_CTL_offNTC1			\
	  | 0x0 << MMU_CTL_offNTC2			\
	  | 0x0 << MMU_CTL_offNTC3			\
	  | 0x0 << MMU_CTL_offTBALCK			\
	  | 0x0 << MMU_CTL_offMPZIU			\
	  | 0x0 << MMU_CTL_offNTM0			\
	  | 0x0 << MMU_CTL_offNTM1			\
	  | 0x2 << MMU_CTL_offNTM2			\
	  | 0x3 << MMU_CTL_offNTM3)
#ifdef CONFIG_CPU_DCACHE_ENABLE
#ifdef CONFIG_CPU_DCACHE_WRITETHROUGH
	/* Write through */
	#define CACHE_ABILITY	0x3
#else
	/* Write back */
	#define CACHE_ABILITY	0x2
#endif
#else
	/* Device */
	#define CACHE_ABILITY	0x0
#endif

#define MMU_CTL_INIT_CACHE_ON				\
	(0x0 << MMU_CTL_offD				\
	  | 0x0 << MMU_CTL_offNTC0		\
	  | 0x0 << MMU_CTL_offNTC1			\
	  | 0x2 << MMU_CTL_offNTC2			\
	  | 0x0 << MMU_CTL_offNTC3			\
	  | 0x0 << MMU_CTL_offTBALCK			\
	  | 0x0 << MMU_CTL_offMPZIU			\
	  | 0x0 << MMU_CTL_offNTM0			\
	  | 0x1 << MMU_CTL_offNTM1			\
	  | 0x2 << MMU_CTL_offNTM2			\
	  | 0x3 << MMU_CTL_offNTM3)

#define CACHE_CTL_MSK					\
	(CACHE_CTL_mskIC_EN				\
	  | CACHE_CTL_mskDC_EN				\
	  | CACHE_CTL_mskICALCK				\
	  | CACHE_CTL_mskDCALCK				\
	  | CACHE_CTL_mskDCCWF				\
	  | CACHE_CTL_mskDCPMW)

#define CACHE_CTL_INIT					\
	(0x0 << CACHE_CTL_offIC_EN			\
	  | 0x0 << CACHE_CTL_offDC_EN			\
	  | 0x0 << CACHE_CTL_offICALCK		\
	  | 0x0 << CACHE_CTL_offDCALCK		\
	  | 0x1 << CACHE_CTL_offDCCWF			\
	  | 0x1 << CACHE_CTL_offDCPMW)

#define CACHE_CTL_INIT_CACHE_ON				\
	(0x1 << CACHE_CTL_offIC_EN			\
	  | 0x1 << CACHE_CTL_offDC_EN			\
	  | 0x0 << CACHE_CTL_offICALCK		\
	  | 0x0 << CACHE_CTL_offDCALCK		\
	  | 0x1 << CACHE_CTL_offDCCWF			\
	  | 0x1 << CACHE_CTL_offDCPMW)

/* Add by Junior, 2012.12.18 */
#define SRIDX(MAJOR, MINOR, EXTEND)			\
	(MAJOR << 7					\
	  + MINOR << 3					\
	  + EXTEND)

#define IVIC_MSK					\
	(0x0 << 0					\
	  | 0x0 << 1					\
	  | 0x1 << 2					\
	  | 0x1 << 3					\
	  | 0x1 << 4					\
	  | 0x1 << 5					\
	  | 0x1 << 6					\
	  | 0x1 << 7					\
	  | 0x0 << 8					\
	  | 0x1 << 9					\
	  | 0x0 << 10					\
	  | 0x1 << 11					\
	  | 0x0 << 12					\
	  | 0x1 << 13					\
	  | 0x0 << 14					\
	  | 0x0 << 15					\
	  | 0x1 << 16					\
	  | 0x1 << 17					\
	  | 0x1 << 18					\
	  | 0x1 << 19					\
	  | 0x0 << 20					\
	  | 0x1 << 21					\
	  | 0x0 << 22					\
	  | 0x0 << 23					\
	  | 0x1 << 24					\
	  | 0x1 << 25					\
	  | 0x0 << 26					\
	  | 0x0 << 27					\
	  | 0x0 << 28					\
	  | 0x0 << 29					\
	  | 0x0 << 30					\
	  | 0x0 << 31)

#define INT_PRIO_MASK1					\
	(0x3 << 0					\
	| 0x3 << 2					\
	| 0x3 << 4					\
	| 0x3 << 6					\
	| 0x3 << 8					\
	| 0x3 << 10					\
	| 0x3 << 12					\
	| 0x3 << 14					\
	| 0x3 << 16					\
	| 0x3 << 18					\
	| 0x3 << 20					\
	| 0x3 << 22					\
	| 0x3 << 24					\
	| 0x1 << 26					\
	| 0x3 << 28					\
	| 0x3 << 30)

#define INT_PRIO_MASK2					\
	(0x3 << 0					\
	| 0x3 << 2					\
	| 0x2 << 4					\
	| 0x3 << 6					\
	| 0x3 << 8					\
	| 0x3 << 10					\
	| 0x3 << 12					\
	| 0x3 << 14					\
	| 0x3 << 16					\
	| 0x3 << 18					\
	| 0x3 << 20					\
	| 0x3 << 22					\
	| 0x3 << 24					\
	| 0x3 << 26					\
	| 0x3 << 28					\
	| 0x3 << 30)


#endif /* __N12_DEF_H__ */
