#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*


    Input Format: N = 5

    Result:
        1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1

    Explanation: There are 5 rows in the output matrix. Each row corresponds to each one of the rows in the image shown above.

    Intuition: 
        When you see the image above, you get a pretty good idea of what you are supposed to do here. Think about the image as a matrix now where each line is basically a row in the matrix. So, first things first, if you are at the edge of the matrix, the value is 1, that’s for sure. Now, what about the inner elements? Well, any inner element is obtained by doing the sum of the 2 values present in the row just above it, i.e., if the element is at index (i, j), then matrix[i][j] can be obtained by doing matrix[i – 1][j – 1] + matrix[i – 1][j].

    TC -> n^2
    SC -> n^2

    LC -> 118
    CodeStudio -> https://www.codingninjas.com/codestudio/problems/1089580?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1
*/

vector<vector<long long int>> printPascal(int n) 
{
	vector<vector<long long int>> ans;
	
	for(int i = 0; i<n; i++) {
		vector<long long int> row(i+1, 1);
		for(int j = 1; j < i; j++) {
			row[j] = ans[i-1][j-1] + ans[i-1][j];
		}
		ans.push_back(row);
	}
	return ans;
}
