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

    // f(i) => # in prefix ending at i that are >= k
    // g(i) => # in prefix ending at i that are <= m
    
    // m < k
    
    // construct a permutation such that
    // (sum of all f(i)) - (sum of all g(i)) is maximized
    
    // g(i) and f(i) have no overlap
    // if k is much larger than m
    // then there may be some elements in the prefix not included in either g(i) or f(i)
    
    // want to maximize left side and minimize right side
    // so put all the elements >= k first
    // then all the elements <= m last
    // put other elements after the ones >= k to extend the f sum

    int t;
    std::cin >> t;
    while(t--){
        int n, m, k;
        std::cin >> n >> m >> k;
        for(int i = n; i > m; i--){
            std::cout << i << " ";
        }

        for(int i = 1; i <= m; i++){
            std::cout << i << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}