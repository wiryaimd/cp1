/*
 * Prob: Can you solve this?
 * File Created: Thursday, 25th April 2024 8:36:46 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        2d multiplier
    */

    int n, m, c;
    cin >> n >> m >> c;

    int b[m];

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        int total = 0;
        for(int j = 0; j < m; j++){
            int a;
            cin >> a;
            total += a * b[j];
        }

        total += c;

        if(total > 0){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
