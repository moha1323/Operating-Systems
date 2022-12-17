#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "kernel/pstat.h"
#include "kernel/param.h"
#include "user.h"

int main(){
    struct pstat ps = {0};
    getpinfofunc(&ps);
    int i;
    for(i = 0; i < NPROC; i++){
        fprintf(1, "inuse: %d\tpid: %d\tpriority: %d\thticks: %d\tlticks: %d\ttickets: %d\n", ps.inuse[i], ps.pid[i], ps.priority[i], ps.hticks[i], ps.lticks[i], ps.tickets[i]);
    }
    exit(0);
}