/*
 * Prob: Sentou, 10mins
 * File Created: Monday, 27th May 2024 2:04:31 pm
 * Author: Wiryaimd
 */

#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        count total sec times water draining when shower pressed for T sec

        other more clean solution see _2.cpp
    */

    int n, t;
    cin >> n >> t;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int t0 = a[0];
    unsigned long long total = 0;
    for(int i = 1; i < n; i++){
        int dif = a[i] - t0;
        t0 = a[i];
        if(dif > t){
            total += t;
            continue;
        }
        // debug(dif); // comment debug() for more fast time when submit
        total += dif;
    }

    total += t;

    cout << total << endl;

    return 0;
}