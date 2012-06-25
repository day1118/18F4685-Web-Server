#include "ENC28J60_Packet.h"
#include "UART_Helper.h"
#include "ENC28J60_Helper.h"


void ENC28J60_PacketReceived(void)
{
    BYTE nextPacketPtH, nextPacketPtL;
    BYTE i = 0;
    WORD curAddress;
    WORD nextAddress;

    //Packet received
    UART_WriteByte(0xAA);
    UART_WriteByte(ENC28J60_ReadControlRegByte(EPKTCNT));

    delayBetweenSPIBytes2();

    UART_WriteByte(0xBB);
    delayBetweenSPIBytes2();
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERXRDPTH));
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERXRDPTL));

    delayBetweenSPIBytes2();

    UART_WriteByte(0xCC);
    delayBetweenSPIBytes2();
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERXWRPTH));
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERXWRPTL));

    delayBetweenSPIBytes2();

    UART_WriteByte(0xDD);
    delayBetweenSPIBytes2();
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERDPTH));
    UART_WriteByte(ENC28J60_ReadControlRegByte(ERDPTL));

    delayBetweenSPIBytes2();

    //i = (BYTE) ((((WORD) (((WORD)ERXWRPTH) << 8)) | ((WORD) ERXWRPTL)) - (((WORD) (((WORD)ERDPTH) << 8)) | ((WORD) ERDPTL)));
    curAddress = (((WORD) (((WORD)ERDPTH) << 8)) | ((WORD) ERDPTL));
    nextAddress = (((WORD) (((WORD)ERXWRPTH) << 8)) | ((WORD) ERXWRPTL));
    i = (nextAddress - curAddress);

    delayBetweenSPIBytes2();
    UART_WriteByte(0xCD);
    UART_WriteByte(i);
    delayBetweenSPIBytes2();



    nextPacketPtL = ENC28J60_ReadBufferMem();
    nextPacketPtH = ENC28J60_ReadBufferMem();

    delayBetweenSPIBytes2();

    UART_WriteByte(0xAB);
    delayBetweenSPIBytes2();
    UART_WriteByte(nextPacketPtH);
    UART_WriteByte(nextPacketPtL);

    delayBetweenSPIBytes2();

    UART_WriteByte(0xEE);
    for(; i > 0; i--)
    {
        UART_WriteByte(ENC28J60_ReadBufferMem());
        delayBetweenSPIBytes2();
    }
    UART_WriteByte(0xEF);

    delayBetweenSPIBytes2();


    //Read packet

    delayBetweenSPIBytes2();
    
    ENC28J60_BitFieldSet(ECON2, 0x40);
    UART_WriteByte(0xAC);
    UART_WriteByte(ENC28J60_ReadControlRegByte(EPKTCNT));
}


void ENC28J60_PacketReceived2(void)
{
    BYTE nextPacketPtH, nextPacketPtL;

    //Packet received
    nextPacketPtH = ENC28J60_ReadControlRegByte(ECON2);
    delayBetweenSPIBytes2();
    UART_WriteByte(nextPacketPtH);
}

