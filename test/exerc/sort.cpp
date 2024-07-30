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

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n, q;
        std::string a, b;
        std::cin >> n >> q;
        std::cin >> a >> b;

        for(int j = 0; j < q; j++){
            int l, r;
            std::cin >> l >> r;
            l--, r--;
            int cnta[26] = {0};
            int cntb[26] = {0};
            for(int k = l; k <= r; k++){
                debug(a[k] - 'a');
                // debug(b[k] - 'a');
                cnta[a[k] - 'a']++;
                cntb[b[k] - 'a']++;
            }
            ll cnt = 0;
            bool call[26] = {false};
            for(int k = l; k <= r; k++){
                // debug(cnta[k]);
                // debug(cntb[k]);
                if(call[a[k] - 'a']) continue;
                call[a[k] - 'a'] = true;

                // debug
                cnt += std::abs(cnta[a[k] - 'a'] - cntb[a[k] - 'a']);
                // cnt += cnta[a[k] - 'a'] - cntb[a[k] - 'a'];
            }

            // std::cout << cnt << std::endl;
            debug(cnt);
        }
    }

    return 0;
}