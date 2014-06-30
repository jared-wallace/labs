; SYSTEM
.SET SPH = 0x3E ; Stack Pointer High
.SET SPL = 0x3D ; Stack Pointer Low
.SET SREG = 0x3F ; Status Register
.SET MCUCR = 0x35 ; MCU Control Register
.SET RAMEND = 0x0FFF ; End of RAM

; PORT
.SET DDRA = 0x1A ; Port A Data Direction Register
.SET PORTA = 0x1B ; Port A Data Register

; USART
.SET UDR0 = 0x0C ; USART0 Data Register
.SET UCSR0A = 0x0B ; USART0 Control and Status Register A
.SET UCSR0B = 0x0A ; USART0 Control and Status Register B
.SET UCSR0C = 0x95 ; (MEM) USART0 Control and Status Register C
.SET UBRR0H = 0x90; (MEM) USART0 Baud Rate Registers High
.SET UBRR0L = 0x09 ; USART0 Baud Rate Registers Low

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

;initialize SP
ldi r17, high(RAMEND)
out SPH, r17
ldi r16, low(RAMEND)
out SPL, r16

; enable sleep mode
ldi r16, 0x20
out MCUCR, r16

; make port A output
sbi DDRA, 0 ;
sbi DDRA, 1 ;
sbi DDRA, 2 ;

; init USART0
sbi UCSR0A, 1 ; U2X=1
sbi UCSR0B, 3 ; enable TX
ldi r16, 0x10 ; set rate to 57.6Kbps, the processor's clock is 8MHz
out UBRR0L, r16
ldi r16, 0x00
sts UBRR0H, r16

; enable interrupt
sei

; start the main program
MAIN:
sts 0x200, r1;
lds r16, 0x400
inc r16
sts 0x400, r16
rcall LIGHT ; LED
rcall USART0_OUTPUT ; output
LOOP:
sleep
rjmp LOOP

LIGHT:
mov r17, r16
andi r17, 0x03

LIGHT0:
cpi	r17, 0x0
brne LIGHT1
cbi	PORTA, 0	; yellow
sbi	PORTA, 1	; green
sbi	PORTA, 2	; red
ret

LIGHT1:
cpi r17, 0x1
brne LIGHT2
sbi	PORTA, 0	; yellow
cbi	PORTA, 1	; green
sbi	PORTA, 2	; red
ret

LIGHT2:
cpi r17, 0x2
brne LIGHT3
sbi	PORTA, 0	; yellow
sbi	PORTA, 1	; green
cbi	PORTA, 2	; red
ret

LIGHT3:
cpi r17, 0x3
brne LIGHTERR
cbi	PORTA, 0	; yellow
sbi	PORTA, 1	; green
cbi	PORTA, 2	; red
ret

LIGHTERR:
cbi	PORTA, 0	; yellow
cbi	PORTA, 1	; green
cbi	PORTA, 2	; red
ret

USART0_OUTPUT:
sbi UCSR0B, 6 ; enable TX complete interrupt
out UDR0, r16 ; Serial output
ret

USART0Tx:
cbi UCSR0B, 6 ; disable TX complete interrupt
ldi r16, 0xF0
out UDR0, r16
reti
