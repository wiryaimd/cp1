/*
 * Prob: Coins
 * File Created: Sunday, 12th May 2024 9:19:48 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        complete search approach

        you have 'A' 500 yen coin, 'B' 100, and 'C' 50.
        count how many ways you can using the coins to pay 'X'
    */

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int cnt = 0;
    for(int i = 0; i <= a; i++){ // complete search all when using 1, 500yen coins to A yen
        for(int j = 0; j <= b; j++){ // same until B
            for(int k = 0; k <= c; k++){

                // and then if specific i, j, k coins value is same with X then count
                int curr = (i * 500) + (j * 100) + (k * 50);
                if(curr == x){
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}