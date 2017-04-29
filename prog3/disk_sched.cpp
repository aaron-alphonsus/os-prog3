/**
 * @file disk_sched.cpp
 *
 * @brief Main file for the Disk-Scheduling Algorithms. 
 *
 * Creates request array and reads in initial disk head position. Passes these 
 * values into each function. 
 *  
 * Compilation Instructions: make 
 * 
 * Run: ./disk_sched initial_position
 *
 * @author Aaron Alphonsus
 * 
 * @date 28 April 2017 
 */

#include <iostream>
#include <stdlib.h>

#include "disk_sched.h"

using namespace std;

/**
 * Creates an array of random requests, and takes in initial disk head position 
 * from the command line. These are passed to each of the disk scheduling 
 * functions. The head movement for each function is printed out.
 *
 * @param[in] argc Integer count of the command-line arguments 
 * @param[in] argv Vector of the command-line arguments
 * 
 * @return 0 Indicates normal termination of main.
 */
int main(int argc, char *argv[])
{
    /// Check for correct number of command-line arguments
    if (argc != 2)
    {
        cout << "Usage: ./disk_sched initial_position" << endl;
        exit(0);
    }
    
    /// Read in initial disk head position
    int initial_pos = 0; 
    initial_pos = atoi(argv[1]); 
    if (initial_pos <= -1*CYLINDERS || initial_pos >= CYLINDERS)
    {
        cout << "Enter an initial position below " << CYLINDERS << " , using +";
        cout << " or - to indicate the initial direction of the movement of ";
        cout << "the disk head." << endl;
        exit(1);
    }        
    
    /// Array to hold random cylinder requests
    int request[REQUESTS];

    /// Seed random number generator
    srandom((unsigned) time(NULL));

    /// Fill with rand mod number of cylinders
    for (int i = 0; i < REQUESTS; i++)
        request[i] = rand() % CYLINDERS; 

    /// Print results
    cout << "Total head movement required by each algorithm:" << endl;
    cout << "FCFS: " << fcfs(initial_pos, request) << endl;
    cout << "SSTF: " << sstf(initial_pos, request) << endl;
    cout << "SCAN: " << scan(initial_pos, request) << endl;
    cout << "C-SCAN: " << c_scan(initial_pos, request) << endl;
    cout << "LOOK: " << look(initial_pos, request) << endl;
    cout << "C-LOOK: " << c_look(initial_pos, request) << endl;

    return 0;
}
