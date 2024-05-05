/*
 * Prob: Chocolate
 * File Created: Saturday, 4th May 2024 7:55:51 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        find total chocolate before ated (x is remaining chocolate).
        ated for t * a-ith + 1 times in d days
    */

    int n, d, x;
    cin >> n >> d >> x;

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        cnt++;

        int t = 1;
        while(true){
            int m = t * a + 1;
            // cout << a << endl;
            if(m > d){
                break;
            }
            cnt++;
            t++;
        }
    }

    cout << cnt + x << endl;

    return 0;
}