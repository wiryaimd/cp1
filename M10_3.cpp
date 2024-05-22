/*
 * Prob: Together
 * File Created: Wednesday, 22nd May 2024 10:00:44 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int a[100003] = {0}; // use 1e5 + 3 because accessing a[i + 2]
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        
        a[x]++; // count each much number
    }

    int maxx = 0;
    for(int i = 0; i < 100001; i++){
        maxx = max(maxx, a[i] + a[i + 1] + a[i + 2]); // find most maximum that near between i, i+1, and i+2
        // because its can make the operation meet the value same using i-1, i, and i+1
    }
    
    cout << maxx << endl;

    return 0;
}