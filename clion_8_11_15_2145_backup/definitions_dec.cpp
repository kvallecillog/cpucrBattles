#define LDA_INM 0
#define ADD_INM 16
#define SUB_INM 24
#define AND_INM 32
#define ORA_INM 40
#define LDA_ABS 1
#define STA_ABS 9
#define ADD_ABS 17
#define SUB_ABS 25
#define AND_ABS 33
#define ORA_ABS 41
#define JMP_ABS 49
#define JSR_ABS 57
#define BEQ_REL 2
#define BNE_REL 10
#define BCS_REL 18
#define BCC_REL 26
#define BMI_REL 34
#define BPL_REL 42
#define BVS_REL 50
#define BVC_REL 58
#define LDA_IND 3
#define STA_IND 11
#define ADD_IND 19
#define SUB_IND 27
#define AND_IND 35
#define ORA_IND 43
#define JMP_IND 51
#define JSR_IND 59
#define SEC_IMP 20
#define CLC_IMP 28
#define SEI_IMP 36
#define CLI_IMP 44
#define CLA_ACU 5
#define CPA_ACU 13
#define INA_ACU 21
#define DCA_ACU 29
#define ROL_ACU 37
#define ROR_ACU 45
#define PLA_ACU 53
#define PHA_ACU 61
#define TPA_CTR 6
#define TAP_CTR 14
#define RTI_CTR 22
#define RTS_CTR 30
#define HLT_CTR 38
#define NOP_CTR 46
#define PLS_CTR 54
#define PHS_CTR 62
#define INP_IO 7
#define OUT_IO 15

//Inmediate instructions
#define INM 0
//Absolute instructions
#define ABS 1
//Relative instructions
#define REL 2
//Indirect instructions
#define IND 3
//Implicit instructions
#define IMP 4
//Accumulator instructions
#define ACU 5
//Control instructions
#define CTR 6
//In/Out instructions
#define IO 7
