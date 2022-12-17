#include "types.h"
#include "riscv.h"
#include "param.h"
#include "spinlock.h"
#include "defs.h"
#include "pstat.h"
#include "proc.h"

int
getpinfo(uint64 addr)
{
   struct proc *p = myproc();
   struct pstat ps;

   ps.inuse[0] = inuse();
   ps.pid[0] = p->pid;
   ps.hticks[0] = hticks();
   ps.lticks[0] = lticks();
   ps.priority[0] = priority();
   ps.tickets[0] = tickets();

   if(copyout(p->pagetable, addr, (char *)&ps, sizeof(ps)) < 0){
    return -1;
   }

   return 0;
}

   // int i;
   // for(i = 0; i < NPROC; i++){
   //    ps.inuse[i] = inuse();
   //    ps.pid[i] = p->pid;
   //    ps.hticks[i] = hticks();
   //    ps.lticks[i] = lticks();
   //    ps.priority[i] = priority();
   //    ps.tickets[i] = tickets();
   //    fprintf(1,"inuse: %d\tpid: %d\thticks: %d\tlticks: %d\tpriority: %d\ttickets: %d\n", ps.inuse[i], ps.pid[i], ps.hticks[i], ps.lticks[i], ps.priority[i], ps.tickets[i]);
   // }