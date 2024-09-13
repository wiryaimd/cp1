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

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n, m, x;
        std::cin >> n >> m >> x;

        std::vector<int> num(n);
        std::iota(num.begin(), num.end(), 1);

        std::set<int> res;
        res.insert(x);

        for(int i = 0; i < m; i++){
            int r;
            char c;
            std::cin >> r >> c;

            std::set<int> tmp;
            if(c == '?'){
                for(int u : res){
                    tmp.insert((u + r) % n);
                    tmp.insert((((u - r) % n) + n) % n);
                }
            }else if(c == '1'){
                for(int u : res){
                    tmp.insert((((u - r) % n) + n) % n);
                }
            }else{
                for(int u : res){
                    tmp.insert((u + r) % n);
                }
            }

            res = tmp;
        }

        std::cout << res.size() << std::endl;
        if(res.count(0)){
            res.erase(0);
            res.insert(n);
        }

        for(int u : res){
            std::cout << u << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/*
    dp approach

    void solve(){
        ll n, m, x;
        cin>>n>>m>>x;
        vl dp(n);
        x--;
        dp[x] = 1;
        while(m--){
            vl newdp(n);
            ll dist;
            char ch;
            cin>>dist>>ch;
            if(ch != '1'){
                for(ll i = 0; i<n; i++){
                    if(dp[i]){
                        newdp[(i + dist) % n] = 1;
                    }
                }
            }
            if(ch != '0'){
                for(ll i = 0; i<n; i++){
                    if(dp[i]){
                        newdp[(i - dist + n) % n] = 1;
                    }
                }
            }
            dp = newdp;
        }
        vl ans;
        for(ll i = 0; i<n; i++) if(dp[i]) ans.pb(i + 1);
        cout<<ans.size()<<'\n';
        cout<<ans<<'\n';
    }
 
*/