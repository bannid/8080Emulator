#include "Emulator.h"
#include <stdlib.h>
#include <stdio.h>
int Decoder(unsigned char*);
void InstructionNotImplemented(unsigned char*);
void Emulate(unsigned char*);

void Emulate(unsigned char * fileName){
    FILE * filePointer = fopen(fileName, "rb");
	if (filePointer == NULL)    
    {    
        printf("error: Couldn't open %s\n", fileName);    
        exit(1);    
    }
    fseek(filePointer, 0L, SEEK_END);    
    int fileSize = ftell(filePointer);    
    fseek(filePointer, 0L, SEEK_SET);  
    //Buffer to hold all the code
    unsigned char * buffer = malloc(fileSize);
    fread(buffer, fileSize, 1, filePointer); 
    fclose(filePointer);
    //Temp program counter
    int pc = 0;
    while(pc < fileSize){
    	pc += Decoder(buffer);
    	buffer += pc;
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