#include "ff.h"
#include "platform.h"

static FATFS SDC_FS;


int fsInit(void)
{
  FRESULT err = FR_OK;

  err = f_mount(&SDC_FS, "0:", 0);
  if (err != FR_OK)
    return err;

  return err;
}
