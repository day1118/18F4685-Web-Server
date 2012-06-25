//==========================================================================
//
//   IMPORTANT: For the PIC18 devices, the __CONFIG directive has been
//              superseded by the CONFIG directive.  The following settings
//              are available for this device.
//
//   Oscillator Selection bits:
//     #pragma config OSC = LP             //LP oscillator
//     #pragma config OSC = XT             //XT oscillator
     #pragma config OSC = HS             //HS oscillator//     #pragma config      OSC = RC             //External RC oscillator, CLKO function on RA6
//     #pragma config OSC = EC             //EC oscillator, CLKO function on RA6
//     #pragma config OSC = ECIO           //EC oscillator, port function on RA6
//     #pragma config OSC = HSPLL          //HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1)
//     #pragma config OSC = RCIO           //External RC oscillator, port function on RA6
//     #pragma config OSC = IRCIO67        //Internal oscillator block, port function on RA6 and RA7
//     #pragma config OSC = IRCIO7         //Internal oscillator block, CLKO function on RA6, port function on RA7
//
//   Fail-Safe Clock Monitor Enable bit:
     #pragma config FCMEN = OFF          //Fail-Safe Clock Monitor disabled
//     #pragma config FCMEN = ON           //Fail-Safe Clock Monitor enabled
//
//   Internal/External Oscillator Switchover bit:
     #pragma config IESO = OFF           //Oscillator Switchover mode disabled
//     #pragma config IESO = ON            //Oscillator Switchover mode enabled
//
//   Power-up Timer Enable bit:
//     #pragma config PWRT = ON            //PWRT enabled
     #pragma config PWRT = OFF           //PWRT disabled
//
//   Brown-out Reset Enable bits:
     #pragma config BOREN = OFF          //Brown-out Reset disabled in hardware and software
//     #pragma config BOREN = SBORENCTRL   //Brown-out Reset enabled and controlled by software (SBOREN is enabled)
//     #pragma config BOREN = BOACTIVE     //Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
//     #pragma config BOREN = BOHW         //Brown-out Reset enabled in hardware only (SBOREN is disabled)
//
//   Brown-out Reset Voltage bits:
//     #pragma config BORV = 0             //Maximum setting
//     #pragma config BORV = 1
//     #pragma config BORV = 2
//     #pragma config BORV = 3             //Minimum setting
//
//   Watchdog Timer Enable bit:
     #pragma config WDT = OFF            //WDT disabled (control is placed on the SWDTEN bit)
//     #pragma config WDT = ON             //WDT enabled
//
//   Watchdog Timer Postscale Select bits:
//     #pragma config WDTPS = 1            //1:1
//     #pragma config WDTPS = 2            //1:2
//     #pragma config WDTPS = 4            //1:4
//     #pragma config WDTPS = 8            //1:8
//     #pragma config WDTPS = 16           //1:16
//     #pragma config WDTPS = 32           //1:32
//     #pragma config WDTPS = 64           //1:64
//     #pragma config WDTPS = 128          //1:128
//     #pragma config WDTPS = 256          //1:256
//     #pragma config WDTPS = 512          //1:512
//     #pragma config WDTPS = 1024         //1:1024
//     #pragma config WDTPS = 2048         //1:2048
//     #pragma config WDTPS = 4096         //1:4096
//     #pragma config WDTPS = 8192         //1:8192
//     #pragma config WDTPS = 16384        //1:16384
//     #pragma config WDTPS = 32768        //1:32768
//
//   MCLR Pin Enable bit:
     #pragma config MCLRE = OFF          //RE3 input pin enabled// MCLR disabled
//     #pragma config MCLRE = ON           //MCLR pin enabled// RE3 input pin disabled
//
//   Low Power Timer1 Oscillator Enable bit:
     #pragma config LPT1OSC = OFF        //Timer1 configured for higher power operation
//     #pragma config LPT1OSC = ON         //Timer1 configured for low-power operation
//
//   PORTB Pins Configured for A/D:
     #pragma config PBADEN = OFF         //PORTB<4> and PORTB<1:0> Configured as Digital I/O Pins on Reset
//     #pragma config PBADEN = ON          //PORTB<4> and PORTB<1:0> Configured as Analog Pins on Reset
//
//   BackGround Debugger Enable bit:
//     #pragma config DEBUG = ON           //Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
     #pragma config DEBUG = OFF          //Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
//
//   Extended Instruction Set Enable bit:
//     #pragma config XINST = OFF          //Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
     #pragma config XINST = ON           //Instruction set extension and Indexed Addressing mode enabled
//
//   Boot Block Size Select Bits:
//     #pragma config BBSIZ = 1024         //1K words (2K bytes) Boot Block
//     #pragma config BBSIZ = 2048         //2K words (4K bytes) Boot Block
//     #pragma config BBSIZ = 4096         //4K words (8K bytes) Boot Block
//
//   Low Voltage Programming:
//     #pragma config LVP = OFF            //Disabled
//     #pragma config LVP = ON             //Enabled
//
//   Stack Full/Underflow Reset Enable bit:
     #pragma config STVREN = OFF         //Stack full/underflow will not cause Reset
