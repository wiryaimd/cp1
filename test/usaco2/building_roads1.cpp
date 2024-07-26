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
    graph probl


    given N city from 1 to N and M roads, each two city connected with one roads. 
    theres may some city that disconnected from another city because no roads between them

    find minimum roads need to be added to make all city connected, 
    print road from-to city

    sol
        store all city from 1 to N in set<> visit
        using dfs traversal to traverse all connected graph,
        each traverse delete visited city and check the remaining visit city
        do the same thing until visit is empty and count how much calling dfs per connected graph
*/

int n, m;
std::vector<int> adj[100007];
std::set<int> visit;

int last;
void dfs(int x){
    if(visit.find(x) == visit.end()) return;

    // debug(adj[x].size());
    // debug(x);
    last = x; // last node of graph to used for pair an unconnected node
    visit.erase(visit.find(x)); // connected city that already found is deleted to get which city havent been found in set<> visit;
    
    for(int u : adj[x]){
        // debug(u);
        dfs(u);
    }
}

int main(){

    std::cin >> n >> m;

    for(int i = 1; i <= n; i++){
        visit.insert(i); // store all available city
    }

    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        // make it bidirection instead of directional, ngerti lah ya why
        adj[a].push_back(b); 
        adj[b].push_back(a);
    }

    int cnt = 0;
    std::vector<std::pair<int, int>> res;
    dfs(*visit.rbegin()); // scan first pair city, then it used to find which city is discconected (thats why cnt may be 0 if all graph is already connected)

    while(!visit.empty()){ // remaining unvisited city
        res.push_back({last, *visit.rbegin()});
        dfs(*visit.rbegin());
        cnt++;
    }

    std::cout << cnt << std::endl;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i].first << " " << res[i].second << std::endl;
    }

    return 0;
}