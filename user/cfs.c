#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void process_work(int sleep_time, int stime2) {
    for (int i = 0; i < 10000000; i++) {
        if (i % 100000 == 0) {
            sleep(sleep_time);
        }
    }
    int pid = getpid();
    int cfs_priority;
    int rtime;
    int retime;
    int stime;
    get_cfs_stats(pid, &cfs_priority, &rtime, &retime, &stime);
    sleep(stime2);
    printf("The process id is: %d, cfs_priority: %d, rtime: %d, retime: %d, stime: %d \n", pid, cfs_priority,
           rtime, retime, stime);
}

void main() {

    int pid1 = fork();
    if (pid1 == 0) {
        set_cfs_priority(0);
        process_work(1,15);
    } else {
        int pid2 = fork();
        if (pid2 == 0) {
            set_cfs_priority(1);
            process_work(1,10);
        } else {
            int pid3 = fork();
            if (pid3 == 0) {
                set_cfs_priority(2);
                process_work(1,5);
            } else {
                wait(0,"");
                wait(0,"");
                wait(0,"");
                exit(0,"");
            }
        }
    }
}