//     #pragma config STVREN = ON          //Stack full/underflow will cause Reset
//
//   Code Protection Block 0:
//     #pragma config CP0 = ON             //Block 0 (000800-003FFFh) code-protected
     #pragma config CP0 = OFF            //Block 0 (000800-003FFFh) not code-protected
//
//   Code Protection Block 1:
//     #pragma config CP1 = ON             //Block 1 (004000-007FFFh) code-protected
     #pragma config CP1 = OFF            //Block 1 (004000-007FFFh) not code-protected
//
//   Code Protection Block 2:
//     #pragma config CP2 = ON             //Block 2 (008000-00BFFFh) code-protected
     #pragma config CP2 = OFF            //Block 2 (008000-00BFFFh) not code-protected
//
//   Code Protection Block 3:
//     #pragma config CP3 = ON             //Block 3 (00C000-00FFFFh) code-protected
     #pragma config CP3 = OFF            //Block 3 (00C000-00FFFFh) not code-protected
//
//   Code Protection Block 4:
//     #pragma config CP4 = ON             //Block 4 (010000-013FFFh) code-protected
     #pragma config CP4 = OFF            //Block 4 (010000-013FFFh) not code-protected
//
//   Code Protection Block 5:
//     #pragma config CP5 = ON             //Block 5 (014000-017FFFh) code-protected
     #pragma config CP5 = OFF            //Block 5 (014000-017FFFh) not code-protected
//
//   Boot Block Code Protection:
//     #pragma config CPB = ON             //Boot Block (000000-0007FFh) code-protected
     #pragma config CPB = OFF            //Boot Block (000000-0007FFh) not code-protected
//
//   Data EEPROM Code Protection:
//     #pragma config CPD = ON             //Data EEPROM code-protected
     #pragma config CPD = OFF            //Data EEPROM not code-protected
//
//   Write Protection Block 0:
//     #pragma config WRT0 = ON            //Block 0 (000800-003FFFh) write-protected
     #pragma config WRT0 = OFF           //Block 0 (000800-003FFFh) not write-protected
//
//   Write Protection Block 1:
//     #pragma config WRT1 = ON            //Block 1 (004000-007FFFh) write-protected
     #pragma config WRT1 = OFF           //Block 1 (004000-007FFFh) not write-protected
//
//   Write Protection Block 2:
//     #pragma config WRT2 = ON            //Block 2 (008000-00BFFFh) write-protected
     #pragma config WRT2 = OFF           //Block 2 (008000-00BFFFh) not write-protected
//
//   Write Protection Block 3:
//     #pragma config WRT3 = ON            //Block 3 (00C000-00FFFFh) write-protected
     #pragma config WRT3 = OFF           //Block 3 (00C000-00FFFFh) not write-protected
//
//   Write Protection Block 4:
//     #pragma config WRT4 = ON            //Block 4 (010000-013FFFh) write-protected
     #pragma config WRT4 = OFF           //Block 4 (010000-013FFFh) not write-protected
//
//   Write Protection Block 5:
//     #pragma config WRT5 = ON            //Block 5 (014000-017FFFh) write-protected
     #pragma config WRT5 = OFF           //Block 5 (014000-017FFFh) not write-protected
//
//   Boot Block Write Protection:
//     #pragma config WRTB = ON            //Boot Block (000000-0007FFh) write-protected
     #pragma config WRTB = OFF           //Boot Block (000000-0007FFh) not write-protected
//
//   Configuration Register Write Protection:
//     #pragma config WRTC = ON            //Configuration registers (300000-3000FFh) write-protected
     #pragma config WRTC = OFF           //Configuration registers (300000-3000FFh) not write-protected
//
//   Data EEPROM Write Protection:
//     #pragma config WRTD = ON            //Data EEPROM write-protected
     #pragma config WRTD = OFF           //Data EEPROM not write-protected
//
//   Table Read Protection Block 0:
//     #pragma config EBTR0 = ON           //Block 0 (000800-003FFFh) protected from table reads executed in other blocks
     #pragma config EBTR0 = OFF          //Block 0 (000800-003FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 1:
//     #pragma config EBTR1 = ON           //Block 1 (004000-007FFFh) protected from table reads executed in other blocks
     #pragma config EBTR1 = OFF          //Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 2:
//     #pragma config EBTR2 = ON           //Block 2 (008000-00BFFFh) protected from table reads executed in other blocks
     #pragma config EBTR2 = OFF          //Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 3:
//     #pragma config EBTR3 = ON           //Block 3 (00C000-00FFFFh) protected from table reads executed in other blocks
     #pragma config EBTR3 = OFF          //Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 4:
//     #pragma config EBTR4 = ON           //Block 4 (010000-013FFFh) protected from table reads executed in other blocks
     #pragma config EBTR4 = OFF          //Block 4 (010000-013FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 5:
//     #pragma config EBTR5 = ON           //Block 5 (014000-017FFFh) protected from table reads executed in other blocks
     #pragma config EBTR5 = OFF          //Block 5 (014000-017FFFh) not protected from table reads executed in other blocks
//
//   Boot Block Table Read Protection:
//     #pragma config EBTRB = ON           //Boot Block (000000-0007FFh) protected from table reads executed in other blocks
     #pragma config EBTRB = OFF          //Boot Block (000000-0007FFh) not protected from table reads executed in other blocks
//
//==========================================================================