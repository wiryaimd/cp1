#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    /*
        WA 3 testcases
    */

    int n;
    std::cin >> n;

    std::map<int, int> mp;
    int meet4 = 0;
    int mut2 = 0;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        if(a % 4 == 0){
            meet4++;
        }else if(a * 2 % 4 == 0 && a != 2){
            mut2++;
        }

        mp[a]++;
    }

    debug(mp[2]);
    debug(mut2);
    if(mut2 > 0 || mp[2] > 1){
        n -= (mp[2] + mut2);
    }
    debug(n);
    debug(meet4);

    if(meet4 >= n / 2){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }


    return 0;
}