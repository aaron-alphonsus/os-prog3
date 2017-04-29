/**
 * @file look.cpp
 *
 * @brief Simulates the LOOK scheduling algorithm. 
 *
 * Simulates the LOOK algorithm and returns total amount of head movement 
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
 * Simulates the LOOK algorithm. Functionality of the LOOK was unclear regarding
 * direction switching. Used description from here: 
 * http://courses.teresco.org/cs432_f02/lectures/17-files/17-files.html
 * The direction switches once there are no pending requests in that direction.
 *
 * The function creates two arrays: for requests less than the initial head 
 * position, and for requests greater. The order in which they are processed 
 * depends on the initial direction of the disk head. 
 * 
 * @param[in] initial_pos Initial disk head position
 * @param[in] request The random request array generated
 * 
 * @return total amount of head movement
 */
int look(int initial_pos, int request[REQUESTS])
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

    return head_movement;  
}
