/**
 * @file scan.cpp
 *
 * @brief Simulates the SCAN scheduling algorithm. 
 *
 * Simulates the SCAN algorithm and returns total amount of head movement 
 * required by the algorithm.
 *   
 * @author Aaron Alphonsus
 * 
 * @date 28 April 2017 
 */

#include <algorithm>
#include <vector>

#include "disk_sched.h"

using namespace std;

/**
 * Simulates the SCAN algorithm. Function creates two arrays: for requests 
 * less than the initial head position, and for requests greater. The order in
 * which they are processed depends on the initial direction of the disk head.
 * The algorithm makes sure the SCAN changes directions at each end by appending
 * a 0 or CYLINDER-1 as the case may be. 
 * 
 * @param[in] initial_pos Initial disk head position
 * @param[in] request The random request array generated
 * 
 * @return total amount of head movement
 */
int scan(int initial_pos, int request[REQUESTS])
{
    vector<int> down;
    vector<int> up;

    int head_movement = 0;
    int current_pos = abs(initial_pos);
    
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
    
    /// If the head is moving left initially
    if(initial_pos < 0)
    {
        /// SCAN goes down to 0 (as long as the up array is not empty)
        if(up.size() != 0)
            down.push_back(0);
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
        /// SCAN goes up to last cylinder (as long as down array is not empty)
        if(down.size() != 0)
            up.push_back(CYLINDERS - 1);
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

    return head_movement; 
}
