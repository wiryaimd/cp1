/*
 * Prob: ABC 139 B
 * File Created: Wednesday, 24th April 2024 12:05:12 am
 * Author: wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    int minn = 1;
    int cnt = 0;
    while(minn < b){
        minn += a;
        minn -= 1;
        cnt++;
    }

    cout << cnt << endl;


    return 0;
}