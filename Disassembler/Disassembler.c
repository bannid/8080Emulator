#include "Disassembler.h"
#include <stdio.h>
void Disassemble(char * opcode,int * opcodeLength){
    char * ptr = opcode;
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
        default:{
            printf("Invalid opcode");
        }
    }
    printf("\n");
}
