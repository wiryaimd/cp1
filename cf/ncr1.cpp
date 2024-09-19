#ifndef ONLINE_JUDGE
#include "../debug.hpp"
#else
#define debug(...)
#define debugArr(...)
#endif

#define br std::cerr << std::endl;

#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>
#include<cstring>
#include<numeric>

using ll = long long;
const ll INF = 1e18 + 7;

// naive approach
// work for small input when n <= 21 about (because ncr exceed value for ll when n > 21)
ll factorial(int x){
    if(x == 0) return 1;

    ll cnt = 1;
    for(int i = 1; i <= x; i++){
        cnt *= i;
    }
    return cnt;
}

ll ncr(int n, int r){
    if (r < 0 || r > n) return 0; // out of bound

    // nCr = n! / r! (n - r)!
    return factorial(n) / (factorial(r) * factorial(n - r)); // O(n) + O(r) + O(n - r) === O(n)
}

ll ncr_optmize1(int n, int r){
    ll cnt = 1;
    // r = std::min(r, n - r);  // may add this symmetry rule to a bit more optimize for large r

    // multiply n! up to (n - r)! then for each multiply, directly divide by j to avoid ll size exceed
    for(int i = n, j = 1; i > n - r; i--, j++){
        cnt *= i;
        cnt /= j;
    }
    // or
    // int d = 1;
    // for(int i = n; i > n - r; i--){
    //     cnt *= i;
    //     cnt /= d;
    //     d++;
    // }
    return cnt;
}

// this code work same like ncr_optimize1() and same time complexity
ll ncr_optmize2(int n, int r){
    if (r < 0 || r > n) return 0;
    r = std::min(r, n - r);  // Use symmetry
    ll result = 1;
    for(int i = 1; i <= r; i++){
        result *= n - r + i;
        result /= i;
    }
    return result;
}

// more advance solution can use modular multiplicative inverse for large n (eg. n >= 1e9)


int main(){
    
    /*
        also called as binomial coefficient, or
        
        combination
            * notation nCr
            The number of ways to choose a sample of r elements from a set of n distinct objects
            where order does not matter and replacements (repetition) are not allowed
        
        permutation
            * notation n!
            find number of ways where order matter and repetition not allowed
        
        combination replacement(repetition)
            order not matter, repetition allowed

        permutation replacement(repetition)
            order matter, repetition allowed

    */
    

    /*
        nCr = n! / r! (n - r)!

        eg n = 10, r = 3
            nCr = 10! / 3! (7!)
            nCr = 10 x 9 x 8 x 7!
                  ---------------
                        3! 7!
            nCr = 10 x 9 x 8
                  -----------
                     3 x 2
    */
    
    debug(ncr(7, 3)); // 35
    debug(ncr(20, 7)); // 77520
    debug(ncr_optmize1(20, 7));

    return 0;
}