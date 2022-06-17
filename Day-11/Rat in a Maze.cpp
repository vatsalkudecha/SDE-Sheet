#include<bits/stdc++.h>
using namespace std;

class Solution{
    private:
    void solve2(int row, int col, string s, vector<string> &ans, 
                    vector<vector<int>> &m, vector<vector<int>> &vis, int n, int di[], int dj[])
    {
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        string direction = "DLRU";
        for(int ind = 0; ind<4; ind++){
            int nexti = row + di[ind];
            int nextj = col + dj[ind];
            if(nexti >= 0 && nextj >= 0 && nexti < n && nextj < n 
                && !vis[nexti][nextj] && m[nexti][nextj])
            {
                vis[row][col] = 1;
                s += direction[ind];
                solve2(nexti, nextj, s, ans, m, vis, n, di, dj);
                s.pop_back();
                vis[row][col] = 0;
            }
        }
    }
    
    void solve1(int row, int col, string s, vector<string> &ans, 
                    vector<vector<int>> &m, vector<vector<int>> &vis, int n)
    {
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return;
        }
        if((row + 1) < n && (m[row+1][col]) && !vis[row+1][col]){
            vis[row][col] = 1;
            s += "D";
            solve1(row+1, col, s, ans, m, vis, n);
            s.pop_back();
            vis[row][col] = 0;
        }
        if((col-1) >= 0 && (m[row][col-1]) && !vis[row][col-1]){
            vis[row][col] = 1;
            s += "L";
            solve1(row, col-1, s, ans, m, vis, n);
            s.pop_back();
            vis[row][col] = 0;
        }
        if((col + 1) < n && (m[row][col+1]) && !vis[row][col+1]){
            vis[row][col] = 1;
            s += "R";
            solve1(row, col+1, s, ans, m, vis, n);
            s.pop_back();
            vis[row][col] = 0;
        }
        if((row -1) >= 0 && (m[row-1][col]) && !vis[row-1][col]){
            vis[row][col] = 1;
            s += "U";
            solve1(row-1, col, s, ans, m, vis, n);
            s.pop_back();
            vis[row][col] = 0;
        }
        
        
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        // if(m[0][0] == 0 || m[n-1][n-1] == 0) return {};
        vector<vector<int>> vis(n, vector<int> (n, 0));
        string s = "";
        vector<string> ans;
        // solve1(0, 0, s, ans, m, vis, n);
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1 && m[n-1][n-1]){
            solve2(0, 0, s, ans, m, vis, n, di, dj);
        }
        return ans;
    }
};