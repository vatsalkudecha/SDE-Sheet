/*
CS-> https://www.codingninjas.com/codestudio/problems/630418?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Lc -> 3

Input: s = ”abcabcbb”
Output: 3
Explanation: The answer is abc with length of 3.
--------------------------------------------------------------------------
Solution 1: Brute force Approach

Approach: 
    This approach consists of taking the two loops one for traversing the string and another loop – nested loop for finding different substrings and after that, we will check for all substrings one by one and check for each and every element if the element is not found then we will store that element in HashSet otherwise we will break from the loop and count it.
_______________________________________________________________________________
Solution 2: Optimised  Approach 1

Approach: 
    We will have two pointers left and right. Pointer ‘left’ is used for maintaining the starting point of substring while ‘right’ will maintain the endpoint of the substring.’ right’ pointer will move forward and check for the duplicate occurrence of the current element if found then ‘left’ pointer will be shifted ahead so as to delete the duplicate elements.

Time Complexity: O( 2*N ) (sometimes left and right both have to travel complete array)
Space Complexity: O(N) where N is the size of HashSet taken for storing the elements
__________________________________________________________________________________

Solution 3: Optimised  Approach 2

Approach: 
    In this approach, we will make a map that will take care of counting the elements and maintaining the frequency of each and every element as a unity by taking the latest index of every element.

Time Complexity: O(N)
Space Complexity: O(N) 
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

// Brute force
/*
int solve(string str) {
  int maxans = INT_MIN;
  for (int i = 0; i < str.length(); i++) // outer loop for traversing the string
  {
    unordered_set < int > set;
    for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
    {
      if (set.find(str[j]) != set.end()) // if element if found so mark it as ans and break from the loop
      {
        maxans = max(maxans, j - i);
        break;
      }
      set.insert(str[j]);
    }
  }
  return maxans;
}
*/

// Sol-2 
/*
int lengthofLongestSubstring(string s) {
    int maxans = INT_MIN;
    unordered_set < int > set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end()) //if duplicate element is found
        {
            while (l < r && set.find(str[r]) != set.end()) {
            set.erase(str[l]);
            l++;
        }
    }
    set.insert(str[r]);
    maxans = max(maxans, r - l + 1);
    }
    return maxans;
}
*/

// Sol-3

int uniqueSubstrings(string s)
{
    int n = s.size();
    int len = 0, left = 0, right = 0;
    // 2 pointers -> sliding window

    /*
        The idea is to scan the string from left to right, 
        keep track of the maximum length Non-Repeating Character Substring
        seen so far in res. When we traverse the string, 
        to know the length of current window we need two indexes. 

        1) Ending index ( j ) : We consider current index as ending index. 
        2) Starting index ( i ) : It is same as previous window 
            -> if current character was not present in the previous window. 
            -> To check if the current character was present in the previous window
            or not, we store last index of every character in an array lasIndex[].
            -> If lastIndex[str[j]] + 1 is more than previous start, 
            then we updated the start index i. Else we keep same i. 

        */
    vector<int> mp(256, -1);
    while(right < n) {
        if(mp[s[right]] != -1) {
            left = max(mp[s[right]] + 1, left);
        }
        mp[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}
