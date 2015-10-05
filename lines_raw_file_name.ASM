1 LDA @00
2 LDA LDA
3 LDA LABEL+1000
4 LABEL LDA @00
5 LABEL LDA LABEL
6 LABEL LDA LABEL+1000
7 LDA X
8 X LDA X
9 LDA LDA+1
10 LDA LDA @00
11 LDA LDA LDA
12 LABEL LDA LDA
13 ABS1 LDA @0000 ; Direccionamiento absoluto validado.
14 ABS2 LDA A1234567 ; Direccionamiento absoluto validado.
15 LDA A1234567 ; Direccionamiento absoluto validado.
