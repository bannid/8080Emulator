#include "Emulator.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
int Decoder(unsigned char*);
void InstructionNotImplemented(unsigned char*);
void Emulate(unsigned char*);
struct Flags{
    uint8_t z:1;
    uint8_t s:1;
    uint8_t p:1;
    uint8_t cy:1;
    uint8_t ac:1;
    uint8_t pad:3;
}Flags;
struct State8080{
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h;
    uint8_t l;
    uint16_t sp;
    uint16_t pc;
    uint8_t * memory;
    struct Flags flags;
    int interrup_enabled;
}State8080;
void Emulate(unsigned char * fileName){
    struct State8080 cpu;
    FILE * filePointer = fopen(fileName, "rb");
	if (filePointer == NULL)    
    {    
        printf("error: Couldn't open %s\n", fileName);    
        exit(1);    
    }
    fseek(filePointer, 0L, SEEK_END);    
    int fileSize = ftell(filePointer);    
    fseek(filePointer, 0L, SEEK_SET);  
    cpu.memory = malloc(fileSize);
    fread(cpu.memory, fileSize, 1, filePointer); 
    fclose(filePointer);
    cpu.pc = 0;
    //Todo: Refactor this
    while(cpu.pc < fileSize){
    	cpu.pc += Decoder(cpu.memory);
    	cpu.memory += cpu.pc;
    }
}

int Decoder(unsigned char * opcode){
	//As most opcodes are one byte long,
	//we gonna have opcodeLength defaulted to 1
	int opcodeLength = 1;
	switch(*opcode){
		case 0x00:{
			break;
		}
		default:{
            //Todo: Once we have implemented all the instructions,
            //we have to remove this function from the default.
			InstructionNotImplemented(opcode);
		}
	}
	return opcodeLength;
}

void InstructionNotImplemented(unsigned char * opcode){
	printf("The instruction %02x is not currently implemented\n",*opcode);
	exit(0);
}