#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

struct pstat {
  int inuse[NPROC];           // whether this slot of the process table is in use (1 or 0)
  int pid[NPROC];             // the PID of each process 
  int hticks[NPROC];          // the number of ticks each process has accumulated at HIGH priority
  int lticks[NPROC];          // the number of ticks each process has accumulated at LOW priority
  int priority[NPROC];        // MLFQ has two queues, HIGH = index 0 & LOW = index 1 in the queue enumerator
  int tickets[NPROC];
};

#endif // _PSTAT_H_