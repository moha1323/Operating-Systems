#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "pstat.h"

int total_calls = -1; 

uint64
sys_exit(void)
{
  int n;
  if(argint(0, &n) < 0)
    return -1;
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  if(argaddr(0, &p) < 0)
    return -1;
  return wait(p);
}

uint64
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_getsyscallinfo(void)
{
  if (total_calls == -1) return total_calls;
  else return total_calls + 1;
}

//return information about the currently running processes
int
sys_getpinfo(void)
{
  return getpinfo();
}

//takes the inputed number for tickets also gets the current proccess then sets the number of tickets to the current process.
int
sys_settickets(void)
{
  int num;
  struct proc *curproc = myproc();
  argint(0, &num);
  if(num < 1) {
    return -1;
  }

  curproc->tickets = num;

  return 0;
}

//testing
int 
sys_getpinfofunc(void)
{
  // uint64 info;
  // if(argaddr(0, &info) < 0){
  //   return -1;
  // }
  // struct proc *p = myproc();
  // struct pstat ps;
  // ps.inuse[0] = inuse();
  // ps.pid[0] = p->pid;
  // ps.hticks[0] = hticks();
  // ps.lticks[0] = lticks();
  // ps.priority[0] = priority();
  // ps.tickets[0] = tickets();

  // printf("name: %s\tpid: %d\tinuse: %d\thticks: %d\tlticks: \tpriority: %d\ttickets: %d\n", p->name, ps.pid[0], ps.inuse[0], ps.hticks[0], ps.lticks[0], ps.priority[0], ps.tickets[0]);

  // if(copyout(p->pagetable, info, (char *)&ps, sizeof(ps)) < 0){
  //   return -1;
  // }

  // uint64 info;
  // if(argaddr(0, &info) < 0){
  //   return -1;
  // }
  uint64 info;
  if(argaddr(0, &info) < 0){
    return -1;
  }
  return processinfo(info);
}