/*
 * Prob: Cracal vs Monster
 * File Created: Sunday, 5th May 2024 8:58:27 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<cmath>

using namespace std;

int main(){

    /*
        h /= 2 when h > 1 and count the loop like in binary-tree formation
    */

    long long h;
    cin >> h;

    long long cnt = 1;
    int t = 1;
    while(h > 1){
        h /= 2;
        cnt += pow(2, t);

        t++;
    }

    cout << cnt << endl;

    return 0;
}