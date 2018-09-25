#include <stdlib.h>
#include "Disassembler/Disassembler.h"
int main(){
    unsigned char buffer[] = {0x00,0x01,0x23,0x24,0x07,0x09,0x02};
    unsigned char * hexBuffer = buffer;
    int bufferLength = 7;
    int opcodeLength = 0;
    for(int i = 0; i<bufferLength;i+=opcodeLength){
        Disassemble(hexBuffer,&opcodeLength);
        hexBuffer += opcodeLength;
    }
}
