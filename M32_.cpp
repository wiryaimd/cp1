/*
 * Prob: #
 * File Created: Sunday, 9th June 2024 2:58:15 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

int main(){

    int n, y;
    std::cin >> n >> y;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n - i; j++){
            int k = n - i - j;
            if((i * 10000) + (j * 5000) + (k * 1000) == y){
                std::cout << i << " " << j << " " << k << std::endl;
                return 0;
            }
        }
    }

    std::cout << -1 << " " << -1 << " " << -1 << std::endl;

    return 0;
}