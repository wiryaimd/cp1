/*
 * Prob: #
 * File Created: Friday, 21st June 2024 3:26:12 pm
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
        given M data with N pieces coordinate that you can select
        Ni coordinate can move +1 or -1

        find minimum move to visit all M data

        eg.
            N = 2, M = 5
            10 12 1 2 14
            step
                set Xi = 1 and 10
                move 1 to 2
                move 10 to 11
                move 11 to 12
                move 12 to 13
                move 13 to 14
                (total 5 move)

        sol: 
            sort it, find most highest gap for each data
            sort again for most highest gap from smallest index to higher until X-1 length (-1 because X0 already used for index 0)

            count total from each gap

        other solution see _2.cpp
    */

    int n, x;
    std::cin >> x >> n;

    std::vector<int> v(n);
    for(int i = 0; i < n; i++){
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    std::vector<std::pair<int, int>> p;
    int curr = v[0];
    for(int i = 1; i < n; i++){ // store gap data
        p.push_back(std::make_pair(i - 1, v[i] - curr)); // store index and gap
        curr = v[i];
    }

    // for(int i = 0; i < n; i++){
    //     debug(v[i]);
    // }

    // for(int i = 0; i < n; i++){
    //     debug(sums[i]);
    // }

    std::sort(p.begin(), p.end(), [](std::pair<int, int> a, std::pair<int, int> b){ // get most gap
        return a.second > b.second;
    });

    std::sort(p.begin(), p.begin() + std::min(x - 1, n - 1)); // sort most gap from 0 to p + min(x-1, n-1) based on index

    int tmp = 0;
    long long cnt = 0;
    for(int i = 0; i < std::min(x - 1, n - 1); i++){
        // debug(p[i].first);
        // debug(p[i].second); br;

        cnt += v[p[i].first] - v[tmp]; // already sorted, so no need prefix sum
        tmp = p[i].first + 1;
    }

    cnt += v[n - 1] - v[tmp];

    std::cout << cnt << std::endl;

    return 0;
}