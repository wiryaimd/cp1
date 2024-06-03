/*
 * Prob: #
 * File Created: Monday, 3rd June 2024 1:19:58 pm
 * Author: Wiryaimd
 */

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

#include<iostream>
#include<vector>
#include<algorithm>

int main(){

    /*
        count minimum deleted number so the total unique number not greater than k total

        sol:
            count all unique number, then sort, find its smallest unique
            and accumulate until total_unique - total_k
    */

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int ai;
        std::cin >> ai;
        if(a[ai - 1] == 0){
            cnt++;
        }
        a[ai - 1]++;
    }

    if(k >= cnt){
        std::cout << 0 << std::endl;
        return 0;
    }

    sort(a.begin(), a.end());
    long long res = 0;
    int l = 0;
    for(int i = 0; i < n; i++){ 
        // or use < n - k, and skip this condition below. for simplify
        if(a[i] == 0){
            continue;
        }

        if(l >= cnt - k){
            break;
        }
        l++;
        debug(a[i]);
        res += a[i];
    }

    std::cout << res << std::endl;


    return 0;
}