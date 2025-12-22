# Registers 

**Registers** are some very fast, and small memory addresses. They are a limited amount because this is the most expensive type of memory. CPU will use those addresses to execute operations, instead of having to go in the RAM, as it is much faster. 

There are 16 registers in the `x86_64` arch, each one of them is 64 bits long. Because of retro compatibility concerns, each register contains the old versions of registers (32, 16 and 8 bits).

> [!TIP]
> For example, `rax` is the main register, and the 32 first bits can be accessed by `eax`

## Table of all registers

8-byte register | Bytes 0-3 | Bytes 0-1 | Byte 0
--- | --- | --- | ---
`rax` | `eax` | `ax` | `al`
`rcx` | `ecx` | `cx` | `cl`
`rdx` | `edx` | `dx` | `dl`
`rbx` | `ebx` | `bx` | `bl`
`rsi` | `esi` | `si` | `sil`
`rdi` | `edi` | `di` | `dil`
`rsp` | `esp` | `sp` | `spl`
`rbp` | `ebp` | `bp` | `bpl`
`r8`  | `r8d` | `r8w` | `r8b`
`r9` | `r9d` | `r9w` | `r9b`
`r10` | `r10d` | `r10w` | `r10b`
`r11` | `r11d` | `r11w` | `r11b`
`r12` | `r12d` | `r12w` | `r12b`
`r13` | `r13d` | `r13w` | `r13b`
`r14` | `r14d` | `r14w` | `r14b`
`r15` | `r15d` | `r15w` | `r15b`