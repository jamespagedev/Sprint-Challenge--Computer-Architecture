#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu
{
  // TODO
  // PC
  unsigned char PC;
  // registers (array)
  // 8 general-purpose 8-bit numeric registers R0-R7.
  unsigned char registers[8];
  // ram (array)
  // The LS-8 has 8-bit addressing, so can address 256 bytes of RAM total.
  unsigned char ram[256];

  // Sprint
  // flag mask used 00000LGE
  // L = less-than
  // G = greater-than
  // E = equal
  unsigned char FL;
};

// ALU operations
enum alu_op
{
  ALU_MUL,
  // Add more here
  ALU_ADD,

  // Sprint
  ALU_CMP_L,
  ALU_CMP_G,
  ALU_CMP_E,

  // Sprint (Stretch)
  ALU_AND,
  ALU_OR,
  ALU_XOR
};

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

#define LDI 0b10000010
#define HLT 0b00000001
#define PRN 0b01000111
#define MUL 0b10100010
#define ADD 0b10100000
#define POP 0b01000110
#define PUSH 0b01000101
#define CALL 0b01010000
#define RET 0b00010001

// Sprint IR's
#define CMP 0b10100111
#define JMP 0b01010100
#define JEQ 0b01010101
#define JNE 0b01010110

// Sprint (Stretch)
#define AND 0b10101000
#define OR 0b10101010
#define XOR 0b10101011

// TODO: more instructions here. These can be used in cpu_run().
#define SP 7

// Function declarations

extern void cpu_load(struct cpu *cpu, char *file);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
