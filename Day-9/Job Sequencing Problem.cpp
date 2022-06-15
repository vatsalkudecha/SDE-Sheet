/*
CS-> https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=3
GFG-> https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
-----------------------------------------------------------------
Example 1:

Input: N = 4, Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

Output: 2 60

Explanation: The 3rd job with a deadline 1 is performed during the first unit of time .The 1st job is performed during the second unit of time as its deadline is 4.
Profit = 40 + 20 = 60
_______________________________________________________
Solution: Image

Approach:  

    The strategy to maximize profit should be to pick up jobs that offer higher profits. Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 we can perform it anytime between day 1-4, but it is preferable to perform the job on its last day. This leaves enough empty slots on the previous days to perform other jobs.

Basic Outline of the approach:-

    -> Sort the jobs in descending order of profit. 
    -> If the maximum deadline is x, make an array of size x .Each array index is set to -1 initially as no jobs have been performed yet.
    -> For every job check if it can be performed on its last day.
    -> If possible mark that index with the job id and add the profit to our answer. 
    -> If not possible, loop through the previous indexes until an empty slot is found.

Time Complexity: O(N log N) + O(N*M).

    O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are iterating through all N jobs and for every job we are checking from the last deadline, say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed if M is the maximum deadline available.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct format {
   int deadline;
   int profit;
};

bool static comparator(struct format f1,format f2) {
   return f1.profit > f2.profit;
}

int jobScheduling(vector<vector<int>> &jobs)
{
   int n = jobs.size();
    
   struct format job[n];
   for(int i=0;i<n;i++) {
       job[i].deadline = jobs[i][0];
       job[i].profit = jobs[i][1];
   }
   sort(job,job+n,comparator);
    
   int max_deadline = 0;
   for(int i=0; i<n; i++) {
       max_deadline = max(max_deadline,job[i].deadline);
   }
   vector<int> filled(max_deadline+1, -1);

   int jobProfit = 0;

   for (int i = 0; i < n; i++) {
        for (int j = job[i].deadline; j > 0; j--) {
           if (filled[j] == -1) {
              filled[j] = 0;
              jobProfit += job[i].profit;
              break;
           }
        }
     }

   return jobProfit;
}
