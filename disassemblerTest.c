#include <stdlib.h>
#include <stdio.h>
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
    unsigned char * hexBuffer = buffer;
    int opcodeLength = 0;
    for(int i = 0; i<fileSize;i+=opcodeLength){
        Disassemble(hexBuffer,&opcodeLength);
        hexBuffer += opcodeLength;
    }
}
