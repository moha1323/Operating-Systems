#include "types.h"
#include "riscv.h"
#include "param.h"
#include "spinlock.h"
#include "defs.h"
#include "pstat.h"
#include "proc.h"

int 
processinfo(uint64 addr){
    struct proc *p = myproc();
    struct pstat info;
    int n = 0;
    while(n < NPROC){
        info.pid[n] = p->pid;
        info.hticks[n] = p->hticks;
        info.lticks[n] = p->lticks;
        info.priority[n] = p->priority;
        info.tickets[n] = p->tickets;
        n++;
    }

    if(copyout(p->pagetable, addr, (char *)&info, sizeof(info)) < 0){
        return -1;
    }
    
    return 0;
}