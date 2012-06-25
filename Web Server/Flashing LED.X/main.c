/* 
 * File:   main.c
 * Author: Anthony
 *
 * Created on 9 May 2012, 5:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Global_Declarations.h"
#include "18F4685_Config_Bits.h"
#include <delays.h>

#include "ENC28J60_Helper.h"
#include "ENC28J60_ARP.h"
#include "UART_Helper.h"
#include "ENC28J60_Packet.h"

//#include "Include/GenericTypeDefs.h"

#define GetSystemClock()		(20000000ul)      // Hz
#define GetInstructionClock()	(GetSystemClock()/4)
#define GetPeripheralClock()	GetInstructionClock()

/*
 * 
 */
void delayms(WORD ms);
BYTE writeByteToSPI(BYTE data);
void delayBetweenSPIBytes(void);

void main(void) {

    int i = 0;
    //int SPIDataReceived = 0;

    //Initialise
    TRISC = 0b10010000; //Set for USART

    //Initialise USART
    TXSTA = 0b00100110;
    RCSTA = 0b10010000;
    BAUDCON = 0b00001000;

    SPBRGH = 0x02;
    SPBRG = 0x08;

    //Init SPI
    SSPSTAT = 0b11000000;
    SSPCON1 = 0b00100010;
    


    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;
    Delay10KTCYx(250);
    PORTCbits.RC0 = !PORTCbits.RC0;

    // ***Init ENC28J60***

    // Perform full system reset
    ENC28J60_SystemReset();

    // Configure RX and TX buffers
        // TX buffer
    ENC28J60_WriteControlRegByte(ETXSTL, 0x00);   // Write lower part of 0x0000 to ETHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ETXSTH, 0x00);   // Write higher part of 0x0000 to ETHSTH
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ETXNDL, 0x3C);   // Write lower part of 0x0BE9 to ETHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ETXNDH, 0x00);   // Write higher part of 0x0BE9 to ETHSTH
    delayBetweenSPIBytes();

    ENC28J60_WriteControlRegByte(EWRPTL, 0x00);   // Write lower part of 0x0BE9 to ETHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(EWRPTH, 0x00);   // Write higher part of 0x0BE9 to ETHSTH
    delayBetweenSPIBytes();

        // RX buffer
    ENC28J60_WriteControlRegByte(ERXSTL, 0xFA);   // Write lower part of 0x0BEA to ERHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERXSTH, 0x0B);   // Write higher part of 0x0BEA to ERHSTH
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERXNDL, 0xFF);   // Write lower part of 0x1FFF to ERHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERXNDH, 0x1F);   // Write higher part of 0x1FFF to ERHSTH
    delayBetweenSPIBytes();

    ENC28J60_WriteControlRegByte(ERXWRPTL, 0xFA);   // Write lower part of 0x0BEA to ERHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERXWRPTH, 0x0B);   // Write higher part of 0x0BEA to ERHSTH
    delayBetweenSPIBytes();

    ENC28J60_WriteControlRegByte(ERXRDPTL, 0xFA);   // Write lower part of 0x0BEA to ERHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERXRDPTH, 0x0B);   // Write higher part of 0x0BEA to ERHSTH
    delayBetweenSPIBytes();

        ENC28J60_WriteControlRegByte(ERDPTL, 0xFA);   // Write lower part of 0x0BEA to ERHSTL
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(ERDPTH, 0x0B);   // Write higher part of 0x0BEA to ERHSTH
    delayBetweenSPIBytes();

        // Configure MAC
    ENC28J60_WriteControlRegByte(MACON1, 0x0D);   // Enable MAC
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MACON3, 0xF0);   // Enable Auto padding and CRC
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MACON4, 0x40);   // Wait when collision occurs
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MABBIPG, 0x12);   // Recommended setting
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAIPGL, 0x12);   // Recommended setting
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAIPGH, 0x0C);   // Recommended setting
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAMXFLL, 0xEE);   // Set max packet size to d1518 = 0x05EE
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAMXFLH, 0x05);   // Set max packet size to d1518 = 0x05EE
    delayBetweenSPIBytes();
        //Program my MAC
    ENC28J60_WriteControlRegByte(MAADR1, 0x00);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAADR2, 0x04);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAADR3, 0xA3);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAADR4, 0x55);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAADR5, 0x55);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();
    ENC28J60_WriteControlRegByte(MAADR6, 0x55);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();


    // Delete any data already received
    ENC28J60_WriteControlRegByte(EPKTCNT, 0x00);   // Set my MAC address to 0x555555555555
    delayBetweenSPIBytes();

        // Configure filter
    ENC28J60_WriteControlRegByte(ERXFCON, 0xC0);   // Recommended setting - Dest MAC must match
    delayBetweenSPIBytes();



    // Configure LEDS on ENC28J60
        // Write a value of 0x3B80 to PHLCON
    ENC28J60_WritePhyRegWord(PHLCON, 0x3B70);       // Configure LEDS
    ENC28J60_WritePhyRegWord(PHCON1, 0x0000);       // Recommended settings - Half Duplex
    ENC28J60_WritePhyRegWord(PHCON2, 0x0100);       // Recommended settings - Prevent data being looped back to receiver

    // Enable receiving packets
    delayBetweenSPIBytes2();
    ENC28J60_BitFieldSet(ECON1, 0x04);
    delayBetweenSPIBytes2();


    ENC28J60_SendARPRequest();

    while(1)
    {
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        Delay1KTCYx(200);
        for(i = 0; i<100; i++)
        {
            delayms(100);
        }
        PORTCbits.RC0 = !PORTCbits.RC0;

        /*PORTCbits.RC2 = 0;      // Start communication

        //TXREG = writeByteToSPI(ENC_READ_CONTROL_REG | ETXNDL);   // Request EIE Control register
        //TXREG = writeByteToSPI(ERXSTL & ~BANK_ANY);   // Request EIE Control register
        //TXREG = writeByteToSPI(0xAA);   // Write garbage so that we can get data back.
        /*UART_WriteByte(0x55);
        UART_WriteByte(ENC28J60_ReadControlRegByte(ESTAT));

        PORTCbits.RC2 = 1;*/      // End communication

        delayBetweenSPIBytes();
                
        if((ENC28J60_ReadControlRegByte(EIR) & 0x40) > 0)
        {
            //Packet received
            delayBetweenSPIBytes();
            ENC28J60_PacketReceived();
        }

        //SPIDataReceived = 0;

        //TXREG = 0x55;
        //TXREG = SSPBUF;
    }

}

