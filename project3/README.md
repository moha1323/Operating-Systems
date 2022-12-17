Name: Yahya Mohamed
Class: ICS 462-50
Title: The Null Pointer and Other Tricks
Institution: Metropolitan State University
Instructor: Mathew Nyamagwa


Project Description:
    Part A: In xv6 dereferencing a null pointer should throw an exception. So we need to locate where and what we should change when a null pointer is dereferenced.
    Part B: In xv6 our address space has the stack at a fixed-sized of one page and has the heap grows towards the high end of the address space. So as explained in class we need to have the heap growing towards the high end of the address space but the stack will be at the end of the address space and growing backwards.

Files Modified: 
~/ICS462/CODE/project3/xv6-riscv-private/kernel/exec.c
   Allocate the first page to sz and then ensure to make the first page inaccesible from the user.

~/ICS462/CODE/project3/xv6-riscv-private/Makefile
    I changed the entry point of the Makefile to 0x1000 also changed the entry point for forktest to 0x1000.
    I added "proj3" user program, the program dereferences a null pointer.


Files Created: 
~/ICS462/CODE/project3/xv6-riscv-private/user/proj3.c
    First, set a pointer to null, dereferences the pointer and returns the pointer. A pointer will not be returned since an exception will be thrown for the dereferenced null pointer.


How To Run:
1. Open Terminal
2. % cd ~/ICS462/CODE/project3/xv6-riscv-private
3. % make
4. % make qemu
5. $ proj3

References and Sources: 
https://www.youtube.com/watch?v=M2CPjjVTmpg