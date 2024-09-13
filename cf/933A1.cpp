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
        int n, m, k;
        std::cin >> n >> m >> k;

        std::vector<int> b(n), c(m);
        for(int i = 0; i < n; i++){
            std::cin >> b[i];
        }

        for(int i = 0; i < m; i++){
            std::cin >> c[i];
        }

        std::sort(b.begin(), b.end());
        std::sort(c.begin(), c.end());

        ll cnt = 0;
        for(int i = 0; i < n; i++){
            if(b[i] >= k) break;
            int r = std::upper_bound(c.begin(), c.end(), k - b[i]) - c.begin();
            cnt += r;
        }

        std::cout << cnt << std::endl;
    }

    return 0;
}