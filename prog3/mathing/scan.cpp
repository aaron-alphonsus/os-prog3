#include <algorithm>
//#include <iostream> //comment out

#include "disk_sched.h"

// using namespace std; // comment out

int scan(int initial_pos, int request[REQUESTS])
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

    if(initial_pos < 0 && highest <= abs(initial_pos))
        head_movement = abs(initial_pos) - lowest;
    else if(initial_pos < 0 && highest > abs(initial_pos))
        head_movement = abs(initial_pos) + highest;
    else if(initial_pos >= 0 && lowest >= abs(initial_pos))
        head_movement = highest - abs(initial_pos);
    else if(initial_pos > 0 && lowest < abs(initial_pos))
        head_movement = ((CYLINDERS - 1) - abs(initial_pos)) 
                        + ((CYLINDERS - 1) - lowest);   
     
    return head_movement; 
}
