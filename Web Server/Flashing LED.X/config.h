//==========================================================================
//
//   IMPORTANT: For the PIC18 devices, the __CONFIG directive has been
//              superseded by the CONFIG directive.  The following settings
//              are available for this device.
//
//   Oscillator Selection bits:
//     OSC = LP             //LP oscillator
//     OSC = XT             //XT oscillator
//     #pragma config OSC = HS             //HS oscillator
//     OSC = RC             //External RC oscillator, CLKO function on RA6
//     OSC = EC             //EC oscillator, CLKO function on RA6
//     OSC = ECIO           //EC oscillator, port function on RA6
//     OSC = HSPLL          //HS oscillator, PLL enabled (Clock Frequency = 4 x FOSC1)
//     OSC = RCIO           //External RC oscillator, port function on RA6
//     OSC = IRCIO67        //Internal oscillator block, port function on RA6 and RA7
//     OSC = IRCIO7         //Internal oscillator block, CLKO function on RA6, port function on RA7
//
//   Fail-Safe Clock Monitor Enable bit:
//     FCMEN = OFF          //Fail-Safe Clock Monitor disabled
//     FCMEN = ON           //Fail-Safe Clock Monitor enabled
//
//   Internal/External Oscillator Switchover bit:
//     IESO = OFF           //Oscillator Switchover mode disabled
//     IESO = ON            //Oscillator Switchover mode enabled
//
//   Power-up Timer Enable bit:
//     PWRT = ON            //PWRT enabled
//     PWRT = OFF           //PWRT disabled
//
//   Brown-out Reset Enable bits:
//     BOREN = OFF          //Brown-out Reset disabled in hardware and software
//     BOREN = SBORENCTRL   //Brown-out Reset enabled and controlled by software (SBOREN is enabled)
//     BOREN = BOACTIVE     //Brown-out Reset enabled in hardware only and disabled in Sleep mode (SBOREN is disabled)
//     BOREN = BOHW         //Brown-out Reset enabled in hardware only (SBOREN is disabled)
//
//   Brown-out Reset Voltage bits:
//     BORV = 0             //Maximum setting
//     BORV = 1
//     BORV = 2
//     BORV = 3             //Minimum setting
//
//   Watchdog Timer Enable bit:
//     WDT = OFF            //WDT disabled (control is placed on the SWDTEN bit)
//     WDT = ON             //WDT enabled
//
//   Watchdog Timer Postscale Select bits:
//     WDTPS = 1            //1:1
//     WDTPS = 2            //1:2
//     WDTPS = 4            //1:4
//     WDTPS = 8            //1:8
//     WDTPS = 16           //1:16
//     WDTPS = 32           //1:32
//     WDTPS = 64           //1:64
//     WDTPS = 128          //1:128
//     WDTPS = 256          //1:256
//     WDTPS = 512          //1:512
//     WDTPS = 1024         //1:1024
//     WDTPS = 2048         //1:2048
//     WDTPS = 4096         //1:4096
//     WDTPS = 8192         //1:8192
//     WDTPS = 16384        //1:16384
//     WDTPS = 32768        //1:32768
//
//   MCLR Pin Enable bit:
//     MCLRE = OFF          //RE3 input pin enabled// MCLR disabled
//     MCLRE = ON           //MCLR pin enabled// RE3 input pin disabled
//
//   Low Power Timer1 Oscillator Enable bit:
//     LPT1OSC = OFF        //Timer1 configured for higher power operation
//     LPT1OSC = ON         //Timer1 configured for low-power operation
//
//   PORTB Pins Configured for A/D:
//     PBADEN = OFF         //PORTB<4> and PORTB<1:0> Configured as Digital I/O Pins on Reset
//     PBADEN = ON          //PORTB<4> and PORTB<1:0> Configured as Analog Pins on Reset
//
//   BackGround Debugger Enable bit:
//     DEBUG = ON           //Background debugger enabled, RB6 and RB7 are dedicated to In-Circuit Debug
//     DEBUG = OFF          //Background debugger disabled, RB6 and RB7 configured as general purpose I/O pins
//
//   Extended Instruction Set Enable bit:
//     XINST = OFF          //Instruction set extension and Indexed Addressing mode disabled (Legacy mode)
//     XINST = ON           //Instruction set extension and Indexed Addressing mode enabled
//
//   Boot Block Size Select Bits:
//     BBSIZ = 1024         //1K words (2K bytes) Boot Block
//     BBSIZ = 2048         //2K words (4K bytes) Boot Block
//     BBSIZ = 4096         //4K words (8K bytes) Boot Block
//
//   Low Voltage Programming:
//     LVP = OFF            //Disabled
//     LVP = ON             //Enabled
//
//   Stack Full/Underflow Reset Enable bit:
//     STVREN = OFF         //Stack full/underflow will not cause Reset
//     STVREN = ON          //Stack full/underflow will cause Reset
//
//   Code Protection Block 0:
//     CP0 = ON             //Block 0 (000800-003FFFh) code-protected
//     CP0 = OFF            //Block 0 (000800-003FFFh) not code-protected
//
//   Code Protection Block 1:
//     CP1 = ON             //Block 1 (004000-007FFFh) code-protected
//     CP1 = OFF            //Block 1 (004000-007FFFh) not code-protected
//
//   Code Protection Block 2:
//     CP2 = ON             //Block 2 (008000-00BFFFh) code-protected
//     CP2 = OFF            //Block 2 (008000-00BFFFh) not code-protected
//
//   Code Protection Block 3:
//     CP3 = ON             //Block 3 (00C000-00FFFFh) code-protected
//     CP3 = OFF            //Block 3 (00C000-00FFFFh) not code-protected
//
//   Code Protection Block 4:
//     CP4 = ON             //Block 4 (010000-013FFFh) code-protected
//     CP4 = OFF            //Block 4 (010000-013FFFh) not code-protected
//
//   Code Protection Block 5:
//     CP5 = ON             //Block 5 (014000-017FFFh) code-protected
//     CP5 = OFF            //Block 5 (014000-017FFFh) not code-protected
//
//   Boot Block Code Protection:
//     CPB = ON             //Boot Block (000000-0007FFh) code-protected
//     CPB = OFF            //Boot Block (000000-0007FFh) not code-protected
//
//   Data EEPROM Code Protection:
//     CPD = ON             //Data EEPROM code-protected
//     CPD = OFF            //Data EEPROM not code-protected
//
//   Write Protection Block 0:
//     WRT0 = ON            //Block 0 (000800-003FFFh) write-protected
//     WRT0 = OFF           //Block 0 (000800-003FFFh) not write-protected
//
//   Write Protection Block 1:
//     WRT1 = ON            //Block 1 (004000-007FFFh) write-protected
//     WRT1 = OFF           //Block 1 (004000-007FFFh) not write-protected
//
//   Write Protection Block 2:
//     WRT2 = ON            //Block 2 (008000-00BFFFh) write-protected
//     WRT2 = OFF           //Block 2 (008000-00BFFFh) not write-protected
//
//   Write Protection Block 3:
//     WRT3 = ON            //Block 3 (00C000-00FFFFh) write-protected
//     WRT3 = OFF           //Block 3 (00C000-00FFFFh) not write-protected
//
//   Write Protection Block 4:
//     WRT4 = ON            //Block 4 (010000-013FFFh) write-protected
//     WRT4 = OFF           //Block 4 (010000-013FFFh) not write-protected
//
//   Write Protection Block 5:
//     WRT5 = ON            //Block 5 (014000-017FFFh) write-protected
//     WRT5 = OFF           //Block 5 (014000-017FFFh) not write-protected
//
//   Boot Block Write Protection:
//     WRTB = ON            //Boot Block (000000-0007FFh) write-protected
//     WRTB = OFF           //Boot Block (000000-0007FFh) not write-protected
//
//   Configuration Register Write Protection:
//     WRTC = ON            //Configuration registers (300000-3000FFh) write-protected
//     WRTC = OFF           //Configuration registers (300000-3000FFh) not write-protected
//
//   Data EEPROM Write Protection:
//     WRTD = ON            //Data EEPROM write-protected
//     WRTD = OFF           //Data EEPROM not write-protected
//
//   Table Read Protection Block 0:
//     EBTR0 = ON           //Block 0 (000800-003FFFh) protected from table reads executed in other blocks
//     EBTR0 = OFF          //Block 0 (000800-003FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 1:
//     EBTR1 = ON           //Block 1 (004000-007FFFh) protected from table reads executed in other blocks
//     EBTR1 = OFF          //Block 1 (004000-007FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 2:
//     EBTR2 = ON           //Block 2 (008000-00BFFFh) protected from table reads executed in other blocks
//     EBTR2 = OFF          //Block 2 (008000-00BFFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 3:
//     EBTR3 = ON           //Block 3 (00C000-00FFFFh) protected from table reads executed in other blocks
//     EBTR3 = OFF          //Block 3 (00C000-00FFFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 4:
//     EBTR4 = ON           //Block 4 (010000-013FFFh) protected from table reads executed in other blocks
//     EBTR4 = OFF          //Block 4 (010000-013FFFh) not protected from table reads executed in other blocks
//
//   Table Read Protection Block 5:
//     EBTR5 = ON           //Block 5 (014000-017FFFh) protected from table reads executed in other blocks
//     EBTR5 = OFF          //Block 5 (014000-017FFFh) not protected from table reads executed in other blocks
//
//   Boot Block Table Read Protection:
//     EBTRB = ON           //Boot Block (000000-0007FFh) protected from table reads executed in other blocks
//     EBTRB = OFF          //Boot Block (000000-0007FFh) not protected from table reads executed in other blocks
//
//==========================================================================