/*
 * Prob: Together
 * File Created: Wednesday, 22nd May 2024 10:00:44 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given n data
        at x-th value

        find most possible maximum value that is same.
        you can perform either x, x+1, x-1 to the value to get most max

        printout to max num

        nb:
            you can bruteforce O n^2 each possiblelity but will TLE.

            otherwise

            count all possible value that +1 +0 -1 to a[] then find most max

        see other most common solution _3.cpp
    */

    int n;
    cin >> n;

    int a[100003] = {0}; // notice that, its 1e5 + 3 instead of 1e5 because it also count a[x + 2]
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        a[x]++;
        a[x + 1]++;
        a[x + 2]++;
    }

    int maxx = 0;
    for(int i = 0; i < 100003; i++){
        maxx = max(maxx, a[i]);
    }
    
    cout << maxx << endl;

    return 0;
}