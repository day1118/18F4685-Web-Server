#include "ENC28J60_ARP.h"

void ENC28J60_SendARPRequest(void)
{
    //Send packet.
    ENC28J60_WriteBufferMem(0x0F); // Control byte
    //Data
     // Dest mac address
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 1
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 2
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 3
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 4
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 5
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 6
     // Source mac address
    ENC28J60_WriteBufferMem(0x00); // MAC Source Byte 1
    ENC28J60_WriteBufferMem(0x04); // MAC Source Byte 2
    ENC28J60_WriteBufferMem(0xA3); // MAC Source Byte 3
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 4
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 5
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 6
     // Type
    ENC28J60_WriteBufferMem(0x08); // ARP
    ENC28J60_WriteBufferMem(0x06); // ARP

    ENC28J60_WriteBufferMem(0x00); // Hardware Type
    ENC28J60_WriteBufferMem(0x01);

    ENC28J60_WriteBufferMem(0x08); // Protocol Type
    ENC28J60_WriteBufferMem(0x00);

    ENC28J60_WriteBufferMem(0x06);  // Length of MAC addresses
    ENC28J60_WriteBufferMem(0x04);  // Protocol length

    ENC28J60_WriteBufferMem(0x00); // Operation - 1 for request
    ENC28J60_WriteBufferMem(0x01); //           - 2 for reply

    // Source mac address
    ENC28J60_WriteBufferMem(0x00); // MAC Source Byte 1
    ENC28J60_WriteBufferMem(0x04); // MAC Source Byte 2
    ENC28J60_WriteBufferMem(0xA3); // MAC Source Byte 3
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 4
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 5
    ENC28J60_WriteBufferMem(0x55); // MAC Source Byte 6

    ENC28J60_WriteBufferMem(0xC0); // Source IP 1
    ENC28J60_WriteBufferMem(0xA8); // Source IP 2
    ENC28J60_WriteBufferMem(0x02); // Source IP 3
    ENC28J60_WriteBufferMem(0x63); // Source IP 4

    // Dest mac address
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 1
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 2
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 3
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 4
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 5
    ENC28J60_WriteBufferMem(0xFF); // MAC Dest Byte 6

    ENC28J60_WriteBufferMem(0xC0); // Dest IP 1
    ENC28J60_WriteBufferMem(0xA8); // Dest IP 2
    ENC28J60_WriteBufferMem(0x02); // Dest IP 3
    ENC28J60_WriteBufferMem(0x17); // Dest IP 4

    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding
    ENC28J60_WriteBufferMem(0x00); // Padding

     /*PORTCbits.RC2 = 0;      // Start communication
     writeByteToSPIWithDelay(ENC_WRITE_BUFFER_MEM);   // Write to Buffer memory
     writeByteToSPIWithDelay(0x0F); // Control byte
    //Data
     // Dest mac address
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 1
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 2
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 3
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 4
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 5
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 6
     // Source mac address
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 1
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 2
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 3
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 4
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 5
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 6
     // Type
    writeByteToSPIWithDelay(0x80); // ARP
    writeByteToSPIWithDelay(0x06); // ARP

    writeByteToSPIWithDelay(0x00); // Hardware Type
    writeByteToSPIWithDelay(0x02);

    writeByteToSPIWithDelay(0x18); // Protocol Type
    writeByteToSPIWithDelay(0x10);

    writeByteToSPIWithDelay(0x06);  // Length of MAC addresses
    writeByteToSPIWithDelay(0x04);  // Protocol length

    writeByteToSPIWithDelay(0x00); // Operation - 1 for request
    writeByteToSPIWithDelay(0x01); //           - 2 for reply

    // Source mac address
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 1
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 2
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 3
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 4
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 5
    writeByteToSPIWithDelay(0x55); // MAC Source Byte 6

    writeByteToSPIWithDelay(0xC0); // Source IP 1
    writeByteToSPIWithDelay(0xA8); // Source IP 2
    writeByteToSPIWithDelay(0x02); // Source IP 3
    writeByteToSPIWithDelay(0x63); // Source IP 4

    // Dest mac address
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 1
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 2
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 3
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 4
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 5
    writeByteToSPIWithDelay(0xFF); // MAC Dest Byte 6

    writeByteToSPIWithDelay(0xC0); // Dest IP 1
    writeByteToSPIWithDelay(0xA8); // Dest IP 2
    writeByteToSPIWithDelay(0x02); // Dest IP 3
    writeByteToSPIWithDelay(0x17); // Dest IP 4

    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding
    writeByteToSPIWithDelay(0x00); // Padding

    PORTCbits.RC2 = 1;      // End communication*/

    delayBetweenSPIBytes2();

    PORTCbits.RC2 = 1;      // Start communication

    ENC28J60_BitFieldSet(ECON1, 0x08);
    delayBetweenSPIBytes2();

    PORTCbits.RC2 = 1;      // End communication
}

////