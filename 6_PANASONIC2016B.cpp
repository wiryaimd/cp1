/*
 * Prob: #
 * File Created: Friday, 26th April 2024 10:23:54 am
 * Author: Wiryaimd
 */


#include<iostream>
#include<cmath>

using namespace std;

int main(){

    /*
        how much square the bishop can move, start from top-left
    */

    int h, w;
    cin >> h >> w;

    if(h == 1 || w == 1){
        cout << 1 << endl;
        return 0;
    }

    unsigned long long res = 0;
    long long f = ceil((double)w / 2);
    long long s = w / 2;

    long long half = h / 2;
    if(h % 2 == 0){
        res += f * half;
        res += s * half;
    }else{
        res += f * (half + 1);
        res += s * half;
    }

    cout << res << endl;

    return 0;
}