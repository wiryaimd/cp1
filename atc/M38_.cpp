/*
 * Prob: #
 * File Created: Wednesday, 19th June 2024 9:43:55 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    /*
        given n candidate problems with di difficulty
        m problem selected with req difficult is ti

        check if they dont need to make new problem of M selected for competition

        sol:
            use map to count each diffcult

            count if ti difficulty problem not enough then ans = no, otherwise ans = yes
    */

    int n;
    std::cin >> n;

    std::map<int, int> d;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;

        d[a]++;
    }

    bool good = true;

    int m;
    std::cin >> m;

    for(int i = 0; i < m; i++){
        int t;
        std::cin >> t;

        if(d[t] <= 0){
            good = false;
        }

        d[t]--;
    }

    std::cout << (good ? "YES" : "NO") << std::endl;

    return 0;
}