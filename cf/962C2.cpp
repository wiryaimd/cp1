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
        int n, q;
        std::string a, b;
        std::cin >> n >> q;
        std::cin >> a >> b;

        int pos[n + 1] = {0};
        std::vector<int> last(26, 0);
        last[a[0] - 'a']++;
        last[b[0] - 'a']++;

        for(int i = 1; i < n; i++){
            std::vector<int> curr(last.begin(), last.end());
            curr[a[i] - 'a']++;
            curr[b[i] - 'a']++;

            int dif = 0;
            for(int j = 0; j < 26; j++){
                dif += std::abs(last[j] - curr[j]);
            }
            debug(dif);
            pos[i + 1] = dif / 2;
            last = curr;
        }

        for(int i = 1; i <= n; i++){
            pos[i] = pos[i - 1] + pos[i];
        }

        for(int i = 0; i < q; i++){
            int l, r;
            std::cin >> l >> r;

            std::cout << pos[r] - pos[l - 1] << std::endl;
            debug(pos[r] - pos[l - 1]);
        }
    }

    return 0;
}