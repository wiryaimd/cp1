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
        int x, y;
        std::cin >> x >> y;

        int mut = (y + 1) / 2;
        int remy = y % 2;
        int remx = 7 * mut;
        if(remy == 1) remx += 4;
        if(remx - x < 0){
            mut += std::ceil((float)(x - remx) / 15);
        }
        
        std::cout << mut << std::endl;
    }

    return 0;
}

/*
    while(t--){
        cin>>x>>y;
        cout<<max((y+1)/2,(4*y+x+14)/15)<<"\n";} // +14 for ceiling when div by 15 
        or can use

        res = max((y + 1) / 2, ceil((4 * y + x) / 15) )
    }
*/