#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/fcntl.h"
#include "user.h"

#define NULL ((void *)0)

int main(int argc, char *argv[]){

    int *p = NULL;
    fprintf(1,"Null Pointer Value: %p\n", *p);
    
    exit(0);
}