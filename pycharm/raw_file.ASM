
;***********************************************************************************************************************
; Instrucciones inmediatas
;***********************************************************************************************************************

;=============================================================
; Prueba de instruccion LDA inmediata.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;BIN LDA #%000001 ; LDA con argumento binario.
;OCT LDA #@02 ; LDA con argumento octal.
;HEX LDA #$03 ; LDA con argumento hexadecimal.
;DEC LDA #4 ; LDA con argumento decimal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion ADD inmediata.
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
; Prueba de instruccion SUB inmediata.
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
; Prueba de instruccion AND inmediata.
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
; Prueba de instruccion ORA inmediata.
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
; Prueba de instruccion LDA absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA @01 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion STA absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #7 ; LDA inmediato.
;L2 STA @0020 ; STA absoluto.
;L3 ADD #1 ; LDA inmediato.
;L4 LDA @0020 ; LDA absoluto.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion ADD absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA inmediato con argumento decimal.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #2 ; LDA inmediato con argumento decimal.
;L4 ADD @0020 ; ADD absoluta.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion SUB absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA inmediato con argumento decimal.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #2 ; LDA inmediato con argumento decimal.
;L4 SUB @0020 ; SUB absoluta.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion AND absoluta.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111111 ; LDA inmediato con argumento binario.
;L2 STA @0020 ; STA absoluto.
;L3 LDA #%000111 ; LDA inmediato con argumento binario.
;L4 AND @0020 ; AND absolutal.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion ORA absoluta.
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
; Instrucciones indirectas
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
; Prueba de instruccion STA indirecta.
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
; Prueba de instruccion ADD indirecta.
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
; Prueba de instruccion SUB indirecta.
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
; Prueba de instruccion AND indirecta.
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
; Prueba de instruccion ORA indirecta.
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
; Prueba de instruccion CLA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 CLA ; CLA de acumulador, limpia el acumulador.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion CPA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111000 ; LDA con argumento decimal.
;L2 CPA ; CPA de acumulador, complementa el acumulador.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion INA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 INA ; INA de acumulador, incrementa el acumulador en 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion INA de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 DCA ; DCA de acumulador, decremento el acumulador en 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion ROL de acumulador.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%111011 ; LDA con argumento decimal.
;L2 ROL ; ROL de acumulador, rota el acumulador hacia la izq.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion ROR de acumulador.
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
; Prueba de instruccion SEC implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEC ; SEC implicito, pone en alto la bandera de acarreo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion CLC implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEC ; SEC implicito, pone en alto la bandera de acarreo.
;L3 CLC ; CLC implicito, pone en bajo la bandera de acarreo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion SEI implicita.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 SEI ; SEI implicito, pone en alto la bandera de interrup.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion CLI implicita.
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
; Prueba de instruccion BEQ relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #0 ; LDA con argumento decimal.
;L2 BEQ L1 ; Salta a L1 si el acumulador es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BNE relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento decimal.
;L2 BNE L1 ; Salta a L1 si el acumulador es distinto de 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BCC relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 SEC ; Pone en alto la bandera de acarreo.
;L2 CLC ; Pone en bajo la bandera de acarreo.
;L3 BCC L2 ; Salta a L1 si la bandera de acarreo es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BCS relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 CLC ; Pone en BAJO la bandera de acarreo.
;L2 SEC ; Pone en alto la bandera de acarreo.
;L3 BCS L2 ; Salta a L1 si la bandera de acarreo es 1.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BPL relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%000001 ; LDA con argumento binario.
;L2 BPL L1 ; Salta a L1 si el acumulador es positivo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BMI relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%100000 ; LDA con argumento binario negativo.
;L2 BMI L1 ; Salta a L1 si el acumulador es negativo.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BVC relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #1 ; LDA con argumento binario.
;L2 ADD #1 ; Se agrega %001010 al acumulador.
;L3 BVC L1 ; Salta a L1 si la bandera de rebase es 0.
;HLT ; Instruccion de detencion.
;=============================================================

;=============================================================
; Prueba de instruccion BVS relativa.
;=============================================================
;* = @0000 ; Declaracion del puntero de posicion.
;L1 LDA #%010110 ; LDA con argumento binario.
;L2 ADD #%001010 ; Se agrega %001010 al acumulador.
;L3 BVS L1 ; Salta a L1 si la bandera de rebase es 1.
;HLT ; Instruccion de detencion.
;=============================================================











;DBWRD @0000
;WRD @0000
;LALA1 = 66
;upper = 55
;lala2 = 7
;BIN = %001000001000
;OCT = @12
;HEX = $FFFF
;DEC = 10
;LALA2 = @0007
;LALA3 = 11
;LALA4 = %111
;DBWRD @0000
;WRD @0000

