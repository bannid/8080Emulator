#include "Disassembler.h"
#include <stdio.h>
void Disassemble(unsigned char * opcode,int * opcodeLength){
    unsigned char * ptr = opcode;
    switch(*ptr){
        case 0x00:{
            printf("NOP");
            *opcodeLength = 1;
            break;
        }
        case 0x01:{
            printf("LXI B,%02x,%02x",ptr[1],ptr[2]);
            *opcodeLength = 3;
            break;
        }
        case 0x02:{
            printf("STAX B");
            *opcodeLength = 1;
            break;
        }
        case 0x03:{
            printf("INX B");
            *opcodeLength = 1;
            break;
        }
        case 0x04:{
            printf("INR B");
            *opcodeLength = 1;
            break;
        }
        case 0x05:{
            printf("DCR B");
            *opcodeLength = 1;
            break;
        }
        case 0x06:{
            printf("MVI B,%02X",ptr[1]);
            *opcodeLength = 1;
            break;
        }
        case 0x07:{
            printf("RLC");
            *opcodeLength = 1;
            break;
        }
        case 0x09:{
            printf("DAD B");
            *opcodeLength = 1;
            break;
        }
        case 0x0a:{
            printf("LDAX B");
            *opcodeLength = 1;
            break;
        }
        case 0x0b:{
        	printf("DCX B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x0c:{
        	printf("INR C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x0d:{
        	printf("DCR C");
        	*opcodeLength = 1;
        	break;
        } 
        case 0x0e:{
        	printf("MVI C, %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x0f:{
        	printf("RRC");
        	*opcodeLength = 1;
        	break;
        }
        case 0x11:{
        	printf("LXI D,%02x,%02x",ptr[1],ptr[2]);
        	*opcodeLength = 1;
        	break;
        }
        case 0x12:{
        	printf("STAX D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x13:{
        	printf("INX D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x14:{
        	printf("INR D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x15:{
        	printf("DCR D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x16:{
        	printf("MVI D,%02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x17:{
        	printf("RAL");
        	*opcodeLength = 1;
        	break;
        }
        case 0x19:{
        	printf("DAD D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x1a:{
        	printf("LDAX D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x1b:{
        	printf("DCX D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x1c:{
        	printf("INR E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x1d:{
        	printf("DCR E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x1e:{
        	printf("MVI E,%02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x1f:{
        	printf("RAR");
        	*opcodeLength = 1;
        	break;
        }
        case 0x20:{
        	printf("RIM");
        	*opcodeLength = 1;
        	break;
        }
        case 0x21:{
        	printf("LXI H,%02x,%02x",ptr[1],ptr[2]);
        	*opcodeLength = 3;
        	break;
        }
        case 0x22:{
        	//Todo: Check if the address is shown in the right format.
        	//Even if it is, we have to cater for big endian
        	printf("SHLD %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0x23:{
        	printf("INX H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x24:{
        	printf("INR H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x25:{
        	printf("DCR H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x26:{
        	printf("MVI H, %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x27:{
        	printf("DAA");
        	*opcodeLength = 1;
        	break;
        }
        case 0x29:{
        	printf("DAD H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x2a:{
        	printf("LHLD %02X%02X",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0x2b:{
        	printf("DCX H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x2c:{
        	printf("INR L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x2d:{
        	printf("DCR L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x2e:{
        	printf("MVI L,%02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x2f:{
        	printf("CMA");
        	*opcodeLength = 1;
        	break;
        }
        case 0x30:{
        	printf("SIM");
        	*opcodeLength = 1;
        	break;
        }
        case 0x31:{
        	printf("LXI SP,%02x,%02x",ptr[1],ptr[2]);
        	*opcodeLength = 3;
        	break;
        }
        case 0x32:{
        	printf("STA %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x33:{
        	printf("INX SP");
        	*opcodeLength = 1;
        	break;
        }
        case 0x34:{
        	printf("INR M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x35:{
        	printf("DCR M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x36:{
        	printf("MVI M,%02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x37:{
        	printf("STC");
        	*opcodeLength = 1;
        	break;
        }
        case 0x39:{
        	printf("DAD SP");
        	*opcodeLength = 1;
        	break;
        }
        case 0x3a:{
        	printf("LDA %02x",ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0x3b:{
        	printf("DCX SP");
        	*opcodeLength = 1;
        	break;
        }
        case 0x3c:{
        	printf("INR A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x3d:{
        	printf("DCR A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x3e:{
        	printf("MVI A,%02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0x3f:{
        	printf("CMC");
        	*opcodeLength = 1;
        	break;
        }
        case 0x40:{
        	printf("MOV B,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x41:{
        	printf("MOV B,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x42:{
        	printf("MOV B,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x43:{
        	printf("MOV B,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x44:{
        	printf("MOV B,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x45:{
        	printf("MOV B,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x46:{
        	printf("MOV B,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x47:{
        	printf("MOV B,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x48:{
        	printf("MOV C,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x49:{
        	printf("MOV C,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4a:{
        	printf("MOV C,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4b:{
        	printf("MOV C,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4c:{
        	printf("MOV C,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4d:{
        	printf("MOV C,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4e:{
        	printf("MOV C,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x4f:{
        	printf("MOV C,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x50:{
        	printf("MOV D,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x51:{
        	printf("MOV D,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x52:{
        	printf("MOV D,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x53:{
        	printf("MOV D,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x54:{
        	printf("MOV D,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x55:{
        	printf("MOV D,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x56:{
        	printf("MOV D,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x57:{
        	printf("MOV D,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x58:{
        	printf("MOV E,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x59:{
        	printf("MOV E,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5a:{
        	printf("MOV E,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5b:{
        	printf("MOV E,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5c:{
        	printf("MOV E,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5d:{
        	printf("MOV E,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5e:{
        	printf("MOV E,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x5f:{
        	printf("MOV E,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x60:{
        	printf("MOV H,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x61:{
        	printf("MOV H,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x62:{
        	printf("MOV H,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x63:{
        	printf("MOV H,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x64:{
        	printf("MOV H,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x65:{
        	printf("MOV H,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x66:{
        	printf("MOV H,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x67:{
        	printf("MOV H,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x68:{
        	printf("MOV L,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x69:{
        	printf("MOV L,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6a:{
        	printf("MOV L,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6b:{
        	printf("MOV L,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6c:{
        	printf("MOV L,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6d:{
        	printf("MOV L,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6e:{
        	printf("MOV L,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x6f:{
        	printf("MOV L,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x70:{
        	printf("MOV M,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x71:{
        	printf("MOV M,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x72:{
        	printf("MOV M,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x73:{
        	printf("MOV M,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x74:{
        	printf("MOV M,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x75:{
        	printf("MOV M,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x76:{
        	printf("HLT");
        	*opcodeLength = 1;
        	break;
        }
        case 0x77:{
        	printf("MOV M,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x78:{
        	printf("MOV A,B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x79:{
        	printf("MOV A,C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7a:{
        	printf("MOV A,D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7b:{
        	printf("MOV A,E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7c:{
        	printf("MOV A,H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7d:{
        	printf("MOV A,L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7e:{
        	printf("MOV A,M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x7f:{
        	printf("MOV A,A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x80:{
        	printf("ADD B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x81:{
        	printf("ADD C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x82:{
        	printf("ADD D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x83:{
        	printf("ADD E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x84:{
        	printf("ADD H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x85:{
        	printf("ADD L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x86:{
        	printf("ADD M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x87:{
        	printf("ADD A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x88:{
        	printf("ADC B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x89:{
        	printf("ADC C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8a:{
        	printf("ADC D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8b:{
        	printf("ADC E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8c:{
        	printf("ADC H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8d:{
        	printf("ADC L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8e:{
        	printf("ADC M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x8f:{
        	printf("ADC A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x90:{
        	printf("SUB B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x91:{
        	printf("SUB C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x92:{
        	printf("SUB D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x93:{
        	printf("SUB E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x94:{
        	printf("SUB H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x95:{
        	printf("SUB L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x96:{
        	printf("SUB M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x97:{
        	printf("SUB A");
        	*opcodeLength = 1;
        	break;
        }
        case 0x98:{
        	printf("SBB B");
        	*opcodeLength = 1;
        	break;
        }
        case 0x99:{
        	printf("SBB C");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9a:{
        	printf("SBB D");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9b:{
        	printf("SBB E");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9c:{
        	printf("SBB H");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9d:{
        	printf("SBB L");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9e:{
        	printf("SBB M");
        	*opcodeLength = 1;
        	break;
        }
        case 0x9f:{
        	printf("SBB A");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa0:{
        	printf("ANA B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa1:{
        	printf("ANA C");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa2:{
        	printf("ANA D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa3:{
        	printf("ANA E");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa4:{
        	printf("ANA H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa5:{
        	printf("ANA L");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa6:{
        	printf("ANA M");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa7:{
        	printf("ANA A");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa8:{
        	printf("XRA B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xa9:{
        	printf("XRA C");
        	*opcodeLength = 1;
        	break;
        }
        case 0xaa:{
        	printf("XRA D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xab:{
        	printf("XRA E");
        	*opcodeLength = 1;
        	break;
        }
        case 0xac:{
        	printf("XRA H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xad:{
        	printf("XRA L");
        	*opcodeLength = 1;
        	break;
        }
        case 0xae:{
        	printf("XRA M");
        	*opcodeLength = 1;
        	break;
        }
        case 0xaf:{
        	printf("XRA A");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb0:{
        	printf("ORA B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb1:{
        	printf("ORA C");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb2:{
        	printf("ORA D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb3:{
        	printf("ORA E");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb4:{
        	printf("ORA H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb5:{
        	printf("ORA L");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb6:{
        	printf("ORA M");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb7:{
        	printf("ORA A");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb8:{
        	printf("CMP B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xb9:{
        	printf("CMP C");
        	*opcodeLength = 1;
        	break;
        }
        case 0xba:{
        	printf("CMP D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xbb:{
        	printf("CMP E");
        	*opcodeLength = 1;
        	break;
        }
        case 0xbc:{
        	printf("CMP H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xbd:{
        	printf("CMP L");
        	*opcodeLength = 1;
        	break;
        }
        case 0xbe:{
        	printf("CMP M");
        	*opcodeLength = 1;
        	break;
        }
        case 0xbf:{
        	printf("CMP A");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc0:{
        	printf("RNZ");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc1:{
        	printf("POP B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc2:{
        	printf("JNZ %02x%02X",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xc3:{
        	printf("JMP %02x%02X",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xc4:{
        	printf("CNZ %02x%02X",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xc5:{
        	printf("PUSH B");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc6:{
        	printf("ADI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xc7:{
        	printf("RST 0");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc8:{
        	printf("RZ");
        	*opcodeLength = 1;
        	break;
        }
        case 0xc9:{
        	printf("RET");
        	*opcodeLength = 1;
        	break;
        }
        case 0xca:{
        	printf("JZ %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xcc:{
        	printf("CZ %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xcd:{
        	printf("CALL %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xce:{
        	printf("ACI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xcf:{
        	printf("RST 1");
        	*opcodeLength = 1;
        	break;
        }
        case 0xd0:{
        	printf("RNC");
        	*opcodeLength = 1;
        	break;
        }
        case 0xd1:{
        	printf("POP D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xd2:{
        	printf("JNC %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xd3:{
        	printf("OUT %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xd4:{
        	printf("CNC %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xd5:{
        	printf("PUSH D");
        	*opcodeLength = 1;
        	break;
        }
        case 0xd6:{
        	printf("SUI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xd7:{
        	printf("RST 2");
        	*opcodeLength = 1;
        	break;
        }
        case 0xd8:{
        	printf("RC");
        	*opcodeLength = 1;
        	break;
        }
        case 0xda:{
        	printf("JC %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xdb:{
        	printf("IN %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xdc:{
        	printf("CC %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 1;
        	break;
        }
        case 0xde:{
        	printf("SBI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xdf:{
        	printf("RST 3");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe0:{
        	printf("RPO");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe1:{
        	printf("POP H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe2:{
        	printf("JPO %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xe3:{
        	printf("XTHL");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe4:{
        	printf("CPO %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xe5:{
        	printf("PUSH H");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe6:{
        	printf("ANI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xe7:{
        	printf("RST 4");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe8:{
        	printf("RPE");
        	*opcodeLength = 1;
        	break;
        }
        case 0xe9:{
        	printf("PCHL");
        	*opcodeLength = 1;
        	break;
        }
        case 0xea:{
        	printf("JPE %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xeb:{
        	printf("XCHG");
        	*opcodeLength = 1;
        	break;
        }
        case 0xec:{
        	printf("CPE %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xee:{
        	printf("XRI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xef:{
        	printf("RST 5");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf0:{
        	printf("RP");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf1:{
        	printf("POP PSW");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf2:{
        	printf("JP %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xf3:{
        	printf("DI");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf4:{
        	printf("CP %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xf5:{
        	printf("PUSH PSW");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf6:{
        	printf("ORI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xf7:{
        	printf("RST 6");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf8:{
        	printf("RM");
        	*opcodeLength = 1;
        	break;
        }
        case 0xf9:{
        	printf("SPHL");
        	*opcodeLength = 1;
        	break;
        }
        case 0xfa:{
        	printf("JM %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xfb:{
        	printf("EI");
        	*opcodeLength = 1;
        	break;
        }
        case 0xfc:{
        	printf("CM %02x%02x",ptr[2],ptr[1]);
        	*opcodeLength = 3;
        	break;
        }
        case 0xfe:{
        	printf("CPI %02x",ptr[1]);
        	*opcodeLength = 2;
        	break;
        }
        case 0xff:{
        	printf("RST 7");
        	*opcodeLength = 1;
        	break;
        }
        default:{
            printf("Invalid opcode");
            break;
        }
    }
    printf("\n");
}
