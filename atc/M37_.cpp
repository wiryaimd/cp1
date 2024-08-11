/*
 * Prob: #
 * File Created: Wednesday, 19th June 2024 4:10:33 pm (code 20 mins? + etc)
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
        given xi value

        count how much operation to make all n data be zero
        if we remove xi val from index L to R that decreased one

        eg. 1 2 2 1
        operation
            L1 R4 = 0 1 1 0
            L2 R3 = 0 0 0 0
            (2 total operation)
        
        eg. 2 3 3 2 1
        operation
            L1 R5 = 1 2 2 1 0
            L1 R4 = 0 1 1 0 0
            L2 R3 = 0 0 0 0 0
            (3 total operation)

        sol:
            constrainst is n <= 100

            then just brute force

            find its minimum
            decrement data from L to R with minimum
            
            if xi is 0 then skip

            count how much the loop

        see _2.cpp for cleaner solution
    */

    int n;
    std::cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        std::cin >> h[i];
    }

    int k = 0;
    int cnt = 0;

    while(true){
        int minn = INT32_MAX;
        int r = n;

        bool pass = false;
        int curr = k;
        for(int i = curr; i < n; i++){
            if(h[i] == 0 && !pass){
                k++;
                continue;
            }

            if(h[i] == 0 && pass){
                r = i;
                break;
            }

            pass = true;
            minn = std::min(minn, h[i]);
            // debug(minn);
        }
        // debug(k);
        // debug(r); br;

        if(k >= n){
            break;
        }

        for(int i = k; i < r; i++){
            h[i] -= minn;
        }
        cnt += minn;
    }

    std::cout << cnt << std::endl;

    return 0;
}