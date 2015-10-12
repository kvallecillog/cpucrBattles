
// All systemc modules should include systemc.h header file
#include <systemc.h>

// regex_search example
#include <iostream>

#include <string>

#include <boost/regex.hpp>


#include <boost/algorithm/string.hpp>

#include <boost/tuple/tuple.hpp>

#include <bitset>

#include "definitions_dec.cpp"

    using namespace std;
    
    using namespace boost;

// FSM is module name
SC_MODULE (FSM) {
SC_CTOR (FSM) {
// Nothing in constructor
}

void instruct_exec(int input) {


	cout << "\nInstruction executer!.\n";

	cout << "This is an input var: " << input << "\n";

	 	int line_cont;

	 	line_cont=0;
		
		// Object file line.
		string line;
		string line_str;
		string pc;
		string pc_val;
		string instr_val;
		string opcode_val;
		int opcode_val_dec;
		string oper_val;
		regex e1;
		// pc_match;

		// Creating the ifstream object file.
		ifstream  object_file ("file.obj");
		
		
		// std::regex regex_pc ("\\d"); 

		// // Reading line by line of object file.
		while(getline (object_file,line)){

	  		string data_line = line ; //("this subject has a submarine as a subsequence");
		  	smatch pc_match;
		  	// regex e1 ("\\d");  
		  	regex pc_regex ("\\b(\\d)*\\s");   // matches words beginning by "sub"

		  	if (regex_search (data_line, pc_match, pc_regex)){
 			// 	for (auto x:pc_match) std::cout << x << " ";
    // 			std::cout << std::endl;
				// // cout << "Matched regex" << endl;		    
		  		pc_val = pc_match.str();
		  		instr_val = pc_match.suffix().str();
		  		algorithm::erase_all(instr_val, " "); 
		  		opcode_val = instr_val.substr(0,6);
		  		oper_val = instr_val.substr(6,12);

				// cout << pc_val<< endl;
				// cout << instr_val<< endl;
				// cout << opcode_val<< endl;
				// cout << oper_val<< endl;

			    std::bitset<6>  opcode_val_bin(opcode_val);


				opcode_val_dec = (int)(opcode_val_bin.to_ulong());
    			std::cout << opcode_val_bin << ":" << opcode_val_dec << std::endl;

				// cout << "opcode int" << int(opcode_val_bin) << endl;

				switch(opcode_val_dec) {

					/////////////////////////////////////////////////
					// 1-Instrucciones de direccionamiento INDEDIATO //
					/////////////////////////////////////////////////
					// case LDA_INM, ADD_INM, SUB_INM, AND_INM, ORA_INM:

						case LDA_INM:
						    
						    cout << "LDA INM Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;


						case ADD_INM:
						    
						    cout << "ADD INM Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case SUB_INM:
						    
						    cout << "SUB INM Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						
						case AND_INM:
						    
						    cout << "AND INM Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case ORA_INM:
						    
						    cout << "ORA INM Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

					/////////////////////////////////////////////////
					// 2-Instrucciones de direccionamiento ABSOLUTO //
					/////////////////////////////////////////////////
					// case LDA_ABS, STA_ABS, ADD_ABS, SUB_ABS, AND_ABS, ORA_ABS, JMP_ABS, JSR_ABS:

						case LDA_ABS:
						    
						    cout << "LDA ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case STA_ABS:
						    
						    cout << "STA ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;


						case ADD_ABS:
						    
						    cout << "ADD ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case SUB_ABS:
						    
						    cout << "SUB ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						
						case AND_ABS:
						    
						    cout << "AND ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case ORA_ABS:
						    
						    cout << "ORA ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case JMP_ABS:
						    
						    cout << "JMP ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case JSR_ABS:
						    
						    cout << "JSR ABS Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						     

					/////////////////////////////////////////////////
					//3-Instrucciones de direccionamiento INDIRECTO //
					/////////////////////////////////////////////////
					// case LDA_IND, STA_IND, ADD_IND, SUB_IND, AND_IND, ORA_IND, JMP_IND, JSR_IND:
						    
		                case LDA_IND:
						    
						    cout << "LDA IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case STA_IND:
						    
						    cout << "STA IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;


						case ADD_IND:
						    
						    cout << "ADD IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case SUB_IND:
						    
						    cout << "SUB IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						
						case AND_IND:
						    
						    cout << "AND IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case ORA_IND:
						    
						    cout << "ORA IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case JMP_IND:
						    
						    cout << "JMP IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

						case JSR_IND:
						    
						    cout << "JSR IND Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;						    

                	/////////////////////////////////////////////////
                	//4-Instrucciones de direccionamiento RELATIVO  //
                	/////////////////////////////////////////////////

  						case BEQ_REL:

						    cout << "BEQ REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BNE_REL:

						    cout << "BNE REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BCS_REL:

						    cout << "BCS REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BCC_REL:

						    cout << "BCC REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BMI_REL:

						    cout << "BMI REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BPL_REL:

						    cout << "BPL REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BVS_REL:

						    cout << "BVC REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case BVC_REL:

						    cout << "BVC REL Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

                	/////////////////////////////////////////////////
                	//5-Instrucciones de direccionamiento IMPLICITO  //
                	/////////////////////////////////////////////////

  						case SEC_IMP:

						    cout << "SEC IMP Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case CLC_IMP:

						    cout << "CLC IMP Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case SEI_IMP:

						    cout << "SEI IMP Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case CLI_IMP:

						    cout << "CLI IMP Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						    
                    /////////////////////////////////////////////////
                	//6-Instrucciones de direccionamiento ACUMULADOR  //
                	/////////////////////////////////////////////////

  						case CLA_ACU:

						    cout << "CLA ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case CPA_ACU:

						    cout << "CPA ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case INA_ACU:

						    cout << "INA ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case DCA_ACU:

						    cout << "DCA ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;						    

  						case ROL_ACU:

						    cout << "ROL ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;							    

  						case ROR_ACU:

						    cout << "ROR ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case PLA_ACU:

						    cout << "ROR ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case PHA_ACU:

						    cout << "ROR ACU Instruc:" << endl;
						    // BN=acumA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

                    /////////////////////////////////////////////////
                	//7-Instrucciones de direccionamiento CONTROL  //
                	/////////////////////////////////////////////////

  						case TPA_CTR:

						    cout << "TPA CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case TAP_CTR:

						    cout << "TAP CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case RTI_CTR:

						    cout << "RTI CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case RTS_CTR:

						    cout << "RTS CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;						    

  						case HLT_CTR:

						    cout << "HLT CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;							    

  						case NOP_CTR:

						    cout << "NOP CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case PLS_CTR:

						    cout << "ROR CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case PHS_CTR:

						    cout << "ROR CTR Instruc:" << endl;
						    // BN=CTRmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;
						    
                    ////////////////////////////////////////////////////////
                	//7-Instrucciones de direccionamiento ENTRADA/SALIDA  //
                	////////////////////////////////////////////////////////

  						case INP_IO:

						    cout << "INP IO Instruc:" << endl;
						    // BN=IOmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;

  						case OUT_IO:

						    cout << "OUT IO Instruc:" << endl;
						    // BN=IOmA[5];
						    // BV
						    // BI
						    // BZ
						    // BC
						    break;						    
						    
						    


				}

			}
			
			else{
		
				cout << "Error: Object file is invalid!" << endl;
		
			}

		
		}


}
};

