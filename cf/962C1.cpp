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

        int pos[n + 1];
        int cnt_a[26] = {0};
        int cnt_b[26] = {0};
        for(int i = 0; i < n; i++){
            int cnt = 0;
            if(a[i] == b[i]){
                pos[i + 1] = 0;
                continue;
            }

            if(cnt_a[a[i] - 'a'] < cnt_b[a[i] - 'a']){
                cnt--;
            }

            if(cnt_b[b[i] - 'a'] < cnt_a[b[i] - 'a']){
                cnt--;
            }
            
            cnt_a[a[i] - 'a']++;
            cnt_b[b[i] - 'a']++;

            cnt++;
            pos[i + 1] = cnt;
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