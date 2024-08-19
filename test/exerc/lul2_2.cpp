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

    std::vector<int> a(n);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
    }

    int q;
    std::cin >> q;
    while(q--){
        int x, y;
        std::cin >> x >> y;
        
        int d = std::upper_bound(a.begin(), a.end(), y) - std::upper_bound(a.begin(), a.end(), x);
        std::cout << d << std::endl;
    }

    return 0;
}