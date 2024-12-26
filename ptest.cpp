// this is the planarity testing algorithm

#include <iostream>
#include <stack>

#include "pqtree.h"

bool ptest(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> next;
    for (int i = 0; i < n; ++i) {
        next.push(i);
    }
    while(next.size() > 0) {
        int v = next.top();
        next.pop();

        if (visited[v]) {
            continue;
        }

        for (const auto& nbr : adj[v]) {
            next.push(nbr);
        }

    }
    
}