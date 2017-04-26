//#include <iostream> 
#include <cmath>

#include "disk_sched.h"

using namespace std;

int fcfs(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;
    int current_pos = abs(initial_pos);

    //for(int i = 0; i < 8; i++)
    for(int i = 0; i < REQUESTS; i++)
    {
        head_movement += abs(current_pos - request[i]);
        // cout << "Head movement = " << head_movement << endl;
        current_pos = request[i]; 
    }            

    return head_movement; 
}
