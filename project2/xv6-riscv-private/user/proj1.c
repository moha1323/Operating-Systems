#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user.h"

int
main(){
    fprintf(1,"Total Number of System Calls till now are : %d\n", getsyscallinfo());
    exit(0);
    return 0;
}