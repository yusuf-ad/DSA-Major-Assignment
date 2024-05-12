#include<bits/stdc++.h>
using namespace std;

bool isSafe(int v, bool graph[101][101], int color[], int c, int V) {
    for(int i = 0; i < V; i++)
        if(graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[101][101], int m, int color[], int v, int V) {
    if(v == V)
        return true;

    for(int c = 1; c <= m; c++) {
        if(isSafe(v, graph, color, c, V)) {
            color[v] = c;
            if(graphColoringUtil(graph, m, color, v+1, V) == true)
                return true;
            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    int color[V];
    for(int i = 0; i < V; i++)
        color[i] = 0;

    if(graphColoringUtil(graph, m, color, 0, V) == false) {
        return false;
    }

    return true;
}

int main() {
    bool graph1[101][101] = {{0, 1, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 0}};
    int m1 = 3;
    int V1 = 4;
    cout << "Example 1 output: " << graphColoring(graph1, m1, V1) << endl;  

	cout << endl;

    bool graph2[101][101] = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
    int m2 = 2;
    int V2 = 3;
    cout << "Example 2 output: " << graphColoring(graph2, m2, V2) << endl; 
    
    return 0;
}
