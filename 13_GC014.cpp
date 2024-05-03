/*
 * Prob: Cookies Exchange
 * File Created: Friday, 3rd May 2024 10:51:20 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){


    /*
        a = 4, b = 12, c = 20
        step:
        a = 12/2 + 20/2 = 6+10 = 16
        b = 4/2 + 20/2 = 2+10 = 12
        c = 4/2 + 12/2 = 2+6 = 8
        16, 12, 8 (all even) continue loop until some a, b or c is odd
    */

    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    while(a % 2 == 0 && b % 2 == 0 && c % 2 == 0){
        int a1 = (b + c) / 2;
        int b1 = (a + c) / 2;
        int c1 = (a + b) / 2;
        a = a1, b = b1, c = c1;
        cnt++;
        // cout << a << " " << b << " " << c << endl;
        if(cnt > 1000){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << cnt << endl;

    return 0;
}