#include "ENC28J60_Helper.h"
#include <delays.h>

BYTE selectedBank = 1;

void ENC28J60_WriteControlRegByte(BYTE address, BYTE data)
{
    ENC28J60_SelectBank(address & BANK_ANY);    // Check we are in correct bank
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_WRITE_CONTROL_REG | (address & ~BANK_ANY));   // Write to register 'address'
    writeByteToSPI2(data);               // Write 'data'
    PORTCbits.RC2 = 1;      // End communication
}

void ENC28J60_SystemReset(void)
{
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_SYSTEM_RESET);   // Perform reset
    PORTCbits.RC2 = 1;      // End communication
    delayBetweenSPIBytes2();
    delayBetweenSPIBytes2();    //Must wait 50us
}

BYTE ENC28J60_ReadControlRegByte(BYTE address)
{
    // Need to implement ability to ignore first byte received when reading MAC and MII regeisters
    
    BYTE returnedData;
    ENC28J60_SelectBank(address & BANK_ANY);    // Check we are in correct bank
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_READ_CONTROL_REG | (address & ~BANK_ANY));   // Write to MIREGADR
    returnedData = writeByteToSPI2(0x55);                         // Writing to PHLCON
    PORTCbits.RC2 = 1;      // End communication

    return returnedData;
}

void ENC28J60_WriteBufferMem(BYTE data)
{
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_WRITE_BUFFER_MEM);   // Write to register 'address'
    writeByteToSPI2(data);               // Write 'data'
    PORTCbits.RC2 = 1;      // End communication
}

BYTE ENC28J60_ReadBufferMem(void)
{
    BYTE returnedData;
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_READ_BUFFER_MEM);   // Write to MIREGADR
    returnedData = writeByteToSPI2(0x55);                         // Writing to PHLCON
    PORTCbits.RC2 = 1;      // End communication

    return returnedData;
}

void ENC28J60_WritePhyRegWord(BYTE address, WORD data)
{
    ENC28J60_WriteControlRegByte(MIREGADR, address);   // Write 'address' to MIREGADR
    delayBetweenSPIBytes2();
    ENC28J60_WriteControlRegByte(MIWRL, data);   // Write lower part of 'data' to MIWRL
    delayBetweenSPIBytes2();
    ENC28J60_WriteControlRegByte(MIWRH, (WORD)(data >> 8));   // Write lower part of 'data' to MIWRL
}

void ENC28J60_SelectBank(BYTE bank)
{
    if(!((bank == BANK_ANY) | (bank == selectedBank)))
    {
        //Change to bank 'bank'
        ENC28J60_WriteControlRegByte(ECON1, (bank >> 5) | 0x04);   // Write 0x02 to ECON1 - Move to BANK2
        selectedBank = bank;
        delayBetweenSPIBytes2();
    }
}

void ENC28J60_BitFieldSet(BYTE address, BYTE data)
{
    ENC28J60_SelectBank(address & BANK_ANY);    // Check we are in correct bank
    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI2(ENC_BIT_FIELD_SET | (address & ~BANK_ANY));   // Write to register 'address'
    writeByteToSPI2(data);               // Write 'data'
    PORTCbits.RC2 = 1;      // End communication
}

BYTE writeByteToSPI2(BYTE data)
{
    SSPBUF = data;          // Send data
    while(!SSPSTATbits.BF); // Wait for data to finish transmit
    return(SSPBUF);         // Return received data
}

void writeByteToSPIWithDelay(BYTE data)
{
    writeByteToSPI2(data);
    delayBetweenSPIBytes2();
}

void delayBetweenSPIBytes2(void)
{
    Delay1KTCYx(200);
}