#include <algorithm>
// #include <iostream> // TODO: comment out
#include <vector>

#include "disk_sched.h"

using namespace std;

int c_look(int initial_pos, int request[REQUESTS])
{
    vector<int> down;
    vector<int> up;

    int head_movement = 0;
    int current_pos = abs(initial_pos);
    // cerr << "Current pos = " << current_pos << endl;
    
    /// Place requests into an 'up' and 'down' vector which will be sorted
    for(int i = 0; i < REQUESTS; i++)
    {
        if(request[i] < current_pos)
            down.push_back(request[i]);
        else if(request[i] > current_pos)
            up.push_back(request[i]);
        /// Assumes that == are processed first, therefore 0 head movement
    }   
 
    if(initial_pos < 0)
    {
        /// Sort both up and down in descending order
        sort(down.rbegin(), down.rend());
        sort(up.rbegin(), up.rend());
     
        /// Service the 'down' array
        for(int i = 0; i < down.size(); i++)
        {
            head_movement += abs(current_pos - down[i]);
            current_pos = down[i]; 
        }
        /// Head position wraps around to the highest request in 'up' array
        if(up.size() > 0)
            current_pos = up[0];
        /// Service 'up' array
        for(int i = 0; i < up.size(); i++)
        {
            head_movement += abs(current_pos - up[i]);
            current_pos = up[i];
        }     
    }
    else
    {
        sort(up.begin(), up.end());
        sort(down.begin(), down.end()); 

        /// Service 'up' array
        for(int i = 0; i < up.size(); i++)
        {
            head_movement += abs(current_pos - up[i]);
            current_pos = up[i];
        }
        /// Head position wraps around to the lowest request in 'down' array
        if(down.size() > 0)
            current_pos = down[0]; 
        /// Service the 'down' array
        for(int i = 0; i < down.size(); i++)
        {
            head_movement += abs(current_pos - down[i]);
            current_pos = down[i]; 
        }
    }
    
    // for(int i = 0; i < down.size(); i++)
    //     cerr << down[i] << " ";
    // cerr << "\n";

    // for(int i = 0; i < up.size(); i++)
    //     cerr << up[i] << " ";
    // cerr << "\n";
 
    return head_movement;
}
