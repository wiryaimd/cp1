#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

int main(){

    int n, m, k;
    std::cin >> n >> m >> k;
    std::map<std::string, bool> mp;
    std::pair<std::string, std::string> p[n];
    for(int i = 0; i < n; i++){
        std::cin >> p[i].first >> p[i].second;
    }

    for(int i = 0; i < m; i++){
        mp[p[i].second] = true;
    }

    int cnt = 0;
    std::vector<std::string> res;
    for(int i = m; i < n; i++){
        if(cnt == k) break;
        if(mp[p[i].second]) continue;
        mp[p[i].second] = true;
        cnt++;
        res.push_back(p[i].first);
    }

    std::cout << res.size() << std::endl;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i] << std::endl;
    }

    return 0;
}