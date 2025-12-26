# Exectable formats

Binary files made for running programms are encoded into a specific format. There are two main formats out there :

- **ELF**, or Executable and Linkable Format, the default format for any UNIX system
- **PE**, or Portable Executable is the standard for Windows 

# Principles

All formats share the same global rules. They are structured in 3 main parts :

- the **headers**, define the informations about the executable, such as the format and the entry point. Used by the OS to understand how to read and run the file
- **code section** (`.text`) : where the assembly instructions are written and where the code resides
- **data section** (`.data`, `.rodata`): all data such as strings, global variables and more 

When a programm is loaded, the OS will read each section and load a copy of it in the memory.

# `ELF` format

`ELF` is considered as the standard format for any UNIX systems, and is used in many systems from PlayStation to Solaris.

`ELF` is structuted in 3 parts :

1. **header 1** : details for execution
   1. **ELF header** : identify the architecture, and identify the ELF
   2. **programm header** : informations for running the programm
2. **sections** : main content 
   1. **code** : all code 
   2. **data** : variables (strings, global variables etc)
3. **header 2** (ignored for execution): details for linking, used for compilation 

> [!TIP]
> All `ELF` files start with a *magic* of `ox7f E L F`. 


![struct of ELF](https://raw.githubusercontent.com/corkami/pics/28cb0226093ed57b348723bc473cea0162dad366/binary/elf101/elf101-64.svg)

## Inspecting headers 

To inspect headers of an ELF file, we can use `readelf -h` or `objdump -x`. For example, this is the header of a basic hello world programm written in C, compiled with gcc on 64 bit arch :

```
➜ readelf -h hello_world
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1 (current)
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Position-Independent Executable file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x1
  Entry point address:               0x1060
  Start of program headers:          64 (bytes into file)
  Start of section headers:          13984 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         13
  Size of section headers:           64 (bytes)
  Number of section headers:         31
  Section header string table index: 30
```

We can see for example the OS, the cpu used for compilation, the entry points and the addresses from differents sections. 

# `PE` format

`PE` is the format of the majority of executable in DOS, such as `.exe`, `.dll` and `.sys`. It is much more complex than `ELF` (because Windows). 

> [!TIP]
> The *magic* starts with `PE` is `M Z`, for Mark Zbiwoski an architect of MS-DOS


## Ressources 

- [Ange Albertini's posters](https://github.com/corkami/pics)