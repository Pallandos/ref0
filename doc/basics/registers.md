# Registers 

**Registers** are some very fast, and small memory addresses. They are a limited amount because this is the most expensive type of memory. CPU will use those addresses to execute operations, instead of having to go in the RAM, as it is much faster. 

There are 16 general purpose registers in the `x86_64` arch, each one of them is 64 bits long. Because of retro compatibility concerns, each register contains the old versions of registers (32, 16 and 8 bits).

> [!TIP]
> For example, `rax` is the main register, and the 32 first bits can be accessed by `eax`

Also, there are special registers : the pointer registers. They can not be modified, (with `MOV`) but are only used with `JMP` etc.

Finally, there are the **flags**, which are 64 1-bits registers, so they are 1 or 0. They are used to store values of operations. 

## General purpose registers

8-byte register | Note on usage | Save type | Bytes 0-3 | Bytes 0-1 | Byte 0
--- | --- |--- | --- | --- | ---
`rax` | Main register, used for the return value of functions | caller-save | `eax` | `ax` | `al`
`rcx` | Used as counter, may be fourth arg | caller-save | `ecx` | `cx` | `cl`
`rdx` | third arg | caller-save | `edx` | `dx` | `dl`
`rbx` | | callee-save | `ebx` | `bx` | `bl`
`rsi` | second arg | caller-save | `esi` | `si` | `sil`
`rdi` | first arg | caller-save | `edi` | `di` | `dil`
`rsp` | *stack* pointer (points to the topmost element) | caller-save | `esp` | `sp` | `spl`
`rbp` | | callee-save | `ebp` | `bp` | `bpl`
`r8`  | fivth arg | caller-save | `r8d` | `r8w` | `r8b`
`r9` | sixth arg | caller-save | `r9d` | `r9w` | `r9b`
`r10` | | caller-save | `r10d` | `r10w` | `r10b`
`r11` | | caller-save | `r11d` | `r11w` | `r11b`
`r12` | | callee-save | `r12d` | `r12w` | `r12b`
`r13` | | callee-save | `r13d` | `r13w` | `r13b`
`r14` | | callee-save | `r14d` | `r14w` | `r14b`
`r15` | | callee-save | `r15d` | `r15w` | `r15b`

> [!WARNING]
> The *Note on usage* column contains facts which are *generally* true, because they are conventional. However, it may be different on some case.

> [!NOTE]
> The *save type* columns indicates if the value is saved across function calls. **caller-save** (volatile) means that the value of the register is not necessarily saved across function calls, and **callee-save** (non volatile) means that they are saved across function calls.

## Pointer registers

`RIP` is the **extended instruction pointer**, it points at the *next* instruction. it is therefore one of the most important register.

8-byte register | Note on usage | Save type | Bytes 0-3 | Bytes 0-1 | Byte 0
--- | --- |--- | --- | --- | ---
`RIP` | Instruction pointer | - | `EIP` | `IP` | -