# *stack* and *heap* memory

When a programm is running, it requires memory. There are two main types of memory : the **stack** and the **heap**. Each programm has its memory layout, consisting of various segments. Those segments include :

- `stack`
- `heap`
- `data` : stores global variables
- `text` : stores the code 

![memory layout](/doc/lib/img/Memory_Layout.jpg)
> Memory layout of a program

We will explore in depth how does the stack and the heap behave. 

# The `stack`

The stack, or *execution stack*, *call stack* or just *stack* is one of the most important data structure in computer science, and in reverse engineering. Its main goal is to keep track of the point where the program has to return avec executing a subroutine. 

The `stack` is a **LIFO** (Last In First Out) data structure, which means that we can only access the last added element, as in a stack of book. Therefore, adding an element is done by adding it on the top. 

The top of the stack is located with a register : `RSP`. This register stires a pointer to the top of the stack, and it cannot be modified unless using the instructions to *pop* (remove) and *push* (add) elements to the stack.

In assembly, it is done with two instructions :

- `PUSH X` : **decrement** the stack pointer and add the value of the operand `X` at the top of the stack
- `POP X` : load the value of top of the stack to the operand `X` and **increment** the stack pointer

> [!WARNING]
> The stack grows **backward** : its top most element has a lowest memory address than the deepest. For example `0x7FFFFFF` is the first element and `0xFFFFFFE` is the last. 

So we can find various type of data in the stack, including :

- local variables and primitives types
- return address

## Local variables in the stack

When a variable is created inside a function (subroutine) it is generally alocated on the stack. For primitives types such as `int`, `char`, `bool`, their value is written directly in the stack. This is why their value do not persist outside of their function. **Pointers** are allocated in the stack but their value is in the **heap**.

For example if you do `char *ptr = malloc(100)`, the pointer `ptr` will be in the stack, but pointing to somewhere in the stack. 

## return address 

This is a really important concept for reverse engineering as it is the base of *stack overflow* attacks. When a function or a program calls a subroutine, the **return address** is stored in the stack. This is a pointer to an instruction in the `.text` section. This is where the execution will be restored after completing the subroutine.  

Also, the `rbp` register can be added into the stack. Its purpose is to store the current *stackframe*, to be able to restore it later.

# The `heap`

The `heap` is much more easier, but also more slower because it is managed by the programmer. When a programm requires large amount of memory, it is allocated in the heap. There is no order in the heap and any values can be accessed, regardless of the order they where added. 

> [!WARNING]
> Unlike the stack, the *heap* grows upward.

> [!CAUTION]
> The heap is not temporary. Therefore, is there are no `free` the values are kept stored, even after execution, resulting to *memory leaks*. 