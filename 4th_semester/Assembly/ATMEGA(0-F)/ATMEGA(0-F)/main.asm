// +----------------------------------------------------------------------------+
// | Author.......: Vanessa Reteguín <vanessa@reteguin.com>
// | Author.......: 
// | First release: May 19th, 2025
// | Last update..: May 23rd, 2025
// | WhatIs.......: 7 Segments Display Cycle: 0 to F - Main
// +----------------------------------------------------------------------------+

// ------------ Objective -------------
// Escribir un programa que despliegue en un Display de 7 segmentos el conteo de O a F de forma cíclica (Se sugiere que sea con Lógica Inversa)


// ------------ Resources / Documentation involved -------------
// Bit Shifting with Delays Teacher's Tutorial: https: //www.youtube.com/watch?v=apbuP5SLwVA

// AVR Delay Loop Calculator: http:// darcy.rsgc.on.ca/ACES/TEI4M/AVRdelay.html
; Assembly code auto-generated
; by utility from Bret Mulvey
; Delay 8 000 000 cycles
; 1s at 8 MHz

/*
		ldi  r25, 82
		ldi  r26, 43
		ldi  r27, 0
L1:		dec  r27
		brne L1
		dec  r26
		brne L1
		dec  r25
		brne L1
		lpm
		nop
*/

.INCLUDE <M8515DEF.inc>

// Declaramos el puerto A como salida

			LDI		R16,0XFF	// Llenamos el registro 16 con puros 1s
			OUT		DDRA,R16	// Configuramos el puerto A como salida

	RETARDO:
			LDI R25, 41
			LDI R26, 150
			LDI R27, 128


	AAA:
		LDI R17, 0b10000000
		LDI R18, 0b01000000
		LDI R19, 0b00100000
		LDI R20, 0b00010000
		LDI R21, 0b00001000
		LDI R22, 0b00000100
		LDI R23, 0b00000010
		LDI R24, 0b00000001
	