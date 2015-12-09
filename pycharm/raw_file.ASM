
;***********************************************************************************************************************
; Instrucciones inmediatas
;***********************************************************************************************************************

;=============================================================
;#1  Prueba de instruccion LDA inmediata.
;=============================================================
* = @0000 ; Declaracion del puntero de posicion.
BIN LDA #%000001 ; LDA con argumento binario.
OCT LDA #@02 ; LDA con argumento octal.
HEX LDA #$03 ; LDA con argumento hexadecimal.
DEC LDA #4 ; LDA con argumento decimal.
HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#2 Prueba de instruccion ADD inmediata.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;BIN ADD #%000010 ; ADD con argumento binario.
;OCT ADD #@02 ; ADD con argumento octacl.
;DEC ADD #2 ; ADD con argumento decimal.
;HEX ADD #$02 ; ADD con argumento hexadecimal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#3 Prueba de instruccion SUB inmediata.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #10 ; LDA con argumento decimal.
;BIN SUB #%000010 ; SUB con argumento binario.
;OCT SUB #@02 ; SUB con argumento octacl.
;DEC SUB #2 ; SUB con argumento decimal.
;HEX SUB #$02 ; SUB con argumento hexadecimal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#4 Prueba de instruccion AND inmediata.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111111 ; LDA con argumento decimal.
;BIN AND #%000111 ; AND con argumento binario.
;OCT AND #@07 ; AND con argumento octacl.
;DEC AND #3 ; AND con argumento decimal.
;HEX AND #$01 ; AND con argumento hexadecimal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#5 Prueba de instruccion ORA inmediata.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%101000 ; LDA con argumento decimal.
;BIN ORA #%000101 ; ORA con argumento binario.
;OCT ORA #@20 ; ORA con argumento octacl.
;DEC ORA #2 ; ORA con argumento decimal.
;HEX ORA #$00 ; ORA con argumento hexadecimal.
;HLT ; Instruccion de detencion.
;=============================================================

;***********************************************************************************************************************


;***********************************************************************************************************************
; Instrucciones absolutas
;***********************************************************************************************************************

;=============================================================
;#6 Prueba de instruccion LDA absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA @01 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#7 Prueba de instruccion STA absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #7 ; LDA inmediato.
;L2 STA @0020 ; STA absoluto.
;L3 ADD #1 ; LDA inmediato.
;L4 LDA @0020 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#8 Prueba de instruccion ADD absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA inmediato con argumento decimal.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #2 ; LDA inmediato con argumento decimal.
;L4 ADD @0020 ; ADD absoluta.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#9 Prueba de instruccion SUB absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA inmediato con argumento decimal.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #2 ; LDA inmediato con argumento decimal.
;L4 SUB @0020 ; SUB absoluta.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#10 Prueba de instruccion AND absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111111 ; LDA inmediato con argumento binario.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #%000111 ; LDA inmediato con argumento binario.
;L4 AND @0020 ; AND absolutal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#12 Prueba de instruccion ORA absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111000 ; LDA inmediato con argumento binario.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #%000111 ; LDA inmediato con argumento binario.
;L4 ORA @0020 ; ORA absoluta.
;HLT ; Instruccion de detencion.
;=============================================================

;***********************************************************************************************************************

;***********************************************************************************************************************
;#13 Instrucciones indirectas
;***********************************************************************************************************************
;=============================================================
; Prueba de instruccion LDA indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #7 ; LDA inmediato con argumento decimal.
;L6 STA @2211 ; STA absoluto, escritura de 7 a @0102.
;L7 LDA (@0010) ; LDA indirecto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#14 Prueba de instruccion STA indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #7 ; LDA inmediato con argumento decimal.
;L6 STA (@0010) ; STA indirecto, escritura de 7 a @0102.
;L7 ADD #1 ; ADD inmediato con argumento decimal.
;L8 LDA @2211 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#15 Prueba de instruccion ADD indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #6 ; LDA inmediato con argumento decimal.
;L6 STA @2211 ; STA absoluto, escritura de 7 a @2211
;L7 LDA #1 ; LDA inmediato con argumento decimal.
;L8 ADD (@0010) ; ADD indirecto, escritura de 7 a @0102.
;L9 LDA @2211 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#16 Prueba de instruccion SUB indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #1 ; LDA inmediato con argumento decimal.
;L6 STA @2211 ; STA absoluto, escritura de 7 a @2211
;L7 LDA #6 ; LDA inmediato con argumento decimal.
;L8 SUB (@0010) ; SUB indirecto.
;L9 LDA @2211 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#17 Prueba de instruccion AND indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #%111111 ; LDA inmediato con argumento decimal.
;L6 STA @2211 ; STA absoluto, escritura de 7 a @2211
;L7 LDA #%000111 ; LDA inmediato con argumento decimal.
;L8 AND (@0010) ; AND indirecto.
;L9 LDA @2211 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#18 Prueba de instruccion ORA indirecta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #@11 ; LDA inmediato con argumento decimal.
;L2 STA @0010 ; STA absoluto, escritura a PB.
;L3 LDA #@22 ; LDA inmediato con argumento decimal.
;L4 STA @0011 ; STA absoluto, escritura a PA.
;L5 LDA #%111000 ; LDA inmediato con argumento decimal.
;L6 STA @2211 ; STA absoluto, escritura de 7 a @2211
;L7 LDA #%000111 ; LDA inmediato con argumento decimal.
;L8 ORA (@0010) ; ORA indirecto.
;L9 LDA @2211 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================
;***********************************************************************************************************************

