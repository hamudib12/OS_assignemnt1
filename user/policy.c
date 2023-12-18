#include "kernel/param.h"
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"
#include "kernel/syscall.h"
#include "kernel/memlayout.h"
#include "kernel/riscv.h"

// Iterative function to implement `atoi()` function in C
int atoi1(const char S[])
{
    int num = 0;
    int i = 0, sign = 1;

    if (S[i] == '+' || S[i] == '-')
    {
        if (S[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (S[i] && (S[i] >= '0' && S[i] <= '9'))
    {
        num = num * 10 + (S[i] - '0');
        i++;
    }

    return sign * num;
}

int main( int argc, char *argv[]) {
    if(argc < 0 || argc > 2) {
        printf("ERROR!!");
        exit(1, "You did not give the specific amount of arguments");
    }
    int sched_pol = atoi1(argv[1]);
    int ans = set_policy(sched_pol);
    if(ans == -1){
        printf("ERROR!!");
        exit(1, "Error while performing the system call");
    }
    exit(0, "Success!!");
}