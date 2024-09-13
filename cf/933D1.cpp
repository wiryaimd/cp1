#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

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

// int main(){

//     int t;
//     std::cin >> t;
//     while(t--){
//         int n, m, x;
//         std::cin >> n >> m >> x;

//         std::vector<int> num(n);
//         std::iota(num.begin(), num.end(), 1);

//         int r0;
//         char c0;
//         std::cin >> r0 >> c0;
//         adj[r0].push_back(num[(x + r0) % n]);
//         if(x - r0 < 0){
//             adj[r0].push_back(num[(n + (x - r0)) - 1]);
//         }else{
//             adj[r0].push_back(num[x - r0]);
//         }


//         for(int i = 1; i < m; i++){
//             int r;
//             char c;
//             std::cin >> r >> c;

//             if(c == '?'){
//                 dfs(r0);
//                 continue;
//             }

//             // if(c - '0'){
//             //     adj[r].push_back();
//             // }else{
//             //     adj[r].push_back();
//             // }
//         }
//     }

//     return 0;
// }