;***********************************************************************************************************************
; Instrucciones de acumulador
;***********************************************************************************************************************

;=============================================================
;#19 Prueba de instruccion CLA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 CLA ; CLA de acumulador, limpia el acumulador.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#20 Prueba de instruccion CPA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111000 ; LDA con argumento decimal.
;L2 CPA ; CPA de acumulador, complementa el acumulador.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#21 Prueba de instruccion INA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 INA ; INA de acumulador, incrementa el acumulador en 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#22 Prueba de instruccion INA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 DCA ; DCA de acumulador, decremento el acumulador en 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#23 Prueba de instruccion ROL de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111011 ; LDA con argumento decimal.
;L2 ROL ; ROL de acumulador, rota el acumulador hacia la izq.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#24 Prueba de instruccion ROR de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111011 ; LDA con argumento decimal.
;L2 ROR ; ROR de acumulador, rota el acumulador hacia la der.
;HLT ; Instruccion de detencion.
;=============================================================
;***********************************************************************************************************************

;***********************************************************************************************************************
; Instrucciones de implicitas
;***********************************************************************************************************************

;=============================================================
;#25 Prueba de instruccion SEC implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEC ; SEC implicito, pone en alto la bandera de acarreo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#26 Prueba de instruccion CLC implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEC ; SEC implicito, pone en alto la bandera de acarreo.
;L3 CLC ; CLC implicito, pone en bajo la bandera de acarreo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#27 Prueba de instruccion SEI implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEI ; SEI implicito, pone en alto la bandera de interrup.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#28 Prueba de instruccion CLI implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEI ; SEI implicito, pone en alto la bandera de interrup.
;L3 CLI ; CLI implicito, pone en bajo la bandera de interrup.
;HLT ; Instruccion de detencion.
;=============================================================
;***********************************************************************************************************************

;***********************************************************************************************************************
; Instrucciones de relativas
;***********************************************************************************************************************

;=============================================================
;#29 Prueba de instruccion BEQ relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 BEQ L1 ; Salta a L1 si el acumulador es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#30 Prueba de instruccion BNE relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 BNE L1 ; Salta a L1 si el acumulador es distinto de 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#31 Prueba de instruccion BCC relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 SEC ; Pone en alto la bandera de acarreo.
;L2 CLC ; Pone en bajo la bandera de acarreo.
;L3 BCC L2 ; Salta a L1 si la bandera de acarreo es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#32 Prueba de instruccion BCS relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 CLC ; Pone en BAJO la bandera de acarreo.
;L2 SEC ; Pone en alto la bandera de acarreo.
;L3 BCS L2 ; Salta a L1 si la bandera de acarreo es 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#33 Prueba de instruccion BPL relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%000001 ; LDA con argumento binario.
;L2 BPL L1 ; Salta a L1 si el acumulador es positivo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#34 Prueba de instruccion BMI relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%100000 ; LDA con argumento binario negativo.
;L2 BMI L1 ; Salta a L1 si el acumulador es negativo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#35 Prueba de instruccion BVC relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento binario.
;L2 ADD #1 ; Se agrega %001010 al acumulador.
;L3 BVC L1 ; Salta a L1 si la bandera de rebase es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
;#36 Prueba de instruccion BVS relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%010110 ; LDA con argumento binario.
;L2 ADD #%001010 ; Se agrega %001010 al acumulador.
;L3 BVS L1 ; Salta a L1 si la bandera de rebase es 1.
;HLT ; Instruccion de detencion.
;=============================================================
;***********************************************************************************************************************

;***********************************************************************************************************************
; Instrucciones de control
;***********************************************************************************************************************

;=============================================================
;#37 Prueba de instruccion HLT de control.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;BIN LDA #%000001 ; LDA con argumento binario.
;HLT ; Instruccion de control HTL, detiene la ejecucion.
;=============================================================

;=============================================================
;#38 Prueba de instruccion NOP de control.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;NOP ; Instruccion de control NOP.
;HLT ; Instruccion de control HTL, detiene la ejecucion.
;=============================================================
;***********************************************************************************************************************

;***********************************************************************************************************************
;#39 Instrucciones de entrada salida
;***********************************************************************************************************************

;=============================================================
; Prueba de instruccion OUT de control.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;BIN LDA #%000001 ; LDA con argumento binario.
;OUT @01 ; Escritura al puerto de salida con direccion @01.
;HLT ; Instruccion de control HTL, detiene la ejecucion.
;=============================================================

;=============================================================
;#40 Prueba de instruccion INP de control.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;BIN1 LDA #%000110 ; LDA con argumento binario.
;INP @00 ; Carga del puerto de entrada al acumulador @01.
;INP @01 ; Carga del puerto de entrada al acumulador @01.
;HLT ; Instruccion de control HTL, detiene la ejecucion.
;=============================================================
