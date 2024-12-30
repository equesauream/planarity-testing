// this is the planarity testing algorithm

#include <iostream>
#include <stack>

#include "pqtree.h"

// psuedocode from Haeupler, Tarjan (2008)

/*Our linear-time implementation of the abstract planarity testing method does
a depth-first search on every connected component of the input graph, testing
planarity on the fly using PQ-trees. For each ancestor v in the depth-first
spanning tree of the current vertex of the search it maintains a PQ-tree and
a set of PQ-tree leaves S(v):
• When advancing along a tree arc (v, w), construct a PQ-tree for w consisting
of a root that is the special leaf and represents (v, w), with a single child that
is a P-node and represents w. Initialize S(v) to contain just the special leaf.
• When advancing along a back arc (v, w), add a leaf child representing (v, w)
to the P-node for v, and add this leaf to S(w).
• When retreating along a tree arc (v, w), reduce the PQ-tree for w to represent
the circular orders such that the leaves in S(v) are consecutive. If this produces
the null tree, stop and declare the graph non-planar. Otherwise, delete from
the reduced tree all the leaves in S(v), simplify the tree by deleting P-nodes
and Q-nodes with no children and repeating until all P-nodes and Q-nodes
have children, and do the appropriate part of the combining step by making
the root of the simplified tree a child of the P-node for v, unless v is the start
vertex of the depth-first search.*/

bool ptest(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> next;
    for (int i = 0; i < n; ++i) {
        next.push(i);
    }
    while (next.size() > 0) {
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