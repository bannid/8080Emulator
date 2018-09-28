#include "Emulator.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
struct Flags;
struct State8080;
int Decoder(struct State8080*);
void InstructionNotImplemented(uint16_t);
void PrintStringWithNewLine(const char *);
uint16_t CalculateAddress(uint8_t, uint8_t);
uint16_t Parity8Bits(uint8_t);
uint16_t Parity16Bits(uint16_t);
void SetFlags(uint16_t lengthInBytes, void * bytes,struct State8080*);
void PrintFlagsOfCpu(struct State8080*);
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
    uint8_t * pc;
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
    cpu.pc = cpu.memory;
    //Todo: Refactor this
    while(1){
    	cpu.pc += Decoder(&cpu);
    }
}

int Decoder(struct State8080 * cpu){
	//As most opcodes are one byte long,
	//we gonna have opcodeLength defaulted to 1
	int opcodeLength = 0;
	switch(cpu->pc[0]){
		case 0x00:{
            PrintStringWithNewLine("NOP Executed");
            opcodeLength = 1;
			break;
		}
        case 0x05:{
            PrintStringWithNewLine("DCR B executed");
            cpu->b--;
            SetFlags(1,(void*)cpu->b,cpu);
            PrintFlagsOfCpu(cpu);
            opcodeLength = 1;
            break;
        }
        case 0x06:{
            PrintStringWithNewLine("MVI B executed");
            cpu->b = cpu->memory[cpu->pc[1]];
            opcodeLength = 2;
            break;
        }
        case 0x11:{
            PrintStringWithNewLine("LXI D executed");
            cpu->d = cpu->pc[2];
            cpu->e = cpu->pc[1];
            opcodeLength = 3;
            break;
        }
        case 0x13:{
            PrintStringWithNewLine("INX D executed");
            uint16_t address = CalculateAddress(cpu->d,cpu->e);
            address++;
            cpu->d = address >> 8;
            cpu->e = address & 0xff;
            opcodeLength = 1;
            break;
        }
        case 0x1a:{
            PrintStringWithNewLine("LDAX D executed");
            uint16_t address = CalculateAddress(cpu->d,cpu->e);
            cpu->a = cpu->memory[address];
            opcodeLength = 1;
            break;
        }
        case 0x21:{
            PrintStringWithNewLine("LXI H executed");
            cpu->h = cpu->pc[2];
            cpu->l = cpu->pc[1];
            opcodeLength = 3;
            break;
        }
        case 0x23:{
            PrintStringWithNewLine("INX H executed");
            uint16_t address = CalculateAddress(cpu->h,cpu->l);
            address++;
            cpu->h = address >> 8;
            cpu->l = address & 0xff;
            opcodeLength = 1;
            break;
        }
        case 0x31:{
            PrintStringWithNewLine("LXI SP Executed");
            cpu->sp = CalculateAddress(cpu->pc[2],cpu->pc[1]);
            opcodeLength = 3;
            break;
        }
        case 0x77:{
            PrintStringWithNewLine("MOV M, A executed");
            uint16_t address = CalculateAddress(cpu->h,cpu->l);
            cpu->memory[address] = cpu->a;
            opcodeLength = 1;
            break;
        }
        case 0xc2:{
            if(cpu->flags.z == 0){
                uint16_t address = CalculateAddress(cpu->pc[2],cpu->pc[1]);
                cpu->pc = &cpu->memory[address];
            }
            else{
                opcodeLength = 3;
            }
            break;
        }
        case 0xc3:{
            //In jump opcode, we would not change the opocodeLength variable
            PrintStringWithNewLine("JMP Executed");
            uint16_t jmpAddress = CalculateAddress(cpu->pc[2],cpu->pc[1]);
            cpu->pc = &cpu->memory[jmpAddress];
            break;
        }
        case 0xc9:{
            cpu->sp += 2;
            uint16_t address = CalculateAddress(cpu->memory[cpu->sp - 1],cpu->memory[cpu->sp]);
            printf("%02x",address);
            exit(0);
            cpu->pc = &cpu->memory[address];
            break;
        }
        case 0xcd:{
            PrintStringWithNewLine("CALL executed");
            //In call opcode, we would not change the opcodeLength variable
            uint16_t calledAddress = CalculateAddress(cpu->pc[2],cpu->pc[1]);
            cpu->memory[cpu->sp] = cpu->pc[4];
            cpu->memory[(cpu->sp - 1)] = cpu->pc[3];
            cpu->sp = cpu->sp - 2;
            cpu->pc = &cpu->memory[calledAddress];
            break;
        }
		default:{
            //Todo: Once we have implemented all the instructions,
            //we have to remove this function from the default.
			InstructionNotImplemented(*(cpu->pc));
		}
	}
	return opcodeLength;
}
//Helper function to print the string with new line
void PrintStringWithNewLine(const char * string){
    printf(string);
    printf("\n");
}
void InstructionNotImplemented(uint16_t opcode){
	printf("The instruction %02x is not implemented\n",opcode);
	exit(0);
}
uint16_t CalculateAddress(uint8_t high, uint8_t low){
    return (((high & 0xff) << 8) | low);
}

uint16_t Parity8Bits(uint8_t byte){
    byte ^= byte >> 4;
    byte ^= byte >> 2;
    byte ^= byte >> 1;
    return (~byte) & 0x1;
}
uint16_t Parity16Bits(uint16_t bytes){
    bytes ^= bytes >> 8;
    bytes ^= bytes >> 4;
    bytes ^= bytes >> 2;
    bytes ^= bytes >> 1;
    return (~bytes) & 0x1;
}
void SetFlags(uint16_t lengthInBytes, void * bytes, struct State8080 * cpu){
    switch(lengthInBytes){
        case 1:{
            uint8_t bytesAsUint = ((uint8_t)bytes);
            cpu->flags.z = ((bytesAsUint & 0xff) == 0);
            cpu->flags.s = ((bytesAsUint & 0x80) != 0);
            cpu->flags.cy = bytesAsUint > 0xff;
            cpu->flags.p = Parity8Bits(bytesAsUint);
            break;
        }
        case 2:{
            uint16_t bytesAsUint = ((uint16_t)bytes);
            cpu->flags.z = ((bytesAsUint & 0xff) == 0);
            cpu->flags.s = ((bytesAsUint & 0x80) != 0);
            cpu->flags.cy = bytesAsUint > 0xff;
            cpu->flags.p = Parity16Bits(bytesAsUint);
            break;
        }
        default:{
            PrintStringWithNewLine("The length for bytes in function SetFlags is wrong");
            break;
        }
    }
}
void PrintFlagsOfCpu(struct State8080 * cpu){
    printf("Value of z is %02x\n",cpu->flags.z);
    printf("Value of s is %02x\n",cpu->flags.s);
    printf("Value of p is %02x\n",cpu->flags.p);
    printf("Value of cy is %02x\n",cpu->flags.cy);
}