; ==== Register address information ====
; SYSTEM Register
.SET SPH = 0x3E ; Stack Pointer High
.SET SPL = 0x3D ; Stack Pointer Low
.SET SREG = 0x3F ; Status Register
.SET MCUCR = 0x35 ; MCU Control Register
.SET RAMEND = 0x0FFF ; End of RAM

; PORT Registers
.SET DDRA = 0x1A ; Port A Data Direction Register
.SET PORTA = 0x1B ; Port A Data Register

; USART Registers
.SET UDR0 = 0x0C ; USART0 Data Register
.SET UCSR0A = 0x0B ; USART0 Control and Status Register A
.SET UCSR0B = 0x0A ; USART0 Control and Status Register B
.SET UCSR0C = 0x95 ; (MEM) USART0 Control and Status Register C
.SET UBRR0H = 0x90; (MEM) USART0 Baud Rate Registers High
.SET UBRR0L = 0x09 ; USART0 Baud Rate Registers Low

; ==== Code starts here ====
.CSEG
; Interrupt vector table
INTVECTOR:
jmp RESET ; int 1, the reset interrupt
jmp NOINT ; int 2
jmp NOINT ; int 3
jmp NOINT ; int 4
jmp NOINT ; int 5
jmp NOINT ; int 6
jmp NOINT ; int 7
jmp NOINT ; int 8
jmp NOINT ; int 9
jmp NOINT ; int 10
jmp NOINT ; int 11
jmp NOINT ; int 12
jmp NOINT ; int 13
jmp NOINT ; int 14
jmp NOINT ; int 15
jmp NOINT ; int 16
jmp NOINT ; int 17
jmp NOINT ; int 18
jmp NOINT ; int 19
jmp NOINT ; int 20
jmp USART0Tx ; int 21, the USART Tx complete interrupt
jmp NOINT ; int 22
jmp NOINT ; int 23
jmp NOINT ; int 24
jmp NOINT ; int 25
jmp NOINT ; int 26
jmp NOINT ; int 27
jmp NOINT ; int 28
jmp NOINT ; int 29
jmp NOINT ; int 30
jmp NOINT ; int 31
jmp NOINT ; int 32
jmp NOINT ; int 33
jmp NOINT ; int 34
jmp NOINT ; int 35

; not a valid interrupt
NOINT:
reti

; restart from here
RESET:

; clear status and disable interrupt
eor	r1, r1
out	SREG, r1
; enable sleep mode
ldi r16, 0x20
out MCUCR, r16
; ==== Intialization starts here ==>>
; initialize the stack pointer


; make port A output


; initilize USART0


; <<== Intialization ends here ====

; start the main program
MAIN:
; enable interrupt
sei

; ==== Application starts here ==>>


; <<== Application ends here ====

; the USART Tx complete interrupt
USART0Tx:
; ==== Interrupt starts here ==>>


reti
; <<== Interrupt ends here ====



