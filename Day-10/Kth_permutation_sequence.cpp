/*
cs-> https://www.codingninjas.com/codestudio/problems/1112626?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

lc-> 60
-------------------------------------------------------------------
Input: N = 3, K = 3

Output: “213”

Explanation: The sequence has 3! permutations as illustrated in the figure above. K = 3 corresponds to the third sequence.
----------------------------------------------------------------
Solution 1: Brute Force Solution

Approach:

    The extreme naive solution is to generate all the possible permutations of the given sequence.  This is achieved using recursion and every permutation generated is stored in some other data structure (here we have used a vector).
    Finally, we sort the data structure in which we have stored all the sequences and return the Kth sequence from it.

    Code:

        //function to generate all possible permutations of a string
        void solve(string & s, int index, vector < string > & res) {
            if (index == s.size()) {
                res.push_back(s);
                return;
            }
            for (int i = index; i < s.size(); i++) {
                swap(s[i], s[index]);
                solve(s, index + 1, res);
                swap(s[i], s[index]);
            }
        }

    string getPermutation(int n, int k) {
        string s;
        vector < string > res;
        //create string
        for (int i = 1; i <= n; i++) {
            s.push_back(i + '0');
        }
        solve(s, 0, res);
        //sort the generated permutations
        sort(res.begin(), res.end());
        //make k 0-based indexed to point to kth sequence
        auto it = res.begin() + (k - 1);
        return *it;
    }

Time complexity: O(N! * N) +O(N! Log N!)

Reason:  The recursion takes O(N!)  time because we generate every possible permutation and another O(N)  time is required to make a deep copy and store every sequence in the data structure. Also, O(N! Log N!)  time required to sort the data structure

Space complexity: O(N) 

Reason: Result stored in a vector, we are auxiliary space taken by recursion
--------------------------------------------------------------------------------------
Solution 2:(Optimal Approach)

Say we have N = 4  and K = 17. Hence the number sequence is {1,2,3,4}. 

Intuition:

    Since this is a permutation we can assume that there are four positions that need to be filled using the four numbers of the sequence. First, we need to decide which number is to be placed at the first index. Once the number at the first index is decided we have three more positions and three more numbers.  Now the problem is shorter. We can repeat the technique that was used previously until all the positions are filled. The technique is explained below.

Approach:  

STEP 1: (Image-1)

    Mathematically speaking there can be 4 variations while generating the permutation. We can have our permutation starting with either 1 or 2 or 3 or 4. If the first position is already occupied by one number there are three more positions left. The remaining three numbers can be permuted among themselves while filling the 3 positions and will generate 3! = 6 sequences. Hence each block will have 6 permutations adding up to a total of 6*4 = 24 permutations. If we consider the sequences as 0-based and in the sorted form we observe:- 

    The 0th – 5th permutation will start with 1 
    The 6th – 11th permutation will start with 2
    The 12th – 17th permutation will start with 3 
    The 18th – 23rd permutation will start with 4.
    (For better understanding refer to the picture below.) 

    We make K = 17-1 considering 0-based indexing. Since each of the four blocks illustrated above comprises 6 permutations, therefore, the 16th permutation will lie in (16 / 6 ) = 2nd block, and our answer is the (16 % 6) = 4th sequence from the 2nd block. Therefore 3 occupies the first position of the sequence and K = 4.

STEP 2:(Image-2)

    Our new search space comprises three elements {1,2,4} where K = 4 . Using the previous technique we can consider the second position to be occupied can be any one of these 3 numbers. Again one block can start with 1, another can start with 2 and the last one can start with 4 . Since one position is fixed, the remaining two numbers of each block can form 2! = 2  sequences. In sorted order :

    The 0th – 1st sequence starts with 1 
    The 2nd – 3rd sequence starts with 2 
    The 4th – 5th sequence starts with 4
    

    The 4th permutation will lie in (4/2) = 2nd block and our answer is the 4%2 = 0th sequence from the 2nd block. Therefore 4 occupies the second position and K = 0.

STEP 3: (Image-3)

    The new search space will have two elements {1 ,2} and K = 0. One block starts with 1 and the other block starts with 2. The other remaining number can form only one 1! = 1 sequence. In sorted form –

    The  0th sequence starts with 1 
    The  1st sequence. starts with 2

    The 0th permutation will lie in the (0/1) = 0th block and our answer is the 0%1 = 0th sequence from the 0th block. Therefore 1 occupies the 3rd position and K = 0.

STEP 4: (Image-4)

    Now the only block has 2 in the first position and no remaining number is present.

    This is the point where we place 2 in the last position and stop.

    The final answer is 3412.
*/

#include <bits/stdc++.h>
using namespace std;
// brute force:     // tc -> n!*log(n!)
// storing each permutation in a ds. and returning k-1

// tc-> O(n*n)
class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> num;
        for(int i = 1; i<n; i++){
            fact *= i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k = k-1;
        while(1){
            ans = ans + to_string(num[k / fact]);
            num.erase(num.begin() + (k / fact));
            if(num.size() == 0){
                break;
            }
            k = k % fact;
            fact /= num.size();
        }
        return ans;
    }
};