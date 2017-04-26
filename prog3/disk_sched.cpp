#include <iostream>
#include <stdlib.h>

#include "disk_sched.h"

using namespace std;

int main(int argc, char *argv[])
{
    /// Check for correct number of command-line arguments
    if (argc != 2)
    {
        cout << "Usage: ./disk_sched initial-position" << endl;
        exit(0);
    }
    
    /// Read in initial disk head position
    int initial_pos = 0; 
    initial_pos = atoi(argv[1]); 
    if (initial_pos < -5000 || initial_pos > 5000)
    {
        cout << "Enter an initial position below 5000, using + or - to ";
        cout << "indicate the initial direction of the movement of the disk ";
        cout << "head." << endl;
        exit(1);
    }        
    
    /// Array to hold random cylinder requests
    int request[REQUESTS];
    //int request[REQUESTS] = {98, 183, 37, 122, 14, 124, 65, 67}; 

    /// Seed random number generator
    srandom((unsigned) time(NULL));

    /// Fill with rand mod number of cylinders
    for (int i = 0; i < REQUESTS; i++)
        request[i] = rand() % CYLINDERS; 

    // for (int i = 0; i < REQUESTS; i++)
        // cerr << request[i] << "\n"; 

    /// Print results
    cout << "Total head movement required by each algorithm:" << endl;
    cout << "FCFS: " << fcfs(initial_pos, request) << endl;
    cout << "SSTF: " << sstf(initial_pos) << endl;
    cout << "SCAN: " << scan(initial_pos) << endl;
    // cout << "C-SCAN: " << c_scan(initial_pos) << endl;
    // cout << "LOOK: " << look(initial_pos) << endl;
    // cout << "C-LOOK: " << c_look(initial_pos) << endl;

    return 0;
}
