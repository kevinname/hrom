#ifndef __UPGRADE_SD_H__
#define __UPGRADE_SD_H__

#define IMG_CIPHER_LEN      0x400
#define IMG_FSPATH          "0:boot/image.pack"
#define LIST_FSPATH         "0:boot/btaddr.list"
#define STAT_FSPATH         "0:boot/statis.txt"

int hs_upgrade_sdProc(void);

#endif
