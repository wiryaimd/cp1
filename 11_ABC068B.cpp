/*
 * Prob: Break Number
 * File Created: Tuesday, 30th April 2024 8:33:23 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        need to know that most counted divisble number from 1 to 100 is
        2^n which is
        [2, 4, 16, 32, 64]
    */

    int n;
    cin >> n;

    int maxx = 0;
    int num = 1;
    for(int i = n; i > 0; i--){
        int cnt = 0;
        int k = i;
        while(k % 2 == 0){
            k /= 2;
            cnt++;
        }
        if(cnt > maxx){
            maxx = cnt;
            num = i;
        }
    }

    cout << num << endl;

    return 0;
}