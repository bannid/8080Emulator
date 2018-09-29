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
    cpu.pc = 0x00;
    //Todo: Refactor this
    while(1){
    	cpu.pc += Decoder(&cpu);
    }
}

int Decoder(struct State8080 * cpu){
	int opcodeLength = 0;
    printf("%04x         ",cpu->pc);
	switch(cpu->memory[cpu->pc]){
		case 0x00:{
            PrintStringWithNewLine("NOP Executed");
            opcodeLength = 1;
			break;
		}
        case 0x05:{
            PrintStringWithNewLine("DCR B executed");
            cpu->b--;
            SetFlags(1,(void*)cpu->b,cpu);
            opcodeLength = 1;
            break;
        }
        case 0x06:{
            PrintStringWithNewLine("MVI B executed");
            cpu->b = cpu->memory[cpu->pc + 1];
            opcodeLength = 2;
            break;
        }
        case 0x0e:{
            PrintStringWithNewLine("MVI C, D8 Executed");
            cpu->c = cpu->memory[cpu->pc + 1];
            opcodeLength = 2 ;
            break;
        }
        case 0x11:{
            PrintStringWithNewLine("LXI D executed");
            cpu->d = cpu->memory[cpu->pc + 2];
            cpu->e = cpu->memory[cpu->pc + 1];
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
            cpu->h = cpu->memory[cpu->pc + 2];
            cpu->l = cpu->memory[cpu->pc + 1];;
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
        case 0x26:{
            PrintStringWithNewLine("MVI H, D8 Executed");
            cpu->h = cpu->memory[cpu->pc + 1];
            opcodeLength = 2;
            break;
        }
        case 0x29:{
            PrintStringWithNewLine("DAD H Executed");
            uint16_t combinedHL = ((cpu->h & 0xff) << 8) | cpu->l;
            uint32_t resultAs32Bits = combinedHL + combinedHL;
            uint16_t resultAs16Bits = combinedHL + combinedHL;
            if(resultAs32Bits > 0xffff){
                cpu->flags.cy = 1;
            }
            else {
                cpu->flags.cy = 0;
            }
            cpu->h = resultAs16Bits & 0xff00;
            cpu->l = resultAs16Bits & 0xff;
            opcodeLength = 1;
            break;
        }
        case 0x31:{
            PrintStringWithNewLine("LXI SP Executed");
            cpu->sp = CalculateAddress(cpu->memory[cpu->pc + 2],cpu->memory[cpu->pc + 1]);
            opcodeLength = 3;
            break;
        }
        case 0x36:{
            PrintStringWithNewLine("MVI M, D8 Executed");
            uint16_t address = CalculateAddress(cpu->h,cpu->l);
            cpu->memory[address] = cpu->memory[cpu->pc + 1];
            opcodeLength = 2;
            break;
        }
        case 0x6f:{
            PrintStringWithNewLine("MVI L, A Executed");
            cpu->l = cpu->a;
            opcodeLength = 1;
            break;
        }
        case 0x77:{
            PrintStringWithNewLine("MOV M, A Executed");
            uint16_t address = CalculateAddress(cpu->h,cpu->l);
            cpu->memory[address] = cpu->a;
            opcodeLength = 1;
            break;
        }
        case 0x7c:{
            PrintStringWithNewLine("MOV A, H Executed");
            cpu->a = cpu->h;
            opcodeLength = 1;
            break;
        }
        case 0xc2:{
            PrintStringWithNewLine("JNZ Executed");
            if(cpu->flags.z == 0){
                uint16_t address = CalculateAddress(cpu->memory[cpu->pc + 2],cpu->memory[cpu->pc + 1]);
                cpu->pc = address;
            }
            else{
                opcodeLength = 3;
            }
            break;
        }
        case 0xc3:{
            PrintStringWithNewLine("JMP Executed");
            uint16_t jmpAddress = CalculateAddress(cpu->memory[cpu->pc + 2],cpu->memory[cpu->pc + 1]);
            cpu->pc = jmpAddress;
            break;
        }
        case 0xc9:{
            PrintStringWithNewLine("RET executed");
            uint16_t address = CalculateAddress(cpu->memory[cpu->sp + 1],cpu->memory[cpu->sp]);
            cpu->sp += 2;
            cpu->pc = address;
            break;
        }
        case 0xcd:{
            PrintStringWithNewLine("CALL executed");
            //In call opcode, we would not change the opcodeLength variable
            
            //Todo: We dont need this calculation
            uint16_t calledAddress = CalculateAddress(cpu->memory[cpu->pc + 2],cpu->memory[cpu->pc + 1]);
            uint16_t returnAddress = cpu->pc + 3;
            cpu->memory[cpu->sp - 1] = (returnAddress & 0xff00) >> 8;
            cpu->memory[cpu->sp - 2] = returnAddress & 0xff;
            cpu->sp -= 2;
            cpu->pc = calledAddress;
            break;
        }
        case 0xd5:{
            PrintStringWithNewLine("PUSH D Executed");
            cpu->memory[cpu->sp - 2] = cpu->e;
            cpu->memory[cpu->sp - 1] = cpu->d;
            cpu->sp -= 2;
            opcodeLength = 1;
            break;
        }
        case 0xe5:{
            PrintStringWithNewLine("PUSH H Executed");
            cpu->memory[cpu->sp - 2] = cpu->l;
            cpu->memory[cpu->sp - 1] = cpu->h;
            cpu->sp -= 2;
            opcodeLength = 1;
            break;
        }
        case 0xfe:{
            PrintStringWithNewLine("CPI D8 Executed");
            uint8_t result = cpu->a - cpu->memory[cpu->pc + 1];
            SetFlags(1,(void*)result,cpu);
            opcodeLength = 2;
            break;
        }
		default:{
            //Todo: Once we have implemented all the instructions,
            //we have to remove this function from the default.
			InstructionNotImplemented(cpu->memory[cpu->pc]);
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
            exit(0);
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