#ifndef __DES_H__
#define __DES_H__

#include "stdint.h"

#define PLAIN_FILE_OPEN_ERROR -1
#define KEY_FILE_OPEN_ERROR -2
#define CIPHER_FILE_OPEN_ERROR -3
#define OK  0
#define ERR 1

typedef char ElemType;

int DES_PC1_Transform(ElemType key[64], ElemType tempbts[56]);
int DES_ROL(ElemType data[56], int time);
int DES_PC2_Transform(ElemType key[56], ElemType tempbts[48]);


int DES_Encrypt(uint8_t *plainData, uint8_t *keyData, uint8_t *cipherData, int dataLen);
int DES_Decrypt(uint8_t *cipherData, uint8_t *keyData, uint8_t *plainData, int dataLen);

#endif
