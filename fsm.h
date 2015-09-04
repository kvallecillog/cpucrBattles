/* Includes 
	port definitions
	local variable definitions
	function definitions 
*/


#include <systemc.h>

// SC_MODULE(FSM){

// 	/*
// 	PORTS
// 	*/

// 	sc_in < bool >	clk;
// 	// SC_IN < bool >	reset;
// 	// sc_in < sc_unit < 1 > >	A;
// 	// sc_in < sc_unit < 1 > >	B;
// 	// sc_out < sc_unit < 1 > >	C;
	
// 	SC_CTOR(FSM){



// 	}
// };

// int sc_main(int argc, char* argv[]) {

// return(0);
// }

// instruc= instruccion leida del la linea actual en el ASM.

intruct='';

// Case statement 
	switch(intruct) {
	
		
		/////////////////////////////////////////////////
		// Instrucciones de direccionamiento INMEDIATO //
		/////////////////////////////////////////////////
		
		case 'LDA':
		    // your code goes here
		    break;
		case 'ADD':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'AND':
		    // your code goes here
		    break;
		case 'ORA':
		    // your code for next==2 goes here
		    break;
		// etc.

		/////////////////////////////////////////////////
		// Instrucciones de direccionamiento ABSOLUTO  //
		/////////////////////////////////////////////////
		
		case 'LDA_AB':
		    // your code goes here
		    break;
		case 'STA_AB':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'ADD_AB':
		    // your code goes here
		    break;
		case 'SUB_AB':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'AND_AB':
		    // your code goes here
		    break;
		case 'ORA_AB':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'JMP_AB':
		    // your code goes here
		    break;
		case 'JSR_AB':
		    // your code for next==2 goes here
		    break;
		// etc.

		/////////////////////////////////////////////////
		// Instrucciones de direccionamiento RELATIVO  //
		/////////////////////////////////////////////////

		case 'BEQ':
		    // your code goes here
		    break;
		case 'BNE':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'BCS':
		    // your code goes here
		    break;
		case 'BCC':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'BMI':
		    // your code goes here
		    break;
		case 'BPL':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'BVS':
		    // your code goes here
		    break;
		case 'BVC':
		    // your code for next==2 goes here
		    break;
		// etc.

		/////////////////////////////////////////////////
		// Instrucciones con direccionamiento INDIRECTO //
		/////////////////////////////////////////////////

		case 'LDA_ID':
		    // your code goes here
		    break;
		case 'STA_ID':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'ADD_ID':
		    // your code goes here
		    break;
		case 'SUB_ID':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'AND_ID':
		    // your code goes here
		    break;
		case 'ORA_ID':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'JMP_ID':
		    // your code goes here
		    break;
		case 'JSR_ID':
		    // your code for next==2 goes here
		    break;
		// etc.    

		/////////////////////////////////////////////////
		// Instrucciones con direccionamiento IMPLICITO //
		/////////////////////////////////////////////////
		
		case 'SEC':
		    // your code goes here
		    break;
		case 'CLC':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'SEI':
		    // your code goes here
		    break;
		case 'CLI':
		    // your code for next==2 goes here
		    break;
		// etc.    
	
		/////////////////////////////////////////////////
		// Instrucciones con direccionamiento ACUMULADOR //
		/////////////////////////////////////////////////

		case 'CLA':
		    // your code goes here
		    break;
		case 'CPA':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'INA':
		    // your code goes here
		    break;
		case 'DCA':
		    // your code for next==2 goes here
		    break;
		// etc.  
		case 'ROL':
		    // your code goes here
		    break;
		case 'ROR':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'PLA':
		    // your code goes here
		    break;
		case 'PHA':
		    // your code for next==2 goes here
		    break;
		// etc.  

		/////////////////////////////////////////////////
		// Instrucciones para CONTROL DE LA CPUCR 		//
		/////////////////////////////////////////////////

		case 'TPA':
		    // your code goes here
		    break;
		case 'TAP':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'RTI':
		    // your code goes here
		    break;
		case 'RTS':
		    // your code for next==2 goes here
		    break;
		// etc.  
		case 'HLT':
		    // your code goes here
		    break;
		case 'NOP':
		    // your code for next==2 goes here
		    break;
		// etc.
		case 'PLS':
		    // your code goes here
		    break;
		case 'PHS':
		    // your code for next==2 goes here
		    break;
		// etc.  
		case 'PLS':
		    // your code goes here
		    break;
		case 'PHS':
		    // your code for next==2 goes here
		    break;
		// etc.  

		/////////////////////////////////////////////////
		// Instrucciones para CONTROL DE LA CPUCR 		//
		/////////////////////////////////////////////////

		case 'INP':
		    // your code goes here
		    break;
		case 'OUT':
		    // your code for next==2 goes here
		    break;
		// etc.  

	}



// $#$ $0000
//                    INDICE

//   {Introducci¢n}$0F01

//   {Declaraci¢n}$0010

//   {Secuencia}$0001

