#include "/Users/yahyamohamed/xv6-riscv/kernel/types.h"
#include "/Users/yahyamohamed/xv6-riscv/kernel/stat.h"
#include "/Users/yahyamohamed/xv6-riscv/kernel/fcntl.h"
#include "/Users/yahyamohamed/xv6-riscv/user/user.h"

int
main(){
    fprintf(1,"Total Number of System Calls till now are : %d\n", getsyscallinfo());
    exit(0);
    return 0;
}