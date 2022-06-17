/*
cs-> https://www.codingninjas.com/codestudio/problems/981273?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=1

gfg-> https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
-----------------------------------------------------
Example 1:
Input: 
N = 4
M = 3
E = 5
Edges[] = {
  (0, 1),
  (1, 2),
  (2, 3),
  (3, 0),
  (0, 2)
}

Output: 1

Explanation: It is possible to colour the given graph using 3 colours.
----------------------------------------------------------
*/

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