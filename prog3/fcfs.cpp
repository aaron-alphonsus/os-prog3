//#include <iostream> //comment out
#include <cmath>

#include "disk_sched.h"

using namespace std; //comment out 

int fcfs(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;
    int current_pos = abs(initial_pos);

    // cerr << "Current pos = ";
    for(int i = 0; i < 8; i++)
    //for(int i = 0; i < REQUESTS; i++)
    {
        // cerr << current_pos << " ";
        head_movement += abs(current_pos - request[i]);
        // cerr << "Head movement = " << head_movement << endl;
        current_pos = request[i]; 
    }            
    // cerr << "\n";

    return head_movement; 
}
