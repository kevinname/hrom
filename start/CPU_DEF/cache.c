#include "n12_def.h"
#include "nds32_regs.h"
#include "cache.h"
#include "string.h"
#include <nds32_intrinsic.h>

void n12_icache_flush(void){

	unsigned long end;
	unsigned long cache_line = CACHE_LINE_SIZE(ICACHE);

	end = CACHE_WAY(ICACHE) * CACHE_SET(ICACHE) * CACHE_LINE_SIZE(ICACHE);

	do {
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1I_IX_INVAL" ::"r" (end));
	} while (end > 0);

}


void n12_dcache_invalidate(void){
	unsigned long end;
	unsigned long cache_line = CACHE_LINE_SIZE(DCACHE);

  end = CACHE_WAY(DCACHE) * CACHE_SET(DCACHE) * CACHE_LINE_SIZE(DCACHE);

  do {
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1D_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1D_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1D_IX_INVAL" ::"r" (end));
    end -= cache_line;
    __asm__ volatile ("\n\tcctl %0, L1D_IX_INVAL" ::"r" (end));
	} while (end > 0);

  __nds32__msync_store();
  __nds32__dsb();
}

void nds32_dcache_clean(void){

    __nds32__cctl_l1d_wball_one_lvl();
	__nds32__msync_store();
	__nds32__dsb();
}



