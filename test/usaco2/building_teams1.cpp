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

/*
    graph (bipartite) prob

    given N node and M pairs
    you can assume each node have at most one connected node between them

    //// print splited node which the node connected each other.
    more simply, just print its bipartite for each node by 1 and 2

    bipartite is when color in node must different in each other side

    print it for each node 1...N, print impossible if cant

*/

std::vector<int> adj[100007];
bool visit[100007];
bool team[100007];
bool valid = true;

void dfs(int x, int last){
    // debug(last);
    if(visit[x]) {
        if(!last == team[x]){ // when the visited node have same value with last team[x], then its impossible
            // debug(x);
            valid = false;
        }
        return;
    }

    visit[x] = true;
    team[x] = last; // set its bipartite with !last when call dfs

    for(int u : adj[x]){
        dfs(u, !last); // !last
    }
}

int main(){

    int n, m;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 1);
    for(int i = 1; i <= n; i++){ // simple way to traverse all unconnected graph (instead of using set<>)
        if(!visit[i]){
            dfs(i, 1);
        }
    }

    if(!valid){
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        std::cout << team[i + 1] + 1;
        if(i < n - 1){
            std::cout << " ";
        }
    }

    std::cout << std::endl;



    return 0;
}