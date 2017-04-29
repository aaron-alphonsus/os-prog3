/**
 * @file disk_sched.h
 * 
 * @brief Disk scheduler header file. Contains function prototypes for each disk
 * scheduling algorithm. Also defines number of requests and cylinders.
 *
 * @author Aaron Alphonsus
 *
 * @date 28 April 2017
 */

#ifndef DISK_SCHED_H
#define DISK_SCHED_H

#define REQUESTS 1000
#define CYLINDERS 5000 

/// First Come First Serve 
int fcfs(int initial_pos, int request[REQUESTS]); 

/// Shortest Seek Time First 
int sstf(int initial_pos, int request[REQUESTS]); 

/// SCAN (aka elevator)
int scan(int initial_pos, int request[REQUESTS]); 

/// C-SCAN (Circular-SCAN)
int c_scan(int initial_pos, int request[REQUESTS]); 

/// LOOK
int look(int initial_pos, int request[REQUESTS]); 

/// C-LOOK (Circular-LOOK)
int c_look(int initial_pos, int request[REQUESTS]); 

#endif
