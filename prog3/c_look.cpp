#include <algorithm>
// #include <iostream> //comment out

#include "disk_sched.h"

// using namespace std; // comment out

int c_look(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;    
    
    // int lowest = CYLINDERS;
    // int lowest_high = CYLINDERS;
    // int highest = -1;
    // int highest_low = -1;

    // for(int i = 0; i < REQUESTS; i++)
    // {
    //     if(request[i] < lowest)
    //         lowest = request[i];
    //     if(request[i] > abs(initial_pos) && request[i] < lowest_high)
    //         lowest_high = request[i];
    //     if(request[i] > highest)
    //         highest = request[i];  
    //     if(request[i] < abs(initial_pos) && request[i] > highest_low)
    //         highest_low = request[i];        
    // }
    // // cerr << "Lowest = " << lowest;
    // // cerr << "Highest = " << highest;
    // // cerr << "Lowest high = " << lowest_high;
    // // cerr << "Highest low = " << highest_low;

    // if(initial_pos < 0 && highest <= abs(initial_pos))
    //     head_movement = abs(initial_pos) - lowest;
    // else if(initial_pos < 0 && highest > abs(initial_pos))
    //     head_movement = abs(initial_pos) + ((CYLINDERS - 1) - lowest_high);  
    // else if(initial_pos >= 0 && lowest >= abs(initial_pos))
    //     head_movement = highest - abs(initial_pos);
    // else if(initial_pos > 0 && lowest < abs(initial_pos))
    //     head_movement = ((CYLINDERS - 1) - abs(initial_pos)) + highest_low;   
    
    return head_movement; 
}
