/*
 * Prob: Replacing Integer
 * File Created: Friday, 3rd May 2024 1:12:40 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        find value that |n - k| as minimum as possible
        that operations can proceed many times until find most minimum

        eg |7 - 4| = 3, |3 - 4| = 1 the min is 1

        the solution is n-k is repeated process, so we can use n % k 
        and check for absolute negative value by min(n % k, (n % k) - k)
    */

    long long n, k;
    cin >> n >> k;

    long long res = n % k;
    res = min(res, abs(res - k));

    cout << res << endl;

    return 0;
}