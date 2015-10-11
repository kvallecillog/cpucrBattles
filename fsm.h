
//Inmediate instructions
#define LDA_INM '000000'
#define STA_INM='001000'
#define ADD_INM='010000'
#define SUB_INM='011000'
#define AND_INM='100000'
#define ORA_INM='101000'
#define JMP_INM='110000'
#define JSR_INM='111000'

//Absolute instructions
#define LDA_ABS='000001'
#define STA_ABS='001001'
#define ADD_ABS='010001'
#define SUB_ABS='011001'
#define AND_ABS='100001'
#define ORA_ABS='101001'
#define JMP_ABS='110001'
#define JSR_ABS='111001'

//Relative instructions
#define BEQ_REL='000010'
#define BNE_REL='001010'
#define BCS_REL='010010'
#define BCC_REL='011010'
#define BMI_REL='100010'
#define BPL_REL='101010'
#define BVS_REL='110010'
#define BVC_REL='111010'

//Indirect instructions
#define LDA_IND='000011'
#define STA_IND='001011'
#define ADD_IND='010011'
#define SUB_IND='011011'
#define AND_IND='100011'
#define ORA_IND='101011'
#define JMP_IND='110011'
#define JSR_IND='111011'

//Implicit instructions
#define SEC_IMP='010100'
#define CLC_IMP='011100'
#define SEI_IMP='100100'
#define CLI_IMP='101100'

//Accumulator instructions
#define CLA_ACU='000101'
#define CPA_ACU='001101'
#define INA_ACU='010101'
#define DCA_ACU='011101'
#define ROL_ACU='100101'
#define ROR_ACU='101101'
#define PLA_ACU='110101'
#define PHA_ACU='111101'

//Control instructions
#define TPA_CTR='000110'
#define TAP_CTR='001110'
#define RTI_CTR='010110'
#define RTS_CTR='011110'
#define HTL_CTR='100110'
#define ROR_ACU='101101'
#define NOP_CTR='101110'

//In/Out instructions
#define INP_IO='000111'
#define OUT_IO='001111'


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


int 

// instruc= instruccion leida del la linea actual en el ASM.

intruct='';

bool BN;
bool BV;
bool BI; 
bool BZ;
bool BC;


bool reg_state={BN,BV,BI,BZ,BC};
bool acumA [6]; 

// Case statement 
	switch(intruct) {
	
		/////////////////////////////////////////////////
		// Instrucciones de direccionamiento INMEDIATO //
		/////////////////////////////////////////////////
		
		case 'LDA':
		    
		    BN=acumA[5];
		    BV
		    BI
		    BZ
		    BC

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
