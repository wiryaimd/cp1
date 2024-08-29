#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

int main(){

    int t;
    std::cin >> t;
    while(t--){
        int n;
        std::cin >> n;

        int a[n];
        for(int i = 0; i < n; i++){
            std::cin >> a[i];
        }

        std::map<std::tuple<int, int, int>, int> mp;
        ll cnt = 0;
        for(int i = 2; i < n; i++){
            auto t1 = std::make_tuple(a[i], a[i - 1], 0);
            auto t2 = std::make_tuple(a[i], 0, a[i - 2]);
            auto t3 = std::make_tuple(0, a[i - 1], a[i - 2]);
            auto t4 = std::make_tuple(a[i], a[i - 1], a[i - 2]); // decrease with t4, how much duplicate that a1 == b1, a2 == b2, a3 == b3

            cnt += mp[t1] - mp[t4];
            cnt += mp[t2] - mp[t4];
            cnt += mp[t3] - mp[t4];

            mp[t1]++;
            mp[t2]++;
            mp[t3]++;
            mp[t4]++;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}