// sc_main in top level function like in C++ main
int sc_main(int argc, char* argv[]) {
FSM instruct("Hello");
// Print the hello world
instruct.instruct_exec(1);
return(0);
}




// int instruct_exec() {

// // bool BN;
// // bool BV;
// // bool BI; 
// // bool BZ;
// // bool BC;


// // bool reg_state={BN,BV,BI,BZ,BC};
// // bool acumA [6]; 

// 	// Case statement 
// 	switch(intruct) {
	
// 		/////////////////////////////////////////////////
// 		// Instrucciones de direccionamiento INDEDIATO //
// 		/////////////////////////////////////////////////
// 		case "LDA_IND", "STA_IND", "ADD_IND", "SUB_IND", "AND_IND", "ORA_IND", "JMP_IND", "JSR_IND":

// 			case "LDA_IND":
			    
			    
// 			    // BN=acumA[5];
// 			    // BV
// 			    // BI
// 			    // BZ
// 			    // BC
// 			    break;

// 			    // BN=acumA[5];
// 			    // BV
// 			    // BI
// 			    // BZ
// 			    // BC

// 			case "STA_IND":
			    
			    
// 			    // BN=acumA[5];
// 			    // BV
// 			    // BI
// 			    // BZ
// 			    // BC
// 			    break;


// 			case "LDA_IND":
			    
			    
// 			    // BN=acumA[5];
// 			    // BV
// 			    // BI
// 			    // BZ
// 			    // BC
// 			    break;

// 			case "STA_IND":
			    
			    
// 			    // BN=acumA[5];
// 			    // BV
// 			    // BI
// 			    // BZ
// 			    // BC
// 			    break;
// 			}
// }



// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones de direccionamiento INDOLUTO  //
// 	// 	/////////////////////////////////////////////////
		
// 	// 	case "LDA_AB":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "STA_AB":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "ADD_AB":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "SUB_AB":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "AND_AB":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "ORA_AB":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "JMP_AB":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "JSR_AB":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.

// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones de direccionamiento RELATIVO  //
// 	// 	/////////////////////////////////////////////////

// 	// 	case "BEQ":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "BNE":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "BCS":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "BCC":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "BMI":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "BPL":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "BVS":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "BVC":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.

// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones con direccionamiento INDIRECTO //
// 	// 	/////////////////////////////////////////////////

// 	// 	case "LDA_ID":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "STA_ID":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "ADD_ID":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "SUB_ID":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "AND_ID":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "ORA_ID":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "JMP_ID":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "JSR_ID":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.    

// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones con direccionamiento IMPLICITO //
// 	// 	/////////////////////////////////////////////////
		
// 	// 	case "SEC":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "CLC":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "SEI":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "CLI":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.    
	
// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones con direccionamiento ACUMULADOR //
// 	// 	/////////////////////////////////////////////////

// 	// 	case "CLA":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "CPA":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "INA":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "DCA":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  
// 	// 	case "ROL":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "ROR":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "PLA":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "PHA":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  

// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones para CONTROL DE LA CPUCR 		//
// 	// 	/////////////////////////////////////////////////

// 	// 	case "TPA":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "TAP":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "RTI":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "RTS":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  
// 	// 	case "HLT":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "NOP":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.
// 	// 	case "PLS":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "PHS":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  
// 	// 	case "PLS":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "PHS":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  

// 	// 	/////////////////////////////////////////////////
// 	// 	// Instrucciones para CONTROL DE LA CPUCR 		//
// 	// 	/////////////////////////////////////////////////

// 	// 	case "INP":
// 	// 	    // your code goes here
// 	// 	    break;
// 	// 	case "OUT":
// 	// 	    // your code for next==2 goes here
// 	// 	    break;
// 	// 	// etc.  

// 	// }
