#include "UART_Helper.h"

void UART_WriteByte(BYTE data)
{
    TXREG = data;
    while(TXSTAbits.TRMT);
}