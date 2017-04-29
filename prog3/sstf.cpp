/**
 * @file sstf.cpp
 *
 * @brief Simulates the SSTF scheduling algorithm. 
 *
 * Simulates the shortest-seek-time-first algorithm and returns total amount of 
 * head movement required by the algorithm.
 *   
 * @author Aaron Alphonsus
 * 
 * @date 28 April 2017 
 */

//#include <iostream> //comment out
#include <algorithm>
#include <cmath>

#include "disk_sched.h"

using namespace std; //comment out

/**
 * Simulates the shortest-seek-time-first algorithm. Function loops through 
 * requests looking for the request with the shortest seek time. The head 
 * movement is added and the next shortest seek time is found until the request
 * array is exhausted.
 *
 * @param[in] initial_pos Initial disk head position
 * @param[in] request The random request array generated
 * 
 * @return total amount of head movement
 */
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

    for(int i = 0; i < REQUESTS; i++)
    {
        /// Look for request with shortest seek time in remaining request array
        for(int j = i; j < REQUESTS; j++)
        {
            st = abs(current_pos - duplicate[j]);
            if(st < sst)
            {
                sst = st;
                swap_pos = j;
            } 
        }
        /// Swap element with shortest request time to the front
        swap(duplicate[i], duplicate[swap_pos]); 
              
        head_movement += sst; /// Add head movement
        current_pos = duplicate[i]; /// Move current position down
        sst = CYLINDERS + 1; /// Reset shortest seek time
    }            

    return head_movement;    
}
