#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

#include<iostream>
#include<map>

int main(){

    /*
        WA
    */

    int n, m;
    std::cin >> n >> m;

    std::map<int, int> mp;
    for(int i = 0; i < m; i++){
        int s, c;
        std::cin >> s >> c;
        if(mp.count(s) == 0){
            mp[s] = c;
            continue;
        }
        // debug(mp[s] > c);
        if(mp[s] > c){
            mp[s] = c;
        }
    }

    if(mp[1] == 0 || mp[n] == 0){
        std::cout << -1 << std::endl;
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(mp.count(i + 1) == 0){
            std::cout << 0;
            continue;
        }
        std::cout << mp[i + 1];
    }

    std::cout << std::endl;

    return 0;
}