//   {Permanentes}$0002
// $#$ $0001
//                SECUENCIA
//            ESTADO       ESTADO
//           { 00 }$0100             { 01 }$0101
//           { 02 }$0102             { 03 }$0103
//           { 04 }$0104             { 05 }$0105
//           { 06 }$0106             { 07 }$0107
//           { 08 }$0107             { 09 }$0109
//           { 10 }$010A             { 11 }$010B
//           { 12 }$010C             { 13 }$010D
//           { 14 }$010E             { 15 }$010F
//           { 16 }$0110             { 17 }$0111
//           { 18 }$0112             { 19 }$0113
//           { 20 }$0114             { 21 }$0115
//            ESTADO        ESTADO
//           { 22 }$0116             { 23 }$0117
//           { 24 }$0118             { 25 }$0119
//           { 26 }$011A             { 27 }$011B
//           { 28 }$011C             { 29 }$011D
//           { 30 }$011E             { 31 }$011F
//           { 32 }$0120             { 33 }$0121
//           { 34 }$0122             { 35 }$0123
//           { 36 }$0124             { 37 }$0125
//           { 38 }$0126             { 39 }$0127
//           { 40 }$0128             { 41 }$0129
//           { 42 }$012A             { 43 }$012B
//           { 44 }$012C             { 45 }$012D
//            ESTADO        ESTADO
//           { 46 }$012E             { 47 }$012F
//           { 48 }$0130             { 49 }$0131
//           { 50 }$0132             { 51 }$0133
//           { 52 }$0134             { 53 }$0135
//           { 54 }$0136             { 55 }$0137
//           { 56 }$0138             { 57 }$0139
//           { 58 }$013A             { 59 }$013B
// $#$ $0010
// MODULO CPUCR;

// MEMSINC:A[6],S[6],P[6],PC[12],RDR[12],TB[6];
// MEMCOMB: RI[6];
// ENTRADAS: INT, SDMA, WAIT;
// SALIDAS: HALT, CB, CM, LE, INTOK, BD, M;
// BUSESCOM: BUSDAT[6], BUSDIR[12];
// BUSES: BALU1[6], BALU2[6];

// ETIQUETAS:
//     'Registro status
// N = S[5],
// V = S[3],
// I = S[2],
// Z = S[1],
// C = S[0],


//     'Funciones ALU

// PASE1 = FUNALU[0],
// 'produce BALU1 en BUSALU

// PASE2 = FUNALU[1],
// 'produce BALU2 en BUSALU

// RIZ = FUNALU[2],
// 'produce la rotaci¢n de BALU2 a la izquierda

// RDE = FUNALU[3],
// 'produce la rotaci¢n de BALU2 a la derecha

// SUME = FUNALU[4],
// 'produce la suma de BALU1 y BALU2

// RESTE = FUNALU[5],
// 'produce la resta de BALU1 con BALU2

// CERO = FUNALU[6],
// 'produce 6#0 en BUSALU

// YLOG = FUNALU[7],
// 'produce la Y l¢gica de BALU1 y BALU2

// OLOG = FUNALU[8],
// 'produce la O l¢gica de BALU1 y BALU2

// INVB2 = FUNALU[9],
// 'produce el complemento a 1 de BALU2



//     'Funciones UCPD
// CERO_OI = FUNUCPD[0],
// 'produce 12#0 en UCPDO y UCPDI

// PCY1_OI = FUNUCPD[1],
// 'produce la suma de PC y 1 en UCPDO y UCPDI

// PP_ALU_O = FUNUCPD[2],
// 'produce 6#@77!BUSALU en UCPDO

// PP_P_O = FUNUCPD[3],
// 'produce 6#@77!P en UCPDO

// BD_TB_OI = FUNUCPD[4],
// 'produce BUSDAT!TB en UCPDO y UCPDI

// CERO_BD_O = FUNUCPD[5],
// 'produce 6#0!BUSDAT en UCPDO

// BD_PC_OI = FUNUCPD[6],
// 'produce la suma de BUSDAT[5]!BUSDAT[5]!BUSDAT[5]!
// 'BUSDAT[5]!BUSDAT[5]!BUSDAT[5]!BUSDAT y PC+1 en UCPDO y
// 'UCPDI

// RDRY1_O = FUNUCPD[7],
// 'produce la suma de RDR y 1 en UCPDO

// PP_P_O\PCY1_I = FUNUCPD[8],
// 'produce 6#@77!P en UCPDO y la suma de PC y 1 en UCPDI

// PASE_PC_O\PCY1_I = FUNUCPD[9],
// 'produce PC en UCPDO y la suma de PC y 1 en UCPDI

// PP_P_O\PASE_PC_I = FUNUCPD[10],
// 'produce 6#@77!P en UCPDO y PC en UCPDI

// V7700_O\PASE_PC_I = FUNUCPD[11],
// 'produce 12#@7700 en UCPDO y PC en UCPDI

// V7701_O = FUNUCPD[12];
// 'produce 12#@7701 en UCPDO

// $#$ $0100
// 'Iniciaci¢n:  (1)
// 0.  CERO_OI = 1;
//     PC <= UCPDI;
//     RDR <= UCPDO;
//     I <= 1;

