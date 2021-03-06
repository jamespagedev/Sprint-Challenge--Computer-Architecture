#ifndef _CPU_HELPERS_H_
#define _CPU_HELPERS_H_

#define DEBUGGER 0 // 0 = off, 1 = on

// Sprint
#define CMP_L 0b00000100
#define CMP_G 0b00000010
#define CMP_E 0b00000001

// ********************************************* helper functions **********************************************
extern unsigned char cpu_ram_read(struct cpu *cpu, unsigned char pc);
extern void cpu_ram_write(struct cpu *cpu, int index, unsigned char binary);
extern void cpu_load_default(struct cpu *cpu);
extern void cpu_load_file(struct cpu *cpu, char *file);
extern void print_binary(const unsigned char dec);
extern void print_ir_bin_hex_dec(const unsigned char ir);
extern void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB);
extern void pop_reg_value(struct cpu *cpu, unsigned char addr, unsigned char value);
extern void push_ram_value(struct cpu *cpu, unsigned char value);

// ***************************************** cpu_run support functions *****************************************
extern void ldi(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void add(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void mul(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void prn(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void pop(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void push(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void call(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void ret(struct cpu *cpu);

// Sprint
extern void cmp(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void jmp(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void jeq(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void jne(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);

// Sprint (Stretch)
extern void alu_and(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_or(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_xor(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_not(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_shl(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_shr(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);
extern void alu_mod(struct cpu *cpu, unsigned char IR, int num_operands, unsigned char *operands);

#endif