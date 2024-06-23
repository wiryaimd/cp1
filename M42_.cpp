/*
 * Prob: Evilator
 * File Created: Sunday, 23rd June 2024 9:17:48 am
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
        given string S contain 'U' and 'D' as up and down, each Si can only going up or down
        count how much minimum 'total times to take the elevetaor' from each floor (i, j) needed
        and go to his destination floor

        eg.
            UUD
            - s0 going to s1, or s2 only need to take elevator once (only up)
            - s1 going to s0, need to take elevetaor twice (s1 going (up) to s2 then go down to s0)
            - same, check for all (i, j)

        constrainst s0 always UP and sn always Down
        
        sol
            maximum take only taking twice elevetor.
            then count when si is up, then if want to go down (below i), we need taking elevator twice
            then we can count it using cnt i * 2

            same for si = down
    */

    std::string s;
    std::cin >> s;

    int n = s.length();
    long long cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
            cnt += n - (i + 1); // count for how much floor above i
            cnt += i * 2; // count below i that need to take elevator twice
            // debug(i * 2);
        }else{
            cnt += i; // if si going down, then no need take elevator twice
            cnt += (n - (i + 1)) * 2; // but if want go to floor above i, need to take it twice
            // debug((n - (i + 1)) * 2);
        }
    }

    std::cout << cnt << std::endl;

    return 0;
}