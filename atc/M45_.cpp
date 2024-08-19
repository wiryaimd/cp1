/*
 * Prob: Scc puzzles (8 mins code)
 * File Created: Sunday, 23rd June 2024 3:45:19 pm
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

    /*
        you have 's' and 'c'
        two 'c' can combined to be one 's'

        given N for 's' and M for 'c'

        find how much maximum possible to make 'Scc'

    */

    ll n, m;
    std::cin >> n >> m;

    ll res;
    if(m / 2 > n){ // m/2 because need two c to make one s, compare which biggest
        ll rem = (m - (n * 2)) / 4; // check remaining m after used for N 's'
        res = n + rem; // res
    }else{
        res = m / 2; // count how much Scc can make using m
    }

    std::cout << res << std::endl;

    return 0;
}