#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user.h"

int 
main(){
    //settickets(5);
    getpinfo(); //return information about the currently running processes
    exit(0);
}