void delayBetweenSPIBytes(void)
{
    Delay1KTCYx(200);
}

BYTE writeByteToSPI(BYTE data)
{
    SSPBUF = data;          // Send data
    while(!SSPSTATbits.BF); // Wait for data to finish transmit
    return(SSPBUF);         // Return received data
}

BYTE writeTwoBytesToSPI(BYTE address, BYTE data)
{
    BYTE returnedData;

    PORTCbits.RC2 = 0;      // Start communication
    writeByteToSPI(ENC_WRITE_CONTROL_REG | address);   // Write to MIREGADR
    returnedData = writeByteToSPI(data);                         // Writing to PHLCON
    PORTCbits.RC2 = 1;      // End communication
    
    return returnedData;
}

void delayms(WORD ms)
{
    /*LONGLONG i, j;
    for(i = 0; i < ms; i++)
    {
        for(j = 0; j < 1000; j++)
        {
            Delay1KTCYx(1);
        }
    }*/
    //BYTE i;// = 2;
    //for(i = 0; i <= 1; i++)
    //while(ms > 0)
    //{
        //i--;
    Delay10KTCYx(ms);
    //Delay10KTCYx(250);
    //ms--;
    //}
    //Delay1KTCYx(200);
    //Delay1KTCYx(200);
    //Delay1KTCYx(200);
}

