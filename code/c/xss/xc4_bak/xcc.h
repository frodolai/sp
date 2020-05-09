#ifndef __XCC_H__
#define __XCC_H__

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>
#include <fcntl.h>

// tokens and classes (operators last and in precedence order) (按優先權順序排列)
enum { // token : 0-127 直接用該字母表達， 128 以後用代號。
  Num = 128, Fun, Sys, Glo, Loc, Id,
  Char, Else, Enum, If, Int, Return, Sizeof, While,
  Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt, Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak
};

// types (支援型態，只有 int, char, pointer)
enum { CHAR, INT, PTR };

// 因為沒有 struct，所以使用 offset 代替，例如 id[Tk] 代表 id.Tk (token), id[Hash] 代表 id.Hash, id[Name] 代表 id.Name, .....
// identifier offsets (since we can't create an ident struct)
enum { Tk, Hash, Name, Class, Type, Val, HClass, HType, HVal, Idsz }; // HClass, HType, HVal 是暫存的備份 ???

// opcodes (機器碼的 op)
enum { LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,
       OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,
       OPEN,READ,CLOS,PRTF,MALC,FREE,MSET,MCMP,EXIT };

#define OPS "LEA ,IMM ,JMP ,JSR ,BZ  ,BNZ ,ENT ,ADJ ,LEV ,LI  ,LC  ,SI  ,SC  ,PSH ,"\
            "OR  ,XOR ,AND ,EQ  ,NE  ,LT  ,GT  ,LE  ,GE  ,SHL ,SHR ,ADD ,SUB ,MUL ,DIV ,MOD ,"\
            "OPEN,READ,CLOS,PRTF,MALC,FREE,MSET,MCMP,EXIT,"

int xvm_main(int *pc, int argc, char *argv[]);
extern int debug;
extern char *data;   // data/bss pointer (資料段機器碼指標)
extern int *code;    // ccc: add *code (程式段)
extern int *sym;     // symbol table (simple list of identifiers) (符號表)
#define poolsz 256*1024

#endif