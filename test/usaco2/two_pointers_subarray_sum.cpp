/*
 * Author: Wiryaimd
 * File Created: Sunday, 14th July 2024 1:40:29 pm
 * CF 171B (*1400), Books
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
        using two pointer approach

        sub array sum problems
            find most maximum total sub array, from L and R

        for this case, print its most max range from L to R position that its total value does not exceed k

        sol
            for sub array sum,
            both L and R position start at left pos

            if total L to R < k then R++
            if total L to R > k then L++
            total L to R can be checked using prefix sum
            
            when L to R < k check its max(maxx, R - L)

            initial max is -1 because, it will +1 for all result (for counting total books in prob)
    */

    int n, k;
    std::cin >> n >> k;

    int a[n];
    std::vector<int> ps(n + 1, 0);
    for(int i = 0; i < n; i++){
        std::cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    int l = 1, r = 1;
    int maxx = -1;
    while(l <= n && r <= n){ // <= n because it index start with 1 (instead of 0)
        int cnt = ps[r] - ps[l - 1];
        if(cnt <= k){
            maxx = std::max(maxx, r - l);
            r++;
        }else{
            l++;
        }
    }

    std::cout << maxx + 1 << std::endl;

    return 0;
}