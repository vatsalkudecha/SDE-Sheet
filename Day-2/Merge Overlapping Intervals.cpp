/*
CS-> https://www.codingninjas.com/codestudio/problems/699917?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

LC - 56

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.

-------------------------------
Solution 1: Brute force

Approach:
    First check whether the array is sorted or not.If not sort the array. Now linearly iterate over the array and then check for all of its next intervals whether they are overlapping with the interval at the current index. Take a new data structure and insert the overlapped interval. If while iterating if the interval lies in the interval present in the data structure simply continue and move to the next interval.

TC: O(NlogN)+O(N*N). O(NlogN)
SC : O(n)
Code:

vector < pair < int, int >> merge(vector < pair < int, int >> & arr) {

    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector < pair < int, int >> ans;

    for (int i = 0; i < n; i++) {
        int start = arr[i].first, end = arr[i].second;

        //since the intervals already lies
        //in the data structure present we continue
        if (!ans.empty()) {
            if (start <= ans.back().second) {
                continue;
            }
        }
    
        for (int j = i + 1; j < n; j++) {
            if (arr[j].first <= end) {
                end = arr[j].second;
            }
        }

        ans.push_back({start,end});
    }

    return ans;
}

-------------------------------------
Solution 2: Optimal approach

Approach: 
    Linearly iterate over the array if the data structure is empty insert the interval in the data structure. If the last element in the data structure overlaps with the current interval we merge the intervals by updating the last element in the data structure, and if the current interval does not overlap with the last element in the data structure simply insert it into the data structure.

Intuition: 
    Since we have sorted the intervals, the intervals which will be merging are bound to be adjacent. We kept on merging simultaneously as we were traversing through the array and when the element was non-overlapping we simply inserted the element in our data structure.

TC ->  O(NlogN) + O(N).
SC -> O(1)
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
	int n = intervals.size();
	vector<vector<int>> merged;
	if(n == 0) return merged;
	
	sort(intervals.begin(), intervals.end());


	vector<int> temp = intervals[0];
	// intervals[i][0] = start point of i'th interval
    // intervals[i][1] = finish point of i'th interval
	
	for(int i=1; i<n; i++) {
		if(intervals[i][0] <= temp[1]) {
			temp[1] = max(temp[1], intervals[i][1]);
		}
		else {
			merged.push_back(temp);
			temp = intervals[i];
		}
	}
	merged.push_back(temp);
	return merged;
}