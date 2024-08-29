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
        int n, m, k, w;
        std::cin >> n >> m >> k;
        std::cin >> w;

        int h[w];
        for(int i = 0; i < w; i++){
            std::cin >> h[i];
        }

        std::vector<std::vector<ll>> a(n + 2, std::vector<ll>(m + 2, 0));
        
        // count each spectacle using difference array and prefix sum

        for(int i = 1; i <= n - k + 1; i++){
            for(int j = 1; j <= m - k + 1; j++){ // difference array
                a[i][j]++;
                a[i][j + k]--;
                a[i + k][j]--;
                a[i + k][j + k]++; // it doubly decremented, then add it back
                // doubly decremented when doing prefix sum which is a[i - 1][j] + a[i][j - 1], that row and col have been decremented by a[i][j + k]-- and a[i + k][j]-- so a[i + k][j + k] affected
                
            }
        }

        std::vector<ll> coef;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){ // prefix sum
                a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
                coef.push_back(a[i][j]); // store in vector
            }
        }

        // use greedy to get most max
        std::sort(h, h + w, std::greater<>());
        std::sort(coef.begin(), coef.end(), std::greater<>());

        ll total = 0;
        for(int i = 0; i < w; i++){
            total += h[i] * coef[i]; // get result
        }

        std::cout << total << std::endl;
        // debug(total);
    }

    return 0;
}