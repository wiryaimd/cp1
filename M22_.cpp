/*
 * Prob: #
 * File Created: Sunday, 2nd June 2024 11:08:36 pm
 * Author: Wiryaimd
 */

#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

#include<cmath>

using namespace std;

int main(){

    /*
        WA, see _2.cpp
    */

    int n, k;
    cin >> n >> k;

    double res = 0;
    for(int i = 1; i <= n; i++){
        unsigned long long pw = ceil(log(k / i) / log(2));
        double cnt = (double)1/n * pow(0.5, pw);
        res += cnt;
    }

    cout << res << endl;

    return 0;
}