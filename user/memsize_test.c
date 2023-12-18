#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"


int main(int argc, char* argv[]) {
    //before allocation.
    int size = memsize();
    printf("memSize before allocation: %d \n", size);


    //after allocation.
    void *p = malloc(20000); // Allocate 20K more memory
    int allocSize = memsize();
    printf("memSize after allocation: %d \n", allocSize);
    free(p);

    //after freeing.
    int freeSize = memsize();
    printf("memSize after free: %d \n", freeSize);
    exit(0, "memSize exit");
}