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
        given h tickects and t budget, check each t[i] which price is slighty lower than h[i] then printout
        this h[i] ticket can only used by one t[i]

        use multiset, because value can be multiple(dupe) and we need lower_bound() or upper_bound() function 
        to check value lower than i-th

        erase it because already used
    */

    int n, m;
    std::cin >> n >> m;

    std::multiset<int> p;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        p.insert(a);
    }

    for(int i = 0; i < m; i++){
        int t;
        std::cin >> t;

        auto it = p.upper_bound(t);
        if(it == p.begin()){
            std::cout << -1 << std::endl;
        }else{
            it--;
            std::cout << *it << std::endl;
            p.erase(it); // delete by address, not by value (eg. *it)
        }
    }

    return 0;
}
