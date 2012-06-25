#include "Global_Declarations.h"

void ENC28J60_WriteControlRegByte(BYTE address, BYTE data);
BYTE ENC28J60_ReadControlRegByte(BYTE address);
void ENC28J60_WritePhyRegWord(BYTE address, WORD data);
void ENC28J60_SelectBank(BYTE bank);
BYTE writeByteToSPI2(BYTE data);
void delayBetweenSPIBytes2(void);
void writeByteToSPIWithDelay(BYTE data);
void ENC28J60_BitFieldSet(BYTE address, BYTE data);
BYTE ENC28J60_ReadBufferMem(void);
void ENC28J60_WriteBufferMem(BYTE data);
void ENC28J60_SystemReset(void);


// *** SPI INSTRUCTION SET ***
#define     ENC_READ_CONTROL_REG    0x00
#define     ENC_READ_BUFFER_MEM     0x3A
#define     ENC_WRITE_CONTROL_REG   0x40
#define     ENC_WRITE_BUFFER_MEM    0x7A
#define     ENC_BIT_FIELD_SET       0x80
#define     ENC_BIT_FIELD_CLEAR     0xA0
#define     ENC_SYSTEM_RESET        0xFF

// ***ENC28J60 MEMORY BANKS ***
    //Define bank addresses
#define     BANK0       0x00
#define     BANK1       0x20
#define     BANK2       0x40
#define     BANK3       0x60
#define     BANK_ANY    0xE0

    // All Banks
#define     EIE     BANK_ANY | 0x1B
#define     EIR     BANK_ANY | 0x1C
#define     ESTAT   BANK_ANY | 0x1D
#define     ECON2   BANK_ANY | 0x1E
#define     ECON1   BANK_ANY | 0x1F

    // Bank 0
#define     ERDPTL      BANK0 | 0x00
#define     ERDPTH      BANK0 | 0x01
#define     EWRPTL      BANK0 | 0x02
#define     EWRPTH      BANK0 | 0x03
#define     ETXSTL      BANK0 | 0x04
#define     ETXSTH      BANK0 | 0x05
#define     ETXNDL      BANK0 | 0x06
#define     ETXNDH      BANK0 | 0x07
#define     ERXSTL      BANK0 | 0x08
#define     ERXSTH      BANK0 | 0x09
#define     ERXNDL      BANK0 | 0x0A
#define     ERXNDH      BANK0 | 0x0B
#define     ERXRDPTL    BANK0 | 0x0C
#define     ERXRDPTH    BANK0 | 0x0D
#define     ERXWRPTL    BANK0 | 0x0E
#define     ERXWRPTH    BANK0 | 0x0F
#define     EDMASTL     BANK0 | 0x10
#define     EDMASTH     BANK0 | 0x11
#define     EDMANDL     BANK0 | 0x12
#define     EDMANDH     BANK0 | 0x13
#define     EDMADSTL    BANK0 | 0x14
#define     EDMADSTH    BANK0 | 0x15
#define     EDMACSL     BANK0 | 0x16
#define     EDMACSH     BANK0 | 0x17

    // Bank 1
#define     EHT0        BANK1 | 0x00
#define     EHT1        BANK1 | 0x01
#define     EHT2        BANK1 | 0x02
#define     EHT3        BANK1 | 0x03
#define     EHT4        BANK1 | 0x04
#define     EHT5        BANK1 | 0x05
#define     EHT6        BANK1 | 0x06
#define     EHT7        BANK1 | 0x07
#define     EPMM0       BANK1 | 0x08
#define     EPMM1       BANK1 | 0x09
#define     EPMM2       BANK1 | 0x0A
#define     EPMM3       BANK1 | 0x0B
#define     EPMM4       BANK1 | 0x0C
#define     EPMM5       BANK1 | 0x0D
#define     EPMM6       BANK1 | 0x0E
#define     EPMM7       BANK1 | 0x0F
#define     EPMCSL      BANK1 | 0x10
#define     EPMCSH      BANK1 | 0x11
#define     EPMOL       BANK1 | 0x14
#define     EPMOH       BANK1 | 0x15
#define     ERXFCON     BANK1 | 0x18
#define     EPKTCNT     BANK1 | 0x19


    // Bank 2
#define     MACON1      BANK2 | 0x00
#define     MACON3      BANK2 | 0x02
#define     MACON4      BANK2 | 0x03
#define     MABBIPG     BANK2 | 0x04
#define     MAIPGL      BANK2 | 0x06
#define     MAIPGH      BANK2 | 0x07
#define     MACLCON1    BANK2 | 0x08
#define     MACLCON2    BANK2 | 0x09
#define     MAMXFLL     BANK2 | 0x0A
#define     MAMXFLH     BANK2 | 0x0B
#define     MICMD       BANK2 | 0x12
#define     MIREGADR    BANK2 | 0x14
#define     MIWRL       BANK2 | 0x16
#define     MIWRH       BANK2 | 0x17
#define     MIRDL       BANK2 | 0x18
#define     MIRDH       BANK2 | 0x19

    // Bank 3
#define     MAADR5      BANK3 | 0x00
#define     MAADR6      BANK3 | 0x01
#define     MAADR3      BANK3 | 0x02
#define     MAADR4      BANK3 | 0x03
#define     MAADR1      BANK3 | 0x04
#define     MAADR2      BANK3 | 0x05
#define     EBSTSD      BANK3 | 0x06
#define     EBSTCON     BANK3 | 0x07
#define     EBSTCSL     BANK3 | 0x08
#define     EBSTCSH     BANK3 | 0x09
#define     MISTAT      BANK3 | 0x0A
#define     EREVID      BANK3 | 0x12
#define     ECOCON      BANK3 | 0x15
#define     EFLOCON     BANK3 | 0x17
#define     EPAUSL      BANK3 | 0x18
#define     EPAUSH      BANK3 | 0x19

    // PHY Registers
#define     PHCON1      0x00
#define     PHSTAT1     0x01
#define     PHID1       0x02
#define     PHID2       0x03
#define     PHCON2      0x10
#define     PHSTAT2     0x11
#define     PHIE        0x12
#define     PHIR        0x13
#define     PHLCON      0x14
