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

std::vector<std::vector<int>> adj;
std::vector<int> res;

int dfs(int x){
    // if(visit[x]) return 1;
    // visit[x] = true;

    int cnt = 0;
    for(int u : adj[x]){
        cnt += dfs(u) + 1;
    }
    res[x] = cnt;
    return cnt;
}

int main(){

    int n;
    std::cin >> n;
    adj.resize(n);
    res.resize(n);

    for(int i = 0; i < n - 1; i++){
        int a;
        std::cin >> a;
        adj[a - 1].push_back(i + 1);
    }

    dfs(0);
    for(int i = 0; i < n; i++){
        std::cout << res[i] << std::endl;
    }

    return 0;
}