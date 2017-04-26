#include <iostream> //comment out
#include <algorithm>
#include <cmath>

#include "disk_sched.h"

using namespace std; //comment out

int sstf(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;
    int current_pos = abs(initial_pos);

    /// Set shortest seek time to largest value
    int sst = CYLINDERS + 1;
    int st = 0;
    int swap_pos = 0;
    
    /// Duplicate request queue
    int duplicate[REQUESTS];
    for(int i = 0; i < REQUESTS; i++)
        duplicate[i] = request[i];

    // cerr << "Duplicate: ";
    // for(int i = 0; i < REQUESTS; i++)
    //     cerr << duplicate[i] << " ";
    // cerr << "\n";

    for(int i = 0; i < 8; i++)
    //for(int i = 0; i < REQUESTS; i++)
    {
        //cerr << "SST = "; 
        for(int j = i; j < 8; j++)
        {
            //cerr << sst << " ";
            st = abs(current_pos - duplicate[j]);
            // cerr << "st = " << st << " ";
            if(st < sst)
            {
                sst = st;
                swap_pos = j;
            } 
        }
        //cerr << "sst = " << sst << " swap pos = " << swap_pos << endl;
        //cerr << "\n";
        /// Swap shortest seek time to the front
        swap(duplicate[i], duplicate[swap_pos]);
        //duplicate[i] = duplicate[i] + duplicate[swap_pos];  
        // cerr << duplicate[i];
        //duplicate[swap_pos] = duplicate[i] - duplicate[swap_pos]; 
        //duplicate[i] = duplicate[i] - duplicate[swap_pos]; 

        // cerr << "Duplicate: ";
        // for(int j = i; j < 8; j++)
        //     cerr << duplicate[j] << " ";
        // cerr << "\n";

                
        head_movement += sst;
        // // cerr << "Head movement = " << head_movement << endl;
        current_pos = duplicate[i]; 
        sst = CYLINDERS + 1;
    }            

    return head_movement;    
}
