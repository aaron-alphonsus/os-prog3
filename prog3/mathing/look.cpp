#include <algorithm>
// #include <iostream> //comment out

#include "disk_sched.h"

using namespace std; 

int look(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;    
    
    int lowest = CYLINDERS;
    int highest = -1;
   
    for(int i = 0; i < REQUESTS; i++)
    {
        if(request[i] < lowest)
            lowest = request[i];
        if(request[i] > highest)
            highest = request[i];     
    }
    // cerr << "Lowest = " << lowest;
    // cerr << "Highest = " << highest;
    // cerr << "Lowest high = " << lowest_high;
    // cerr << "Highest low = " << highest_low;

    head_movement = min(abs(abs(initial_pos)-lowest), 
                        abs(abs(initial_pos)-highest)) + (highest - lowest);

    return head_movement; 
}
