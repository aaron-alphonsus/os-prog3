#ifndef DISK_SCHED_H
#define DISK_SCHED_H

#define REQUESTS 8
#define CYLINDERS 200 

/// FCFS
int fcfs(int initial_pos, int request[REQUESTS]); 

/// SSTF 
int sstf(int initial_pos, int request[REQUESTS]); 

/// SCAN
int scan(int initial_pos, int request[REQUESTS]); 

/// C-SCAN
int c_scan(int initial_pos, int request[REQUESTS]); 

/// LOOK
int look(int initial_pos, int request[REQUESTS]); 

/// C-LOOK
int c_look(int initial_pos, int request[REQUESTS]); 

#endif
