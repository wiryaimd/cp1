/*
 * Prob: #
 * File Created: Friday, 28th June 2024 2:01:23 pm
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

using ll = long long;

int main(){

    int t;
    std::cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        std::cin >> n;
        int a[n];
        for(int j = 0; j < n; j++){
            std::cin >> a[j];
        }

        std::sort(a, a + n);
        int k = 1;
        int curr = a[0];
        for(int j = 1; j < n; j++){
            if(curr != a[j]){
                break;
            }
            // curr = a[j];
            k++;
        }

        std::cout << n - k << std::endl;
    }

    return 0;
}