/**
 * @file fcfs.cpp
 *
 * @brief Simulates the FCFS scheduling algorithm. 
 *
 * Simulates the first-come, first-served algorithm and returns total amount of 
 * head movement required by the algorithm.
 *   
 * @author Aaron Alphonsus
 * 
 * @date 28 April 2017 
 */

#include <cmath>

#include "disk_sched.h"

using namespace std;  

/**
 * Simulates the first-come, first-served algorithm. Function loops through 
 * requests summing up each consecutive head movement.
 *
 * @param[in] initial_pos Initial disk head position
 * @param[in] request The random request array generated
 * 
 * @return total amount of head movement
 */
int fcfs(int initial_pos, int request[REQUESTS])
{
    int head_movement = 0;
    int current_pos = abs(initial_pos);

    /// Loop through requests array summing up differences in head positions
    for(int i = 0; i < REQUESTS; i++)
    {
        head_movement += abs(current_pos - request[i]);
        current_pos = request[i]; 
    }            
    
    return head_movement; 
}
