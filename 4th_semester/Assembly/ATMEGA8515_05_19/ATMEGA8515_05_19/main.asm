;
; ATMEGA8515_05_19.asm
; Autor: Isai Nuñez
;

.include "m8515def.inc"

; Configurar Puerto A como salida
LDI R16, 0xFF
OUT DDRA, R16

; Cargar valores para secuencia en registros
LDI R17, 0b10000000
LDI R18, 0b01000000
LDI R19, 0b00100000
LDI R20, 0b00010000
LDI R21, 0b00001000
LDI R22, 0b00000100
LDI R23, 0b00000010
LDI R24, 0b00000001

CICLOTE:
	OUT PORTA, R17
	RCALL RETARDO

	OUT PORTA, R18
	RCALL RETARDO

	OUT PORTA, R19
	RCALL RETARDO

	OUT PORTA, R20
	RCALL RETARDO

	OUT PORTA, R21
	RCALL RETARDO

	OUT PORTA, R22
	RCALL RETARDO

	OUT PORTA, R23
	RCALL RETARDO

	OUT PORTA, R24
	RCALL RETARDO

	OUT PORTA, R23
	RCALL RETARDO

	OUT PORTA, R22
	RCALL RETARDO

	OUT PORTA, R21
	RCALL RETARDO

	OUT PORTA, R20
	RCALL RETARDO

	OUT PORTA, R19
	RCALL RETARDO

	OUT PORTA, R18
	RCALL RETARDO

	RJMP CICLOTE

; Subrutina de retardo
RETARDO:
	LDI R25, 41
	LDI R26, 150
	LDI R27, 128
L_RETRASO:
	DEC R27
	BRNE L_RETRASO
	DEC R26
	BRNE L_RETRASO
	DEC R25
	BRNE L_RETRASO
	RET
