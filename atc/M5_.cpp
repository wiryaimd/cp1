/*
 * Prob: Mod Sum
 * File Created: Friday, 17th May 2024 9:48:01 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){
    
    /*
        find most max sum 1 to n that mod by permutation 1 to n

        because most max remainder always at ith % i+1th which is the remainder is i-th self.
        then, we can only use arithmetic progression to sum 1 to n - 1 (see _2.cpp)



        TLE because constrainsts up to 10^9
    */

    int n;
    cin >> n;

    unsigned long long cnt = 0;
    int last = n % 1;
    int pos = 0;
    for(int i = 0; i < n - 1; i++){
        int rem = (i + 1) % (i + 2);
        cnt += rem;

        // if(rem > n % (i + 2)){
        //     continue;
        // }

        // last = n % (i + 2);
        // pos = i + 1;
    }

    // cnt -= pos % (pos + 1);
    // cnt += last;
    
    cout << cnt << endl;

    return 0;
}