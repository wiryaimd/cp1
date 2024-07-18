/*
 * Prob: 2SUM
 * File Created: Monday, 15th July 2024 1:27:51 pm
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
        2SUM problem
            given n array and val x, find two value (distinct position) that the sum is equal to x
        
        print the position of the array

        sol
            using two pointers approach for two sum, which
            sort it first
            start L at 0 and R at end position
            if total < x then L++
            if total > x then R--

            otherwise it impossible
    */

    int n, x;
    std::cin >> n >> x;

    std::pair<int, int> a[n];
    for(int i = 0; i < n; i++){
        int ai;
        std::cin >> ai;

        a[i] = std::make_pair(ai, i);
    }

    std::sort(a, a + n);

    int l = 0, r = n - 1;
    while(l < r){
        if(a[l].first + a[r].first == x){
            std::cout << a[l].second + 1 << " " << a[r].second + 1 << std::endl;
            return 0;
        }

        if(a[l].first + a[r].first < x){
            l++;
        }else{
            r--;
        }
    }

    std::cout << "IMPOSSIBLE" << std::endl;

    return 0;
}