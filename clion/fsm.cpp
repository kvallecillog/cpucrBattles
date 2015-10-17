
// All systemc modules should include systemc.h header file

// g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o fsm.sim fsm.cpp -lsystemc -lm -std=c++11 -lboost_regex

// System C library.
#include <systemc.h>

// Basic library c++ set.
#include <iostream>
#include <string>
#include <bitset>

// Boost c++ library.
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tuple/tuple.hpp>

// Instruction case definitions.
#include "definitions_dec.cpp"

// To call basic c++ methods.
using namespace std;
// To call boost methods.    
using namespace boost;

// FSM is module name
SC_MODULE (FSM) {

	SC_CTOR (FSM) {
	
		// Nothing in constructor	
	
	}

	void instruct_exec(int input) {


		cout << "\nInstruction executer!.\n";

		string Acum_A_bin;
	 	sc_bv<6> Acum_A_sc;
        sc_bv<1> BC_sc;
        sc_bv<7> BC_ACUM_A_sc;

        BC_ACUM_A_sc = BC_sc, Acum_A_sc;
	 	int line_cont = 0;
		
		string line, line_str, pc, pc_val, instr_val, opcode_val, oper_val, oper_val_pb , oper_val_pa;

		int opcode_val_dec, i_length, oper_val_pa_dec, oper_val_pb_dec, Acum_A_dec = 0;

		int BN, BV, BI, BZ, BC = 0;

		sc_bit BN_bin, BV_bin, BI_bin, BZ_bin, BC_bin;
		BN_bin, BV_bin, BI_bin, BZ_bin, BC_bin = 0;

        // Dont care operand for instruction with not pb.
		string dont_care;
		dont_care = "XXXXXX";

		// Creating the ifstream object file.
		ifstream  object_file ("file.obj");

 		// // Reading line by line of object file.
		while(getline (object_file,line)){

			line_cont++;

	  		string data_line = line ; //("this subject has a submarine as a subsequence");
		  	smatch pc_match;

		  	regex pc_regex ("\\b(\\d)*\\s");   // matches words beginning by "sub"

		  	if (regex_search (data_line, pc_match, pc_regex)){

		  		pc_val = pc_match.str();

		  		instr_val = pc_match.suffix().str();

		  		algorithm::erase_all(instr_val, " ");

		  		i_length = instr_val.length();

	            // substr(first bit, number of bits)
	            // read from left to right
		  		opcode_val = instr_val.substr(0,6);
		  		oper_val = instr_val.substr(6,12);

	            oper_val_pa = oper_val.substr(0,6);
				oper_val_pb = oper_val.substr(6,6);

			    bitset<6>  oper_val_pa_bin(oper_val_pa);
				oper_val_pa_dec = (int)(oper_val_pa_bin.to_ulong());

				if (oper_val_pb!=dont_care){

				// If operand is not a dont care value
				bitset<6>  oper_val_pb_bin(oper_val_pb);
				oper_val_pb_dec = (int)(oper_val_pb_bin.to_ulong());

				}

			    bitset<6>  opcode_val_bin(opcode_val);
				opcode_val_dec = (int)(opcode_val_bin.to_ulong());

				switch(opcode_val_dec) {

					/////////////////////////////////////////////////
					// 1-Instrucciones de direccionamiento INDEDIATO //
					/////////////////////////////////////////////////
					// case LDA_INM, ADD_INM, SUB_INM, AND_INM, ORA_INM:

						case LDA_INM:
						    
						    cout << "LDA INM Instruc:" << endl;

                            char * oper_val_pa_sc = new char [oper_val_pa.length()+1];
                            std::strcpy (oper_val_pa_sc, oper_val_pa.c_str());

                            Acum_A_sc = oper_val_pa_sc;
                            BC_ACUM_A_sc = Acum_A_sc << 1;

                            cout <<" Acum A bus: " << Acum_A_sc << endl;
                            cout <<" BC_ACUM_A_sc bus: " << BC_ACUM_A_sc[6] << endl;

//							Acum_A_dec = oper_val_pa_dec;
//							cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
//
//						    Acum_A_sc = oper_val_pa;
//
//						    cout << "Acum_A_sc: |[" << Acum_A_sc <<"]|" << endl;

//							Acum_A_bin = bitset<6> ( Acum_A_dec ).to_string();
//							cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;

//							cout << "inst " << instr_val << endl;
//							cout <<"inst legth "<< i_length<< endl;
//	            			cout << "opcode " << opcode_val << endl;
//	            			cout << "oper word " << oper_val << endl;
//	            			cout << "oper pa " << oper_val_pa << endl;
//							cout << "oper pb " << oper_val_pb << endl;
//
//						    Acum_A_dec = oper_val_pa_dec;
//
//
//							Acum_A_bin = bitset< 6 >( Acum_A_dec ).to_string();
//
//							cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
//						    cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;
//
//						    BN = Acum_A_dec & 32; //0x20 = 0b00100000
//							BN_bin = BN >> 5;
//						    cout << "BN : |[" << BN_bin <<"]|" << endl;
//
//						    // Calculating BZ flag.
//
//						    if (Acum_A_dec ==0){
//
//						    	// If accumulator A is zero, up BZ flag to 1.
//						    	BZ_bin = true;
//						    }
//
//						    else{
//
//								// If accumulator A is not zero, down BZ flag to 0.
//						    	BZ_bin = false;
//						    }
//						    cout << "BZ: |[" << BZ_bin <<"]|" << endl;


						    // BV
						    // BI
						    // BZ
						    // BC
						    break;


//						case ADD_INM:
//
//						    cout << "ADD INM Instruc:" << endl;
//
//							cout << "inst " << instr_val << endl;
//							cout <<"inst legth "<< i_length<< endl;
//	            			cout << "opcode " << opcode_val << endl;
//	            			cout << "oper word " << oper_val << endl;
//	            			cout << "oper pa " << oper_val_pa << endl;
//							cout << "oper pb " << oper_val_pb << endl;
//
//						    Acum_A_dec = Acum_A_dec + oper_val_pa_dec;
//
//							Acum_A_bin = bitset< 6 >( Acum_A_dec ).to_string();
//
//							cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
//						    cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;
//
//							BN = Acum_A_dec & 32; //0x20 = 0b00100000
//
//							BN_bin = BN >> 5;
//						    cout << "BN : |[" << BN_bin <<"]|" << endl;
//
//						    // Calculating BZ flag.
//
//						    if (Acum_A_dec ==0){
//
//						    	// If accumulator A is zero, up BZ flag to 1.
//						    	BZ_bin = true;
//						    }
//
//						    else{
//
//								// If accumulator A is not zero, down BZ flag to 0.
//						    	BZ_bin = false;
//						    }
//						    cout << "BZ: |[" << BZ_bin <<"]|" << endl;
//
//						    // BV
//						    // BI
//						    // BC
//
//						    break;

					// 	case SUB_INM:
						    
					// 	    cout << "SUB INM Instruc:" << endl;

					// 		cout << "inst " << instr_val << endl;
					// 		cout <<"inst legth "<< i_length<< endl;
	    //         			cout << "opcode " << opcode_val << endl;
	    //         			cout << "oper word " << oper_val << endl;                			
	    //         			cout << "oper pa " << oper_val_pa << endl;						    
					// 		cout << "oper pb " << oper_val_pb << endl;

					// 	    Acum_A_dec = Acum_A_dec - oper_val_pa_dec;

					// 		Acum_A_bin = bitset< 6 >( Acum_A_dec ).to_string(); 

					// 		cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
					// 	    cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;

					// 		BN = Acum_A_dec & 32; //0x20 = 0b00100000
					// 		BN_bin = BN >> 5;
					// 	    cout << "BN : |[" << BN_bin <<"]|" << endl;

					// 	    // Calculating BZ flag.

					// 	    if (Acum_A_dec ==0){

					// 	    	// If accumulator A is zero, up BZ flag to 1.
					// 	    	BZ_bin = true;
					// 	    }

					// 	    else{

					// 			// If accumulator A is not zero, down BZ flag to 0.
					// 	    	BZ_bin = false;
					// 	    }
					// 	    cout << "BZ: |[" << BZ_bin <<"]|" << endl;						    

					// 	    // cout << " PA: " << oper_val_pa_dec << endl;

					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						
					// 	case AND_INM:
						    
					// 	    cout << "AND INM Instruc:" << endl;

					// 	    cout << "inst " << instr_val << endl;
					// 		cout <<"inst legth "<< i_length<< endl;
	    //         			cout << "opcode " << opcode_val << endl;
	    //         			cout << "oper word " << oper_val << endl;                			
	    //         			cout << "oper pa " << oper_val_pa << endl;						    
					// 		cout << "oper pb " << oper_val_pb << endl;

					// 	    Acum_A_dec = Acum_A_dec&oper_val_pa_dec;

					// 		Acum_A_bin = bitset< 6 >( Acum_A_dec ).to_string(); 

					// 		cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
					// 	    cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;

					// 		BN = Acum_A_dec & 32; //0x20 = 0b00100000
					// 		BN_bin = BN >> 5;
					// 	    cout << "BN : |[" << BN_bin <<"]|" << endl;

					// 	    // Calculating BZ flag.

					// 	    if (Acum_A_dec ==0){

					// 	    	// If accumulator A is zero, up BZ flag to 1.
					// 	    	BZ_bin = true;
					// 	    }

					// 	    else{

					// 			// If accumulator A is not zero, down BZ flag to 0.
					// 	    	BZ_bin = false;
					// 	    }
					// 	    cout << "BZ: |[" << BZ_bin <<"]|" << endl;


					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case ORA_INM:
						    
					// 	    cout << "ORA INM Instruc:" << endl;

					// 	  	cout << "inst " << instr_val << endl;
					// 		cout <<"inst legth "<< i_length<< endl;
	    //         			cout << "opcode " << opcode_val << endl;
	    //         			cout << "oper word " << oper_val << endl;                			
	    //         			cout << "oper pa " << oper_val_pa << endl;						    
					// 		cout << "oper pb " << oper_val_pb << endl;

					// 	    Acum_A_dec = Acum_A_dec|oper_val_pa_dec;

					// 		Acum_A_bin = bitset< 6 >( Acum_A_dec ).to_string(); 

					// 		cout << "ACUM A dec: |[" << Acum_A_dec <<"]|" << endl;
					// 	    cout << "ACUM A bin: |[" << Acum_A_bin <<"]|" << endl;

					// 		BN = Acum_A_dec & 32; //0x20 = 0b00100000
					// 		BN_bin = BN >> 5;
					// 	    cout << "BN : |[" << BN_bin <<"]|" << endl;

					// 	    // Calculating BZ flag.

					// 	    if (Acum_A_dec ==0){

					// 	    	// If accumulator A is zero, up BZ flag to 1.
					// 	    	BZ_bin = true;
					// 	    }

					// 	    else{

					// 			// If accumulator A is not zero, down BZ flag to 0.
					// 	    	BZ_bin = false;
					// 	    }
					// 	    cout << "BZ: |[" << BZ_bin <<"]|" << endl;

					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	/////////////////////////////////////////////////
					// 	// 2-Instrucciones de direccionamiento ABSOLUTO //
					// 	/////////////////////////////////////////////////
					// 	// case LDA_ABS, STA_ABS, ADD_ABS, SUB_ABS, AND_ABS, ORA_ABS, JMP_ABS, JSR_ABS:

					// 	case LDA_ABS:
						    
					// 	    cout << "LDA ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case STA_ABS:
						    
					// 	    cout << "STA ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;


					// 	case ADD_ABS:
						    
					// 	    cout << "ADD ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case SUB_ABS:
						    
					// 	    cout << "SUB ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						
					// 	case AND_ABS:
						    
					// 	    cout << "AND ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case ORA_ABS:
						    
					// 	    cout << "ORA ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case JMP_ABS:
						    
					// 	    cout << "JMP ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case JSR_ABS:
						    
					// 	    cout << "JSR ABS Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						     

					// /////////////////////////////////////////////////
					// //3-Instrucciones de direccionamiento INDIRECTO //
					// /////////////////////////////////////////////////
					// // case LDA_IND, STA_IND, ADD_IND, SUB_IND, AND_IND, ORA_IND, JMP_IND, JSR_IND:
						    
		   //              case LDA_IND:
						    
					// 	    cout << "LDA IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case STA_IND:
						    
					// 	    cout << "STA IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;


					// 	case ADD_IND:
						    
					// 	    cout << "ADD IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case SUB_IND:
						    
					// 	    cout << "SUB IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						
					// 	case AND_IND:
						    
					// 	    cout << "AND IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case ORA_IND:
						    
					// 	    cout << "ORA IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case JMP_IND:
						    
					// 	    cout << "JMP IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 	case JSR_IND:
						    
					// 	    cout << "JSR IND Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;						    

	    //         	/////////////////////////////////////////////////
	    //         	//4-Instrucciones de direccionamiento RELATIVO  //
	    //         	/////////////////////////////////////////////////

					// 		case BEQ_REL:

					// 	    cout << "BEQ REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BNE_REL:

					// 	    cout << "BNE REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BCS_REL:

					// 	    cout << "BCS REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BCC_REL:

					// 	    cout << "BCC REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BMI_REL:

					// 	    cout << "BMI REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BPL_REL:

					// 	    cout << "BPL REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BVS_REL:

					// 	    cout << "BVC REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case BVC_REL:

					// 	    cout << "BVC REL Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

	    //         	/////////////////////////////////////////////////
	    //         	//5-Instrucciones de direccionamiento IMPLICITO  //
	    //         	/////////////////////////////////////////////////

					// 		case SEC_IMP:

					// 	    cout << "SEC IMP Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case CLC_IMP:

					// 	    cout << "CLC IMP Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case SEI_IMP:

					// 	    cout << "SEI IMP Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case CLI_IMP:

					// 	    cout << "CLI IMP Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						    
	    //             /////////////////////////////////////////////////
	    //         	//6-Instrucciones de direccionamiento ACUMULADOR  //
	    //         	/////////////////////////////////////////////////

					// 		case CLA_ACU:

					// 	    cout << "CLA ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case CPA_ACU:

					// 	    cout << "CPA ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case INA_ACU:

					// 	    cout << "INA ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case DCA_ACU:

					// 	    cout << "DCA ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;						    

					// 		case ROL_ACU:

					// 	    cout << "ROL ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;							    

					// 		case ROR_ACU:

					// 	    cout << "ROR ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case PLA_ACU:

					// 	    cout << "ROR ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case PHA_ACU:

					// 	    cout << "ROR ACU Instruc:" << endl;
					// 	    // BN=acumA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

	    //             /////////////////////////////////////////////////
	    //         	//7-Instrucciones de direccionamiento CONTROL  //
	    //         	/////////////////////////////////////////////////

					// 		case TPA_CTR:

					// 	    cout << "TPA CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case TAP_CTR:

					// 	    cout << "TAP CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case RTI_CTR:

					// 	    cout << "RTI CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case RTS_CTR:

					// 	    cout << "RTS CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;						    

					// 		case HLT_CTR:

					// 	    cout << "HLT CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;							    

					// 		case NOP_CTR:

					// 	    cout << "NOP CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case PLS_CTR:

					// 	    cout << "ROR CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case PHS_CTR:

					// 	    cout << "ROR CTR Instruc:" << endl;
					// 	    // BN=CTRmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;
						    
	    //             ////////////////////////////////////////////////////////
	    //         	//7-Instrucciones de direccionamiento ENTRADA/SALIDA  //
	    //         	////////////////////////////////////////////////////////

					// 		case INP_IO:

					// 	    cout << "INP IO Instruc:" << endl;
					// 	    // BN=IOmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;

					// 		case OUT_IO:

					// 	    cout << "OUT IO Instruc:" << endl;
					// 	    // BN=IOmA[5];
					// 	    // BV
					// 	    // BI
					// 	    // BZ
					// 	    // BC
					// 	    break;						    
						    
						    


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

	// Execute instruction from memory
	instruct.instruct_exec(1);
	
	return(0);
}

