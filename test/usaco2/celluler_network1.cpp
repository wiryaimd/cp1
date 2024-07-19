/*
 * Prob: (*1500) two pointers
 * File Created: Thursday, 18th July 2024 2:32:53 pm
 * Author: Wiryaimd
 */


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
        two pointer approach

        given n city, and m towers with coordinate x-axis
        find minimum distance for each city to get placed by one tower

        nb. n and m input in increasing order

        sol
            check and compare current city to ith tower with i+1th tower, check which is smallest
            when i+1th is smaller then use next th tower (l++)

        other sol
            using set<> and lower_bound() for to find most nearest tower at left or right, then check it most maximum
            see _2.cpp
    */

    int n, m;
    std::cin >> n >> m;

    int c[n], t[m];
    for(int i = 0; i < n; i++){
        std::cin >> c[i];
    }

    for(int i = 0; i < m; i++){
        std::cin >> t[i];
    }

    int l = 0;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        int curr = std::abs(c[i] - t[l]);
        int next = INT32_MAX;
        if(l + 1 < m){
            next = std::abs(c[i] - t[l + 1]);
        }

        // debug(curr);
        // debug(next); br;

        if(curr < next){
            maxx = std::max(maxx, curr);
        }else{
            l++;
            i--;
        }
    }

    std::cout << maxx << std::endl;

    return 0;
}