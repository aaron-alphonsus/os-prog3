#ifndef DISK_SCHED_H
#define DISK_SCHED_H

#define REQUESTS 1000
#define CYLINDERS 5000 

/// FCFS
int fcfs(int initial_pos, int request[REQUESTS]); 

/// SSTF 
int sstf(int initial_pos); 

/// SCAN
int scan(int initial_pos); 

/// C-SCAN
int c_scan(int initial_pos); 

/// LOOK
int look(int initial_pos); 

/// C-LOOK
int c_look(int initial_pos); 

#endif
