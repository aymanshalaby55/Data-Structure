#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
public:
    UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

bool hasCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    UnionFind uf(n);
    for (int i = 0; i < n; i++) {
        for (int j : graph[i]) {
            if (uf.find(i) == uf.find(j)) {
                return true;
            }
            uf.unionSets(i, j);
        }
    }
    return false;
}