// $#$ $0101
// 'B£squeda del c¢digo de instrucci¢n:  (2)
// 1.  CBI = 1;
//     CMI = 1;
// I$#$ $0102
// 2.  RI <=0 BUSDAT;
// 'Ejecute las instrucciones cuyos operandos
// 'ya est n en la CPUCR
//     BALU1 = 6#1;
//     BALU2 = (A, P) * (CPA+INA+DCA+ROL+ROR+TAP,
//                          DESAPIL+PHA_PHS+TPA);
//     PASE2 = TAP+TPA;
//     RIZ = ROL;
//     RDE = ROR;
//     SUME = INA;
//     RESTE = DCA+DESAPIL;
//     CERO = CLA;
//     INVB2 = CPA;
//     A * ((CLA+CPA+INA+DCA+ROL+ROR+TPA)&-WAIT)
//                                    <= BUSALU;
//     P * ((TAP+DESAPIL+PHA_PHS)&-WAIT)
//                                    <= BUSALU;
//     C * (INA+DCA+ROL+ROR+CLC+SEC)
//                           <= (C0, D0, 0, 1) *
//     (INA+DCA+ROL, ROR, CLC, SEC);
//     Z * (CLA+TPA+CPA+INA+DCA+ROL+ROR+PLA)
//                             <= (1, CEROALU) *
//     (CLA, TPA+CPA+INA+DCA+ROL+ROR+PLA);
//     N * (TPA+CLA+CPA+INA+DCA+ROL+ROR+PLA)
//                             <= (0, BUSALU[5])
//     * (CLA, CPA+TPA+INA+DCA+ROL+ROR+PLA);
//     V * (INA + DCA) <= V0;
//     I * CLI <= 0;
//     I * SEI <= 1;
// 'Prepara direcci¢n del siguiente uso del bus
//     PCY1_OI = INS_SINPILA;
//     PP_ALU_O = DESAPIL;
//     PP_P_O = PHA_PHS;
//     PC * (INS_SINPILA&-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
// 'Salte seg£n corresponda a la instrucci¢n
//     ->(UN_CICLO&HAY_DMA, UN_CICLO&HAY_INT,
//      UN_CICLO&SIGA,HLT, PLA_PLS, RTS_RTI,
//      PHA_PHS, INMEDIATAS, INP, OUT,
//      CONDICIONALES, ABSOLUTAS+STA_AB+JMP_AB,
//      INDIRECTAS+STA_ID+JMP_ID, JSR, WAIT)/(50,
//      51,1,3,4,6,10,12,14,18,22,24,30,38,2);
// $#$ $0103
// 'Instrucci¢n HLT: (1)
// 3.  HALT = 1;
//     ->(3);
// $#$ $0104
// 'Instrucciones PLA y PLS:  (2)
// 4.  CMI = 1;
// I$#$ $0105
// 5.  S * PLS <= BUSDAT;
//     BALU1 = BUSDAT;
//     PASE1 = 1;
//     A * PLA <= BUSALU;
//     Z * PLA <= CEROALU
//     N * PLA <= BUSALU[5]
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 5);
// $#$ $0106
// 'Instrucciones RTS y RTI:  (4)
// 6.  CMI = 1;
// I$#$ $0107
// 7.  TB <= BUSDAT;
//     BALU1 = 6#1;
//     BALU2 = P;
//     RESTE = 1;
//     P * (-WAIT) <= BUSALU;
//     PP_ALU_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/7;
// $#$ $0108
// 8.  CMI = 1;
// I$#$ $0109
// 9.  I * RTI <= 0;
//     BD_TB_OI = 1;
//     RDR * (-WAIT) <= UCPDO;
//     PC * (-WAIT) <= UCPDI;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 9);
// $#$ $010A
// 'Instrucciones PHA y PHS:  (2)
// 10. CMI = 1;
// I$#$ $010B
// 11. ESCRIBA = 1;
//     BUSDAT = (A, S) * (PHA, PHS);
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//      ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 11)
// I$#$ $010C
// 'Instrucciones LDA, ADD, SUB, AND y ORA con
// 'direccionamiento INMEDIATO: (2)
// 12. CMI = 1;
// I$#$ $010D
// 13. BALU1 = BUSDAT;
//     BALU2 = A;
//     PASE1 = LDA;
//     SUME = ADD;
//     RESTE = SUB;
//     YLOG = AND;
//     OLOG = ORA;
//     A * (-WAIT) <= BUSALU;
//     C * (ADD + SUB + ADD_AB + ADD_ID) <= C0;
//     Z <= CEROALU;
//     N <= BUSALU[5];
//     V * (ADD + SUB + ADD_AB + ADD+ID) <= V0;
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 13);
// $#$ $010E
// 'Instrucci¢n INP:  (4)
// 14. CMI = 1;
// I$#$ $010F
// 15. CERO_BD_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/15;
// I$#$ $0110
// 16. PUERTO = 1;
//     CMI = 1;
// I$#$ $0111
// 17. PUERTO = 1;
//     BALU1 = BUSDAT;
//     PASE1 = 1;
//     A <= BUSALU;
//     Z <= CEROALU;
//     N <= BUSALU[5];
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 17);
// $#$ $0112
// 'Instrucci¢n OUT:  (4)
// 18. CMI = 1;
// I$#$ $0113
// 19. CERO_BD_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/19;
// I$#$ $0114
// 20. PUERTO = 1;
//     CMI = 1;
// I$#$ $0115
// 21. ESCRIBA = 1;
//     PUERTO = 1;
//     BUSDAT = A;
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 21);
// $#$ $0116
// 'Instrucciones de salto condicional:  (2)
// 22. CMI = 1;
// I$#$ $0117
// 23. PCY1_OI = FALSO;
//     BD_PC_OI = VERDADERO;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 23);
// $#$ $0118
// 'Instrucciones LDA, ADD, SUB, AND, ORA, STA y
// 'JMP con direccionamiento ABSOLUTO:
// 24. CMI = 1;
// I$#$ $0119
// 25. TB <= BUSDAT;
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/25;
// I$#$ $011A
// 26. CMI = 1;
// I$#$ $011B
// 27. BD_TB_OI = 1;
//     RDR * (-WAIT) <= UCPDO;
//     PC * (JMP_AB&-WAIT) <= UCPDI;
// 'La direcci¢n efectiva ya est  en el bus de
// 'direcciones, continue la ejecuci¢n seg£n
// 'la instrucci¢n.
//     ->(ABSOLUTAS&-WAIT, STA_AB&-WAIT,
//    JMP_AB&HAY_DMA,JMP_AB&HAY_INT, JMP_AB&SIGA,
//     WAIT)/(12, 28, 50, 51, 1, 27);
// $#$ $011C
// 'Final de la instrucci¢n STA:
// 28. CMI = 1;
// I$#$ $011D
// 29. ESCRIBA = 1;
//     BUSDAT = A;
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 29);
// $#$ $011E
// 'Instrucciones LDA, ADD, SUB, AND, ORA, STA y
// 'JMP con direccionamiento INDIRECTO:
// 30. CMI = 1;
// I$#$ $011F
// 31. TB <= BUSDAT;
//     PCY1_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/31;
// I$#$ $0120
// 32. CMI = 1;
// I$#$ $0121
// 33. BD_TB_OI = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/33;
// I$#$ $0122
// 34. CMI = 1;
// I$#$ $0123
// 35. TB <= BUSDAT;
//     RDRY1_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/35;
// I$#$ $0124
// 36. CMI = 1;
// I$#$ $0125
// 37. BD_TB_OI = 1;
//     RDR * (-WAIT) <= UCPDO;
//     PC * (JMP_ID&-WAIT) <= UCPDI;
// 'La direcci¢n efectiva ya est  en el bus de
// 'direcciones, continue la ejecuci¢n seg£n la
// 'instrucci¢n.
//     ->(INDIRECTAS&-WAIT, STA_ID&-WAIT,
//     JMP_ID&HAY_DMA,JMP_ID&HAY_INT,JMP_ID&SIGA,
//      WAIT)/(12, 28, 50, 51, 1, 37);
// $#$ $0126
// 'Instrucciones JSR con direccionamiento INDI_
// RECTO y ABSOLUTO:
// 38. CMI = 1;
// I$#$ $0127
// 39. TB <= BUSDAT;
// 'Lea parte baja de la dir. ind. de salto.
// 'Apunte con el PC a la parte alta de la
// 'direcci¢n de salto y obtenga la dir. de
// 'pila para almacenar parte ALTA del PC.
//     PP_P_O\PCY1_I = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
// 'Nuevo lugar disponible en la pila
//     BALU1 = 6#1;
//     BALU2 = P;
//     SUME = 1;
//     P * (-WAIT) <= BUSALU;
//     ->(WAIT)/39;
// I$#$ $0128
// 40. CMI = 1;
// I$#$ $0129
// 41. PP_P_O\PCY1_I = 1;
//     BUSDAT = UCPDI[11:6];
// 'Parte alta de direcci¢n de retorno.
//     RDR * (-WAIT) <= UCPDO;
// 'Dir.de pila para almacenar parte BAJA del PC.
//     ESCRIBA = 1;
// 'Nuevo lugar disponible en la pila
//     BALU1 = 6#1;
//     BALU2 = P;
//     SUME = 1;
//     P * (-WAIT) <= BUSALU;
//     ->(WAIT)/41;
// I$#$ $012A
// 42. CMI = 1;
// I$#$ $012B
// 43. PASE_PC_O\PCY1_I = 1;
//     BUSDAT = UCPDI[5:0];
// 'Parte baja de direcci¢n de retorno
//     RDR * (-WAIT) <= UCPDO;
// 'Dir. parte alta de la dir. ind. de salto
//     ESCRIBA = 1;
//     ->(JSR_ID&-WAIT, JSR_AB&-WAIT, WAIT)/(44,
//      48, 43);
// I$#$ $012C
// 44. CMI = 1;
// I$#$ $012D
// 45. BD_TB_OI = 1;
//     RDR * (-WAIT) <= UCPDO;
// 'Direcci¢n indirecta de salto
//     ->(WAIT)/45;
// I$#$ $012E
// 46. CMI = 1;
// I$#$ $012F
// 47. TB <= BUSDAT;
// 'Lea parte baja de la direcci¢n de salto
//     RDRY1_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/47;
// I$#$ $0130
// 48. CMI = 1;
// I$#$ $0131
// 49. BD_TB_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
// 'Salte a la subrutina
//     ->(HAY_DMA, HAY_INT, SIGA, WAIT)/(50, 51,
//      1, 49);
// I$#$ $0132
// 'Ejecuci¢n de DMA:  (1)
// 50. BD = 1;
//     ->(-SDMA, SDMA)/(50, 1);
// 'Salto al vector de la subrutina de servicio:
// '  (9)
// I$#$ $0133
// 51. I <= 1;
//     PP_P_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     BALU1 = 6#1;
//     BALU2 = P;
//     SUME = 1;
//     P * (-WAIT) <= BUSALU;
// I$#$ $0134
// 52. CMI = 1;
// I$#$ $0135
// 53. ESCRIBA = 1;
//     PP_P_O\PASE_PC_I = 1;
//     BUSDAT = UCPDI[11:6];
// 'Apile parte alta del PC
//     RDR * (-WAIT) <= UCPDO;
//     BALU1 = 6#1;
//     BALU2 = P;
//     SUME = 1;
//     P * (-WAIT) <= BUSALU;
//     ->(WAIT)/53;
// I$#$ $0136
// 54. CMI = 1;
// I$#$ $0137
// 55. ESCRIBA = 1;
//     V7700_O\PASE_PC_I = 1;
//     BUSDAT = UCPDI[5:0];
// 'Apile parte baja del PC
//     RDR * (-WAIT) <= UCPDO;
//     ->(WAIT)/55;
// I$#$ $0138
// 56. CMI = 1;
//     INTOK = 1;
// I$#$ $0139
// 57. TB <= BUSDAT;
//     V7701_O = 1;
//     RDR * (-WAIT) <= UCPDO;
//     INTOK = 1;
//     ->(WAIT)/57;
// I$#$ $013A
// 58. CMI = 1;
//     INTOK = 1;
// I$#$ $013B
// 59. BD_TB_OI = 1;
//     PC * (-WAIT) <= UCPDI;
//     RDR * (-WAIT) <= UCPDO;
//     INTOK = 1;
//     ->(-WAIT, WAIT)/(1, 59);

