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
        given n array, find its max sub array sum
        -1, 3, -2, 5, 3, -5, 2, 2

        its max is: 3 + -2 + 5 + 3 = 9

        sol:
            the things that 'negative' value that will make subarray can max or not,
            if theres no negative value, then ofcourse subbarray from 0 to n is max

            use prefix sum and.
            step 1.
                find most minimum value from left in prefix sum ps[i]
                eg. n = -2, -4, 5, 3, 2
                then most minimum in ps[i] is -6
            step 2.
                find most maximum for all ps[i] - mininmum_left

                then when ps[4], it'l be,
                -2 + -4 + 5 + 3 + 2 = 4 - (-6) == 10

                ans = 10

            notice that ps[i] - minimum_left will always subtract negative or zero value
            so it will recover actual value when its ps have subtracted by negative

            then we can find its maximum

    */

    int n;
    std::cin >> n;
    std::vector<int> v(n + 1, 0);
    for(int i = 1; i <= n; i++){
        std::cin >> v[i];
        v[i] = v[i] + v[i - 1];
    }

    int maxx = v[1]; // start position prefix sum
    int minn = v[0]; // current most minimum is zero, so x < 0 is negative
    for(int i = 1; i <= n; i++){

        maxx = std::max(maxx, v[i] - minn); // check maximum - (-minimum val), (itl always substracted negative)
        minn = std::min(minn, v[i]); // find most minimum to be used for finding max


        // debug(maxx);
        // debug(minn); br;
    }

    debug(maxx);

    return 0;
}