; Este file es de ejemplo
LDA @            # ; Hola este es un comentario
LDA @; LOLI LIA

; Este tambien es otro comentario

LDA @00
LDA @LDA
ABS1 LDA @0000 ; Direccionamiento absoluto validado.
ABS2 LDA A1234567 ; Direccionamiento absoluto validado.
LDA A1234567 ; Direccionamiento absoluto validado.


LDA (@77) ; Direccionamiento indirecto Validado.
IND1 LDA (@77) ; Direccionamiento indirecto Validado.
IND2 LDA (A1236467) ; Direccionamiento indirecto Validado.
LDA (A1234567) ; Direccionamiento indirecto Validado.
IND2 LDA (LDA) ; Direccionamiento indirecto Validado.

LDA #07 ; Direccionamiento inmediato validado.
INP @77 ; Direccionamiento de entradas y salidas validado para 64 puertos.
LDASTA INP @77
ldax
sta@
LDA()         #  02 ; Tambien este
STA# ; lalalala
TAP@
INA#
L12222
YYY LDA (xaxasaxas
XXX LDA (@77)