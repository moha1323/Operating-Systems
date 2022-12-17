Name: Yahya Mohamed
Class: ICS 462-50
Title: xv6 Scheduler
Institution: Metropolitan State University
Instructor: Mathew Nyamagwa


Project Description:
	Build a simple two-level scheduler which first places jobs into the high priority queue. Once a job uses one time slice on the high priority queue, move it to the low priority queue; jobs on the lower-priority queue should run for two time slices before relinquishing the CPU. When there is more than one job on a queue, each should run in proportion to the number of tickets it has; the more tickets a process has, the more it runs. Each time slice, a randomized lottery determines the winner of the lottery; that winning process is the one that runs for that time slice.

Files Modified: 
~/ICS462/CODE/project2/xv6-riscv-private/kernel/syscall.h 
	^ Added the "getpinfo" system call name to the header file.
    ^ Added the "settickets" system call name to the header file.
~/ICS462/CODE/project2/xv6-riscv-private/kernel/defs.h
	^ Added the "getpinfo" function prototype (under proc.c) to the header file.
    ^ Added the "lottery" function prototype (under proc.c) to the header file.
~/ICS462/CODE/project2/xv6-riscv-private/user/user.h
	^ Added the "getpinfo" function prototype (under system calls) to header file. 
    ^ Added the "settickets" function prototype (under system calls) to header file. 
~/ICS462/CODE/project2/xv6-riscv-private/kernel/sysproc.c
	^ Added the "getpinfo" function call to this program.
    ^ Added the "settickets" function call to this program.
~/ICS462/CODE/project2/xv6-riscv-private/user/usys.pl
	^ Added the "getpinfo" system call to the file. 
    ^ Added the "settickets" system call to the file. 
~/ICS462/CODE/project2/xv6-riscv-private/kernel/syscall.c
	^ Added the "getpinfo" function.
    ^ Added the "settickets" function.
~/ICS462/CODE/project2/xv6-riscv-private/kernel/proc.h
    ^ Added properties to struct proc
~/ICS462/CODE/project2/xv6-riscv-private/kernel/proc.c
    ^ Added field "next", changed allocproc(), changed scheduler(), added getpinfo(), added lottery()
~/ICS462/CODE/project2/xv6-riscv-private/kernel/trap.c      
    ^ Changed usertrap() & kerneltrap()
~/ICS462/CODE/project2/xv6-riscv-private/Makefile
	^ Added "getpinfo" user program, the program returns information about the currently running processes.
    ^ Added "proj2" user program, the program creates a child process.

Files Created: 
~/ICS462/CODE/project2/xv6-riscv-private/kernel/pstat.h
    ^ Added a data type declaration for pstat
~/ICS462/CODE/project2/xv6-riscv-private/user/getpinfo.c
	^ The user program that will use "getpinfo" function that will return information about the currently running processes and print it to the console while in the emulator. 
~/ICS462/CODE/project2/xv6-riscv-private/user/proj2.c
	^ The user program that will create a child process displays information on the parent plus the child and uses the "settickets" function that will sets the inputed number of tickets to the current process and print it to the console while in the emulator. 

How To Run:
1. Open Terminal
2. % cd ~/ICS462/CODE/project2/xv6-riscv-private
3. % make
4. % make qemu
5. $ getpinfo
6. $ proj2 &; proj2 &;
7. $ getpinfo

References and Sources: 
https://www.youtube.com/watch?v=oQjolyqfUa8
https://medium.com/@harshalshree03/xv6-implementing-ps-nice-system-calls-and-priority-scheduling-b12fa10494e4
https://www.youtube.com/watch?v=eYfeOT1QYmg&t=1119s