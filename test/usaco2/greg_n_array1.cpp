/*
 * Prob: CF 179 A (*1400)
 * File Created: Tuesday, 9th July 2024 10:10:01 pm
 * Author: Wiryaimd
 */


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

    /*
        approach with using difference array technique and prefix sum

        the problem need count difference array two times, for
        l to r with val d and
        x to y with val 1
    */

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> a(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    std::vector<std::tuple<int, int, int>> opr(m);
    for(int i = 0; i < m; i++){
        int l, r, d;
        std::cin >> l >> r >> d;
        opr[i] = std::make_tuple(l, r, d);
    }

    std::vector<ll> diffk(m + 1, 0);
    for(int i = 0; i < k; i++){
        int x, y;
        std::cin >> x >> y;
        diffk[x - 1] += 1;
        diffk[y] -= 1; // or use diffk[y] directly instead
        // if(y < m){ // without this condition
        //     diffk[y] -= 1;
        // }
    }

    std::vector<ll> psk(m, 0);
    psk[0] += diffk[0];
    for(int i = 1; i < m; i++){
        diffk[i] = diffk[i] + diffk[i - 1];
        psk[i] += diffk[i];
    }

    std::vector<ll> diffopr(n + 1, 0);
    for(int i = 0; i < m; i++){
        int l, r, d;
        std::tie(l, r, d) = opr[i];
        diffopr[l - 1] += ((ll)d * psk[i]);
        diffopr[r] -= ((ll)d * psk[i]); // same as diffopr[r + 1] when l is diffopr[l]
        // if(r < n){
            // diffopr[r] -= ((ll)d * psk[i]);
        // }
    }

    a[0] += diffopr[0];
    for(int i = 1; i < n; i++){
        diffopr[i] = diffopr[i] + diffopr[i - 1];
        a[i] += diffopr[i];
    }

    for(int i = 0; i < n; i++){
        std::cout << a[i];
        if(i + 1 < n){
            std::cout << " ";
        }
    }

    std::cout << std::endl;


    return 0;
}