// FIN SECUENCIA;
// $#$ $0002
//                  PERMANENTES

//  {Invocaci¢n para la ALU y la UCPD}$0300
//  {Condiciones para prueba de operandos}$0301
//  {Conexiones del bus de control}$0302
//  {Condiciones para interrupciones y DMA}$0303
//  {Decodificaci¢n de instrucciones}$0304
//  {Instrucciones para secuencias de control}$0305
//  {UNIDAD: ALU}$0306
//  {UNIDAD: GENLLEV}$0307
//  {UNIDAD: GENBANDERA}$0308
//  {UNIDAD: ALU1BIT}$0309
//  {UNIDAD: DEC3A8}$0310
//  {UNIDAD: UCPD}$0311
//  {UNIDAD SUMA12BIT}$0312
// $#$ $0300
// 'Invocaci¢n para la ALU y la UCPD
// U1(BUSALU, D0, C0, V0, CEROALU) = ALU(BALU1, BALU2, C, C,
// FUNALU);
// U2(UCPDO, UCPDI) = UCPD(BUSALU, RDR, PC, TB, P, BUSDAT,
// FUNUCPD);
// $#$ $0301
// 'Condiciones para prueba de operandos
// VERDADERO = BEQ&Z + BNE&-Z + BMI&N + BPL&-N + BCS&C + BCC&-C
// + BVS&V + BVC&-V;
// FALSO     = -VERDADERO;
// $#$ $0302
// 'Conexiones para las se¤ales del bus de control de la CPUCR
// CONECTE = -BD
// BUSDIR = RDR * CONECTE
// CM = CMI * CONECTE
// CB = CBI * CONECTE
// M = -PUERTO * CONECTE;
// LE = -ESCRIBA * CONECTE;
// $#$ $0303
// 'Condiciones para determinar interrupciones y aceptar
// 'solicitudes de DMA. Se incluye la condici¢n WAIT pues no se
// 'puede realizar el salto correspondiente sin que WAIT sea
// 'cero.
// HAY_INT = -I & -INT & -WAIT;
// HAY_DMA = (I + INT) & -SDMA & -WAIT;
// SIGA    = (I + INT) &  SDMA & -WAIT;
// '-----------------------------------------------------------
// $#$ $0304
// 'Decodificaci¢n de instrucciones
// OPR(OP7, OP6, OP5, OP4, OP3, OP2, OP1, OP0) =
// DEC3A8(RI[5:3]);
// DIR(DR7, DR6, DR5, DR4, DR3, DR2, DR1, DR0) =
// DEC3A8(RI[2:0]);
// 'Instrucciones con direccionamiento INMEDIATO
// LDA = OP0 & DR0;
// ADD = OP2 & DR0;
// SUB = OP3 & DR0;
// AND = OP4 & DR0;
// ORA = OP5 & DR0;
// 'Instrucciones con direccionamiento ABSOLUTO
// LDA_AB = OP0 & DR1;
// STA_AB = OP1 & DR1;
// ADD_AB = OP2 & DR1;
// SUB_AB = OP3 & DR1;
// AND_AB = OP4 & DR1;
// ORA_AB = OP5 & DR1;
// JMP_AB = OP6 & DR1;
// JSR_AB = OP7 & DR1;
// 'Instrucciones con direccionamiento RELATIVO
// BEQ = OP0 & DR2;
// BNE = OP1 & DR2;
// BCS = OP2 & DR2;
// BCC = OP3 & DR2;
// BMI = OP4 & DR2;
// BPL = OP5 & DR2;
// BVS = OP6 & DR2;
// BVC = OP7 & DR2;
// 'Instrucciones con direccionamiento INDIRECTO
// LDA_ID = OP0 & DR3;
// STA_ID = OP1 & DR3;
// ADD_ID = OP2 & DR3;
// SUB_ID = OP3 & DR3;
// AND_ID = OP4 & DR3;
// ORA_ID = OP5 & DR3;
// JMP_ID = OP6 & DR3;
// JSR_ID = OP7 & DR3;
// 'Instrucciones con direccionamiento IMPLICITO
// SEC = OP2 & DR4;
// CLC = OP3 & DR4;
// SEI = OP4 & DR4;
// CLI = OP5 & DR4;
// 'Instrucciones con direccionamiento ACUMULADOR
// CLA = OP0 & DR5;
// CPA = OP1 & DR5;
// INA = OP2 & DR5;
// DCA = OP3 & DR5;
// ROL = OP4 & DR5;
// ROR = OP5 & DR5;
// PLA = OP6 & DR5;
// PHA = OP7 & DR5;
// 'Instrucciones para CONTROL DE LA CPUCR
// TPA = OP0 & DR6;
// TAP = OP1 & DR6;
// RTI = OP2 & DR6;
// RTS = OP3 & DR6;
// HLT = OP4 & DR6;
// NOP = OP5 & DR6;
// PLS = OP6 & DR6;
// PHS = OP7 & DR6;
// 'Instrucciones para ENTRADA/SALIDA
// INP = OP0 & DR7;
// OUT = OP1 & DR7;
// $#$ $0305
// 'Grupos de instrucciones para escoger las  secuencias de
// 'control
// UN_CICLO = TPA + TAP + CLA + CPA + INA + DCA + ROL + ROR +
// SEC + CLC + SEI + CLI + NOP;
// PLA_PLS = PLA + PLS;
// RTS_RTI = RTS + RTI;
// PHA_PHS = PHA + PHS;
// INMEDIATAS = LDA + ADD + SUB + AND + ORA;
// CONDICIONALES = BNE + BEQ + BVS + BVC + BMI + BPL + BCS +
// BCC;
// ABSOLUTAS = LDA_AB + ADD_AB + SUB_AB + AND_AB + ORA_AB;
// INDIRECTAS = LDA_ID + ADD_ID + SUB_ID + AND_ID + ORA_ID;
// DESAPIL = PLA_PLS + RTS_RTI;
// INS_SINPILA = -DESAPIL & -PHA_PHS.
// JSR = JSR_AB + JSR_ID
// STA = STA_AB + STA_ID
// '----------------------------------------------------------
// $#$ $0306
// 'Declaraciones de las unidades usadas