;* = @000A DOESNT WORK
;* = * + 1
;PUNT1 = *
;PUNT2 = * + 20
;* = $3fff
;* = @0010
;DBWRD = $000A
;DBWRD $000A
;WRD $000A


;DBWRD @0100
;WRD @0000

;DBWRD 0
;WRD 0

;DBWRD %100000000000
;WRD %100000

;* = 4096
;* = %000000000000

; Todas las pruebas han sido correctamente ensambladas

; Prueba PC diferente de 0

;Prueba de NOP
;NOP
;L0 LDA #1
;INP @01
;OUT @01
;INP @01

;LDA @01
;STA @01

;Prueba de STA IND
;L0 LDA #@01

;L1 STA @0300
;L2 LDA #@01
;L3 STA @0301
;L7 LDA #7
;L4 STA (@0300)
;L5 INA
;L6 LDA @0101
;HLT


;Prueba AND ABS
;L0 LDA #%000111
;L1 STA @0300
;L2 LDA #%111000
;L3 ORA @0300

;Prueba SUB ABS
;L0 LDA #1
;L1 STA @0300
;L2 INA
;L3 SUB @0300

;Prueba ADD ABS
;L0 LDA #1
;L1 STA @0300
;L2 INA
;L3 ADD @0300

;Prueba de STA ABS
;L0 LDA #1
;L1 STA @0300
;L2 INA
;L3 LDA @0300

;L0 LDA #01
;L1 ADD @0001

;L0 LDA #63
;L1 ora #%101001

; Prueba de BCC
;L0 LDA #0
;L1 INA
;L2 BCC L0
;L3 LDA #1


; Prueba de BNE
;L SEC
;L0 CLC
;L1 LDA #0
;L2 INA
;L6 BNE L2
;L4 INA
;L5 LDA #1

; Prueba de BEQ
;L SEC
;L0 CLC
;L1 LDA #0
;L6 BEQ L1
;L4 INA
;L5 LDA #1

;Prueba de LDA inmediata
;L1 LDA #1
;L2 LDA #2
;L3 LDA #3
;L4 LDA #4
;L5 LDA #5

;Prueba de SUB y ADD inmediatas
;L0 LDA #0
;L1 LDA #63
;L2 SUB #62
;L3 SUB #1
;L4 ADD #1
;L5 ADD #1

;K3 BNE K3
;K5 BNE K3
;K1 SEC
;K2 SEC
;BNE K1
;K3 BNE K3
;K5 BNE K3
;L1 LDA (@0001)
;BNE L1
;L2 LDA @0002
;L3 LDA @0002
;BNE L1
;L1 LDA @0001

;LDA LALA1
;LDA @0001
;L1 LDA BIN
;LDA OCT
;LDA DEC
;LDA HEX
;L1 LDA HEX
;L2 LDA #HEX
;LDA #HEX
;BNE L3
;BMI L1
;LOOP1 BNE L1
;L4 BMI L2
;LDA (BIN)
;LDA (OCT)
;LDA (DEC)
;LDA (HEX)

;LDA %1010
;LDA @12
;LDA 10
;LDA $0A
;LDA (%1010)
;LDA (@12)
;LDA (10)
;LDA ($0A)

;LDA #%1010
;LDA #@12
;LDA #10
;LDA $0A
;LDA #BIN
;LDA #OCT
;LDA #DEC
;LDA #HEX

;IMP SEC
;ACU CLA
;CTR TPA

;INP %1010
;INP @12
;INP 10
;INP $0A
;INP BIN
;INP OCT
;INP DEC
;INP HEX


;LDA %111
;L2 LDA (LALA1)
;L3 LDA (%01)
;LDA (@0001)
;BNE L2
;BMI L3
;LABEL BNE LALA2
;LALA3 BNE LABEL
;BNE LABEL
;BMI LALA2
;LOOP1 CPA
;INA
;ROR
;NOP
;INP LALA1
;L1 INP lala2
;LABEL LDA (LALA1)
;BNE LABEL
;LABEL XXX LALA1
;LABEL LDA @0001
;LAB1 LDA PERRO
;BNE LABEL
;L1 BNE LALA
;LALA LDA #01
;LDA #$A
;LDA #LABEL
;LABEL LDA #@07
;LABEL1 LDA #@07
;BNE LABEL1
;INP $FF
;OUT %100
;HLT


;LDA #0
;HLT
;HLT
;HLT
;LDA #7
;LDA #7
;LDA #7
;HLT

;BEQ JUMP1
;LDA (@1000)
;SEC
;CLA
;TPA
;INP @77

