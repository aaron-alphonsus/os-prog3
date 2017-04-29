// http://courses.teresco.org/cs432_f02/lectures/17-files/17-files.html

#include <algorithm>
// #include <iostream>
#include <vector>

#include "disk_sched.h"

using namespace std;

int look(int initial_pos, int request[REQUESTS])
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
    /// Sort 'down' in descending order and 'up' in ascending
    sort(down.rbegin(), down.rend());
    sort(up.begin(), up.end()); 

    if(initial_pos < 0)
    {
        /// Service the 'down' array
        for(int i = 0; i < down.size(); i++)
        {
            head_movement += abs(current_pos - down[i]);
            current_pos = down[i]; 
        }
        /// Service 'up' array
        for(int i = 0; i < up.size(); i++)
        {
            head_movement += abs(current_pos - up[i]);
            current_pos = up[i];
        }     
    }
    else
    {
        /// Service 'up' array
        for(int i = 0; i < up.size(); i++)
        {
            head_movement += abs(current_pos - up[i]);
            current_pos = up[i];
        } 
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
