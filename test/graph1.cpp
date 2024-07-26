#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

bool visit[10];
std::vector<int> adj[10];

// graph traversal using DFS
void dfs(int x){
    if(visit[x]) return;

    visit[x] = true;
    debug(adj[x].size());
    for(int u : adj[x]){ // all node will visited when its a (connected graph)
        debug(x);
        debug(u);
        dfs(u);
    }
}

int main(){

    // graph representation

    int N = 10;

    // most common way, vector<> v[N]
    // std::vector<int> adj[N]; // adjacent
    adj[1].push_back(3);
    adj[1].push_back(5);
    adj[1].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(1);

    int i = 0;;
    for(std::vector<int> u : adj){
        for(int x : u){
            // debug(i);
            // debug(x); br;
        }
        i++;
    }

    // if need weight
    std::vector<std::pair<int, int>> v2[5]; // graph with weight for each edges
    v2[3].push_back({1, 5}); // (3) ---5---> (1)
    v2[4].push_back({3, 2}); // (4) ---2---> (3)

    // matrix representation
    int mtx[N][N];

    // edge list
    // only store direction from nodesrc to nodetrg
    std::vector<std::pair<int, int>> edges;
    edges.push_back({1, 2}); // (1) --> (2) graph going from node 1 to ndoe 2
    edges.push_back({3, 5}); // (3) --> (5) 

    std::vector<std::tuple<int, int, int>> edges2; // edges with weight

    dfs(2);

    return 0;
}