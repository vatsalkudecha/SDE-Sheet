/*
CS-> https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
GFG-> https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
---------------------------------------------
Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
________________________________________________________________________________

Initial Thought Process:-
    Say if you have two meetings, one which gets over early and another which gets over late. Which one should we choose?  If our meeting lasts longer the room stays occupied and we lose our time. 
    
    On the other hand, if we choose a meeting that finishes early we can accommodate more meetings. Hence we should choose meetings that end early and utilize the remaining time for more meetings.

Approach: 

    To proceed we need a vector of three quantities: the starting time, ending time, meeting number. Sort this data structure in ascending order of end time. 

    Initially, the answer is 1 because the first meeting can always be performed. Make another variable, say limit that keeps track of the ending time of the meeting that was last performed. Initially set limit as the end time of the first meeting.

    Start iterating from the second meeting. At every position we have two possibilities:-

    If the start time of a meeting is  strictly greater than limit we can perform the meeting. Update the answer.Our new limit is the ending time of the current meeting  since it was last performed.Also update limit.  
    
    If the start time is less than or equal to limit  ,skip and move ahead. 

Time Complexity: 
    O(n) to iterate through every position and insert them in a data structure. O(n log n)  to sort the data structure in ascending order of end time. O(n)  to iterate through the positions and check which meeting can be performed.

Overall : O(n) +O(n log n) + O(n) ~O(n log n)

Space Complexity: 
    O(n)  since we used an additional data structure for storing the start time, end time, and meeting no.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct meeting {
   int st;
   int en;
   int pos;
};

bool comparator(struct meeting m1, struct meeting m2) {
    if(m1.en < m2.en) return true;
    else if(m1.en > m2.en) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    
    vector<int> ans;
    
    // creating an array of size n, to store 
    // start, end, pos+1
    struct meeting meet[n];
    
    for(int i= 0; i < n; i++) {
        meet[i].st = start[i];
        meet[i].en = end[i];
        meet[i].pos = i+1;
    }
    // sorting according to their end values
    sort(meet, meet + n, comparator);
    
    int limit = meet[0].en;
    
    ans.push_back(meet[0].pos);
    
    for(int i = 1; i < n; i++) {
        // end time of prev meeting is less than start time of cur meeting
        // so current meeting can take place
        if(limit < meet[i].st) {
            ans.push_back(meet[i].pos);
            limit = meet[i].en;
        }
    }
    return ans;
}