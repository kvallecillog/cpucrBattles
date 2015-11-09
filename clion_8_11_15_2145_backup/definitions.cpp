
//Inmediate instructions
#define LDA_INM 000000
#define ADD_INM 010000
#define SUB_INM 011000
#define AND_INM 100000
#define ORA_INM 101000

//Absolute instructions
#define LDA_ABS 000001
#define STA_ABS 001001
#define ADD_ABS 010001
#define SUB_ABS 011001
#define AND_ABS 100001
#define ORA_ABS 101001
#define JMP_ABS 110001
#define JSR_ABS 111001

//Relative instructions
#define BEQ_REL 000010
#define BNE_REL 001010
#define BCS_REL 010010
#define BCC_REL 011010
#define BMI_REL 100010
#define BPL_REL 101010
#define BVS_REL 110010
#define BVC_REL 111010

//Indirect instructions
#define LDA_IND 000011
#define STA_IND 001011
#define ADD_IND 010011
#define SUB_IND 011011
#define AND_IND 100011
#define ORA_IND 101011
#define JMP_IND 110011
#define JSR_IND 111011

//Implicit instructions
#define SEC_IMP 010100
#define CLC_IMP 011100
#define SEI_IMP 100100
#define CLI_IMP 101100

//Accumulator instructions
#define CLA_ACU 000101
#define CPA_ACU 001101
#define INA_ACU 010101
#define DCA_ACU 011101
#define ROL_ACU 100101
#define ROR_ACU 101101
#define PLA_ACU 110101
#define PHA_ACU 111101

//Control instructions
#define TPA_CTR 000110
#define TAP_CTR 001110
#define RTI_CTR 010110
#define RTS_CTR 011110
#define HLT_CTR 100110
#define NOP_CTR 101110
#define PLS_CTR 110110
#define PHS_CTR 111110

//In/Out instructions
#define INP_IO 000111
#define OUT_IO 001111

//Inmediate instructions
#define INM 000000
//Absolute instructions
#define ABS 000001
//Relative instructions
#define REL 000010
//Indirect instructions
#define IND 000011
//Implicit instructions
#define IMP 010100
//Accumulator instructions
#define ACU 000101
//Control instructions
#define CTR 000110
//In/Out instructions
#define IO 000111