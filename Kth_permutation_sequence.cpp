#include<bits/stdc++.h>
using namespace std;
// brute force:     // tc -> n!*log(n!)
// storing each permutation in a ds. and returning k-1


// tc-> O(n*n)
class Solution {
public:
    string getPermutation(int n, int k) {
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