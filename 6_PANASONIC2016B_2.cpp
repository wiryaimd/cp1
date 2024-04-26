/*
 * Prob: #
 * File Created: Friday, 26th April 2024 10:41:26 am
 * Author: Wiryaimd
 */


#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int h, w;
    cin >> h >> w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }
    unsigned long long res = ceil((double)((long long)w * h) / 2);
    // or 
    // unsigned long long res = ceil((double)(((long long)w * h) + 1) / 2); // because + 1 will make be even when odd and its always floored by /2
    cout << res << endl;

    return 0;
}