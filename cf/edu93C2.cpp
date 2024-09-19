#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define br std::cerr << std::endl;

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
        int n;
        std::string s;
        std::cin >> n >> s;
        int a[n];
        for(int i = 0; i < n; i++){
            a[i] = s[i] - '0';
        }

        ll ps = 0;
        ll cnt = 0;
        std::map<int, int> mp;
        mp[0] = 1;

        // ps[r] - ps[l] = r - l + 1
        // ps[r] - r = ps[l] - l + 1 ====> r - l + 1
        for(int i = 0; i < n; i++){
            ps += a[i]; // using ps[r]
            debug(ps);
            debug(ps - (i + 1)); // zero index, then i + 1
            debug(mp[ps - (i + 1)]);
            cnt += mp[ps - (i + 1)]; // same when approach using n*(n + 1)/2
            debug(cnt);
            br;
            mp[ps - (i + 1)]++;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}

/*
    int n;
	cin >> n;
	vector<int> prefix(n + 1);
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		prefix[i] = c - '0';
	}
 
	for (int i = 1; i <= n; i++) {
		prefix[i] += prefix[i - 1];
	}
 
	map<int, ll> dist;
	for (int i = 0; i <= n; i++) {
		dist[prefix[i] - i]++;
	}
 
	ll ans = 0;
	for (auto cur = dist.begin(); cur != dist.end(); cur++) {
		ans += cur->second * (cur->second - 1) / 2;
	}
 
	cout << ans << endl;
*/