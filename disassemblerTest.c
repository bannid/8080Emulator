#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "Disassembler/Disassembler.h"
int main(int argumentCount, char ** arguments){
	FILE * filePointer = fopen(arguments[1], "rb");
	if (filePointer == NULL)    
    {    
        printf("error: Couldn't open %s\n", arguments[1]);    
        exit(1);    
    }
    fseek(filePointer, 0L, SEEK_END);    
    int fileSize = ftell(filePointer);    
    fseek(filePointer, 0L, SEEK_SET);  

    unsigned char * buffer = malloc(fileSize);
    fread(buffer, fileSize, 1, filePointer); 
    fclose(filePointer);
    int opcodeLength = 0;
    for(uint16_t i = 0; i<fileSize;i+=opcodeLength){
        printf("%02x               ",i);
        Disassemble(buffer,&opcodeLength);
        buffer += opcodeLength;
    }
}
