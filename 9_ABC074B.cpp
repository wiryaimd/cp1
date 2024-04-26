/*
 * Prob: #
 * File Created: Friday, 26th April 2024 11:12:51 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int total = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;

        int minn = min(a, abs(k - a));
        total += minn * 2;
    }

    cout << total << endl;

    return 0;
}