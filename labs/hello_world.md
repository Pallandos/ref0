# Lab1 : Hello World!

For this first lab, i will use **Ghidra** to analyze the most easy programm : hello_world on `C`.

Given the following source code :

```c
#include <stdio.h>

int main(){
    printf("Hello, world!");
    return 0;
}
```

We will first compile it with `gcc` with :

    gcc -o hello_world hello_world.c

In ghidra, we can import the binary and analyze it. 

## Header

First, we can see the header at the very top of the binary :

    Elf64_Phdr_ARRAY_00100040

`Elf` stands for Executable and Linkable Format, and is the main binary format for all UNIX systems (except MacOs). The `64` is because of the arch (64 bits) of the computer. 

## Function 

On the left side of ghidra's UI, we can find a *Functions* menu, and there we can find our `main` function. Note that this menu is just a tool to find the function inside the binary.  

To define a function, Elf uses `[address] <function>`. This is how Ghidra can find all the functions. Lets analyze the code of our *main* function, which i cleaned a bit.  

```asm
ENDBR64
PUSH       RBP
MOV        RBP,RSP
LEA        RAX,[s_Hello,_world!_00102004]                   
MOV        RDI=>s_Hello,_world!_00102004,RAX               
MOV        EAX,0x0
CALL       <EXTERNAL>::printf                           
MOV        EAX,0x0
POP        RBP
RET
```

### Step by step analysis

- `ENDBR64` : this instruction is a security feature, starting every function. If a jump is called to a destination with no `ENDBRxx`, the programm will terminate and raise an error. It is used to prevent from some flow attacks
- `PUSH RBP` : save the state of rbp by pushing it into the stack
- `MOV RBP,RSP` : set the value of rbp to the one of rsp
- `LEA RAX,[s_Hello,_world!_00102004]` : this instruction is improved by ghidra, because it is actually `LEA RAX,[0x00102004`. `LEA` computes the value of the second operand (here a memory address) and load it into the first operand (a general purpose register). And if we look at `0x00102004`, we will see `Hello, world!`.
- `MOV RDI,RAX` : set the value of rdi to the one of rax (which is a pointer to `Hello, world!` because of the previous instruction). Note that rdi is the register of the first argument of a call
- `MOV EAX,0x0` : set the value of eax to 0
- `CALL <EXTERNAL>::printf` : this instruction is in reality `CALL 1050`. It will call the procedure starting at `1050`. If we look there, we can see that this define the `printf` function. With this call, the function will look at the argument register (rdi) and execute the call. This will print `Hello, world!`.
- `MOV EAX,0x0` : set the value of eax to 0. As eax (rax) is the return register, it set the return value to `0`.
- `POP RBP` : restore the value of rbp by popping the the stack and setting rbp to the popping value
- `RET` : load the next instruction from the stack. Note that this instruction will **not** return anything, because the return value is already in eax. 