// UNIDAD: ALU;
// ENTRADAS: A[6], B[6], CRI, CRD, FA[10];
// SALIDAS: R[6], B0, CA, VA, ZA;
// ETIQUETAS: B0 = B[0];
// etapa0(R[0], PA[0], GA[0])
// = ALU1BIT(A[0], B[0], B[1], CRI, FA[5], FA);
// etapa1(R[1], PA[1], GA[1])
// = ALU1BIT(A[1], B[1], B[2], B[0], CG[0], FA);
// etapa2(R[2], PA[2], GA[2])
// = ALU1BIT(A[2], B[2], B[3], B[1], CG[1], FA);
// etapa3(R[3], PA[3], GA[3])
// = ALU1BIT(A[3], B[3], B[4], B[2], CG[2], FA);
// etapa4(R[4], PA[4], GA[4])
// = ALU1BIT(A[4], B[4], B[5], B[3], CG[3], FA);
// etapa5(R[5], PA[5], GA[5])
// = ALU1BIT(A[5], B[5], CRD, B[4], CG[4], FA);
// ugell(CG) = GENLLEV(PA, GA, FA[5]);
// ugeba(CA, VA, ZA)
// = GENBANDERA(R, CG[5], CG[4], FA[2], FA[4], FA[5], B[5]);
// FIN UNIDAD;
// $#$ $0307
// UNIDAD: GENLLEV;
// ENTRADAS: P[6], G[6], Co;
// SALIDAS: C[6];
// LINEAS: C[6], a[21];
// CL1(a[0]) = AND2(P[0], Co);
// CL2(C[0]) = OR2(A[1], G[0]);
// CL3(a[1]) = AND3(P[1:0], Co);
// CL4(a[2]) = AND2(P[1], G[0]);
// CL5(C[1]) = OR3(a[2:1], G[1]);
// CL6(a[3]) = AND4(P[2:0], Co);
// CL7(a[4]) = AND3(P[2:1], G[0]);
// CL8(a[5]) = AND2(P[2], G[1]);
// CL9(C[2]) = OR4(a[5:3], G[2]);
// CL10(a[6]) = AND5(P[3:0], Co);
// CL11(a[7]) = AND4(P[3:1], G[0]);
// CL12(a[8]) = AND3(P[3:2], G[1]);
// CL13(a[9]) = AND2(P[3], G[2]);
// CL14(C[3]) = OR5(a[9:6], G[3]);
// CL15(a[10]) = AND6(P[4:0], Co);
// CL16(a[11]) = AND5(P[4:1], G[0]);
// CL17(a[12]) = AND4(P[4:2], G[1]);
// CL18(a[13]) = AND3(P[4:3], G[2]);
// CL19(a[14]) = AND2(P[4], G[3]);
// CL20(C[4]) = OR6(a[14:10], G[4]);
// CL21(a[15]) = AND7(P[5:0], Co);
// CL22(a[16]) = AND6(P[5:1], G[0]);
// CL23(a[17]) = AND5(P[5:2], G[1]);
// CL24(a[18]) = AND4(P[5:3], G[2]);
// CL25(a[19]) = AND3(P[5:4], G[3]);
// CL26(a[20]) = AND2(P[5], G[4]);
// CL27(C[5]) = OR7(a[20:15], G[5]);
// FIN UNIDAD;
// $#$ $0308
// UNIDAD: GENBANDERA;
// ENTRADAS: RB[6], C6, C5, F2, F4, F5, B5;
// SALIDAS: CB, VB, ZB;
// P1(ZB) = NOR6(RB[5:0]);
// P2(VB) = EXOR(C6,C5);
// P3(a) = OR2(F4,F5);
// P4(b) = AND2(F2, B5);
// P5(c) = AND2(a, C6);
// P6(CB) = OR2(b, c);
// FIN UNIDAD;
// $#$ $0309
// UNIDAD: ALU1BIT;
// ENTRADAS: B1, B2, BIZ, BDE, CIN, FB[10];
// SALIDAS: BIT, P, G;
// LINEAS: L[10];
// CA1(a) = EXOR(B1, FB[5]);
// CA2(P) = EXOR(a, B2);
// CA3(G) = AND2(a, B2);
// CA4(b) = EXOR(P, CIN);
// CA5(c) = AND2(B1, B2);
// CA6(d) = OR2(B1, B2);
// CA7(e) = INV(B2);
// CA8(L[0]) = AND2(B2, FB[0]);
// CA9(L[1]) = AND2(B1, FB[1]);
// CA10(L[2]) = AND2(BDE, FB[2]);
// CA11(L[3]) = AND2(BIZ, FB[3]);
// CA12(L[4]) = AND2(b, FB[4]);
// CA13(L[5]) = AND2(b, FB[5]);
// CA14(L[6]) = AND2(0, FB[6]);
// CA15(L[7]) = AND2(c, FB[7]);
// CA16(L[8]) = AND2(d, FB[8]);
// CA17(L[9]) = AND2(e, FB[9]);
// CA18(BIT]) = OR10(L);
// FIN UNIDAD;
// $#$ $0310
// UNIDAD: DEC3A8;
// ENTRADAS: E[3];
// SALIDAS: S[8];
//     D1(Eb[0]) = INV(E[0]);
//     D2(Eb[1]) = INV(E[1]);
//     D3(Eb[2]) = INV(E[2]);
//     D4(S[0]) = AND3(Eb[2], Eb[1], Eb[0]);
//     D5(S[1]) = AND3(Eb[2], Eb[1], E[0]);
//     D6(S[2]) = AND3(Eb[2], E[1], Eb[0]);
//     D7(S[3]) = AND3(Eb[2], E[1], E[0]);
//     D8(S[4]) = AND3(E[2], Eb[1], Eb[0]);
//     D9(S[5]) = AND3(E[2], Eb[1], E[0]);
//     D10(S[6]) = AND3(E[2], E[1], Eb[0]);
//     D11(S[7]) = AND3(E[2], E[1], E[0]);
// FIN UNIDAD;
// $#$ $0311
// UNIDAD: UCPD;
// ENTRADAS: UBUSALU[6], URDR[12], UPC[12], UTB[6], UP[6],
// D[6], U[13];
// SALIDAS: BUSO[12], BUSI[12];
// ETIQUETAS: SCO = U[6]
// SUMAUCPD(SS) = SUMA12BIT(SX, SY, SCO)
//     T1(h1) = OR2(U[11], U[12]);
//     T2(h2) = OR3(U[3], U[8], U[10]);
//     T3(h3) = OR6(U[2], U[3], U[8], U[10], U[11], U[12]);
//     T4(h4) = OR4(U[0], U[1], U[4], U[6]);
//     T5(h5) = OR4(U[1], U[6], U[8], U[9]);
//     T6(h6) = OR2(U[10], U[11]);
//     T7(h7) = OR4(U[1], U[7], U[8], U[9]);
//     T8(h8) = OR4(U[1], U[6], U[8], U[9]);
//     T9(BUSO[0]) = TSB(%1, U[12]);
//     T10(BUSO[0]) = TSB(%0, U[11]);
//     T11(BUSO[5:1]) = TSB(5#0, h1);
//     T12(BUSO[5:0]) = TSB(UBUSALU, U[2]);
//     T13(BUSO[5:0]) = TSB(UP, h2);
//     T14(BUSO[11:6]) = TSB(6#@77, h3);
//     T15(BUSO) = TSB(UPC, U[9]);
//     T16(BUSO) = TSB(6#0!D, U[5]);
//     T17(BUSO) = TSB(SS, U[7]);
//     T18(BUSO) = TSB(BUSI, h4);
//     T19(BUSI) = TSB(SS, h5);
//     T20(BUSI) = TSB(D!UTB, U[4]);
//     T21(BUSI) = TSB(12#0, U[0]);
//     T22(BUSI) = TSB(UPC, h6);
//     T23(SY) = TSB(12#1, h7);
//     T24(SY) = TSB(D[5]!D[5]!D[5]!D[5]!D[5]!D[5]!D, U[6]);
//     T25(SX) = TSB(URDR, U[7]);
//     T26(SX) = TSB(UPC, h8);
// FIN UNIDAD;
// $#$ $0312
// UNIDAD SUMA12BIT;
// ENTRADAS: X[12], Y[12], CO;
// SALIDAS: S[12];
// K0(sp[0]) = EXOR(X[0], Y[0]);
// K1(sp[1]) = EXOR(X[1], Y[1]);
// K2(sp[2]) = EXOR(X[2], Y[2]);
// K3(sp[3]) = EXOR(X[3], Y[3]);
// K4(sp[4]) = EXOR(X[4], Y[4]);
// K5(sp[5]) = EXOR(X[5], Y[5]);
// K6(sp[6]) = EXOR(X[6], Y[6]);
// K7(sp[7]) = EXOR(X[7], Y[7]);
// K8(sp[8]) = EXOR(X[8], Y[8]);
// K9(sp[9]) = EXOR(X[9], Y[9]);
// K10(sp[10]) = EXOR(X[10], Y[10]);
// K11(sp[11]) = EXOR(X[11], Y[11]);
// Q0(sg[0]) = AND2[X[0], Y[0]);
// Q1(sg[1]) = AND2[X[1], Y[1]);
// Q2(sg[2]) = AND2[X[2], Y[2]);
// Q3(sg[3]) = AND2[X[3], Y[3]);
// Q4(sg[4]) = AND2[X[4], Y[4]);
// Q5(sg[5]) = AND2[X[5], Y[5]);
// Q6(sg[6]) = AND2[X[6], Y[6]);
// Q7(sg[7]) = AND2[X[7], Y[7]);
// Q8(sg[8]) = AND2[X[8], Y[8]);
// Q9(sg[9]) = AND2[X[9], Y[9]);
// Q10(sg[10]) = AND2[X[10], Y[10]);
// Q11(sg[11]) = AND2[X[11], Y[11]);
// G1(sc[5:0]) = GENLLEV(sp[5:0], sg[5:0], CO);
// G2(sc[11:6]) = GENLLEV(sp[11:6], sg[11:6], sc[5]);
// M0(S[0]) = EXOR(sp[0], sc[0]);
// M1(S[1]) = EXOR(sp[1], sc[1]);
// M2(S[2]) = EXOR(sp[2], sc[2]);
// M3(S[3]) = EXOR(sp[3], sc[3]);
// M4(S[4]) = EXOR(sp[4], sc[4]);
// M5(S[5]) = EXOR(sp[5], sc[5]);
// M6(S[6]) = EXOR(sp[6], sc[6]);
// M7(S[7]) = EXOR(sp[7], sc[7]);
// M8(S[8]) = EXOR(sp[8], sc[8]);
// M9(S[9]) = EXOR(sp[9], sc[9]);
// M10(S[10]) = EXOR(sp[10], sc[10]);
// M11(S[11]) = EXOR(sp[11], sc[11]);
// FIN UNIDAD;

// FIN MODULO;

// $#$ $0F01
//                 ÚÄÄÄÄÄÄÄ¿
//                 ³ FACIL ³
//                 ÀÄÄÄÄÄÄÄÙ
// Formulaci¢n Algoritmica para CIruitos L¢gicos

//    El dise¤o de sistemas digitales medianos y
// grandes es una labor bastante compleja y en -
// gorrosa por  la cantidad  de detalles  que se
// deben administrar.
//    FACIL es un lenguaje que ayuda a describir
// la estructura  l¢gica de  un sistema  digital
// desde el punto de vista de sus elementos:
//       Compuertas       Flip Flop
//       Registros
//       Unidades l¢gico aritm‚ticas
// as¡ como desde el punto de vista  de interac-
// ci¢n entre ellos.

//    Se presenta en esta ayuda la declaraci¢n
// en facil de la CPUCR hecha por:





// que se tomo para construir este simulador.