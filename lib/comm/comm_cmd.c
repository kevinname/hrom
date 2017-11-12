/*
    bootloader - Copyright (C) 2012~2014 HunterSun Technologies
                 pingping.wu@huntersun.com.cn
 */

/**
 * @file    comm/comm_cmd.c
 * @brief   command file.
 * @details 
 *
 * @addtogroup  comm
 * @details 
 * @{
 */
#include "comm_cmd.h"
#include "comm_mem.h"
#include "lib.h"

static hs_comm_cmd_t g_stCommCmd[] =
{
  {COMM_CMD_ENTER_DOWNLOAD,             hs_upgrade_usbDownload},

  {COMM_CMD_MEMORY_READ,                hs_comm_readmem},
  {COMM_CMD_MEMORY_WRITE,               hs_comm_writemem},
  {COMM_CMD_MEMORY_ERASE,               hs_comm_erasemem},
};

/** @} */
