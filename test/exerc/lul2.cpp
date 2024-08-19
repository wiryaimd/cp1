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

    int n;
    std::cin >> n;

    std::set<int> a;
    for(int i = 0; i < n; i++){
        int ai;
        std::cin >> ai;
        a.insert(ai);
    }

    // std::sort(a.begin(), a.end());

    int q;
    std::cin >> q;
    while(q--){
        int x, y;
        std::cin >> x >> y;
        // if(a.lower_bound(x) == a.end()){
        //     it = std::prev(it);
        // }
        int d = std::distance(a.upper_bound(x), a.upper_bound(y));
        // int d2 = std::distance(a.begin(), a.upper_bound(y));
        // debug(d)
        // debug(d2);
        // debug(*f);

        std::cout << d << std::endl;
        
        // int res = std::distance(a.end(), std::prev(a.upper_bound(x))) + std::distance(std::prev(a.upper_bound(y)), a.begin());
        // debug(res);
    }

    

    return 0;
}