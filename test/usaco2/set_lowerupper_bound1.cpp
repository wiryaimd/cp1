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

    int n, m;
    std::cin >> n >> m;

    std::multiset<int> a;
    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        a.insert(x);
    }

    for(int i = 0; i < m; i++){
        int mi;
        std::cin >> mi;

        auto it = a.upper_bound(mi);
        if(it == a.begin()){
            std::cout << -1 << std::endl;
            continue;    
        }

        int price = *std::prev(it);
        if(price > mi){
            std::cout << -1 << std::endl;
        }else{
            a.erase(std::prev(it)); // erase(prev(it)) instead of erase(price), because this using multiset and have multiple same value
            std::cout << price << std::endl;

            // debug(a.count(price));
        }
    }

    return 0;
}