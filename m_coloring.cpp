#include<bits/stdc++.h>
using namespace std;
bool possible(int col, int node, bool graph[101][101], int color[], int n)
{
    for(int k = 0; k<n; k++){
        if(k != node && graph[k][node] == 1 && color[k] == col){
            return false;
        }
    }
    return true;
}

bool solve(int node, bool graph[101][101], int color[], int m, int n)
{
    // able to fill color in all nodes
    if(node == n){
        return true;
    }
    for(int i = 1; i<= m; i++){
        if(possible(i, node, graph, color, n)){
            color[node] = i;
            if(solve(node+1, graph, color, m, n) == true){
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int N)
{
    // your code here
    int color[N] = {0};
    if(solve(0, graph, color, m, N)==true) return true;
    return false;
}