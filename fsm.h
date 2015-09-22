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
