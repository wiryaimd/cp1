/*
 * Prob: 754
 * File Created: Tuesday, 7th May 2024 4:44:02 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    string s;
    cin >> s;

    int minn = INT32_MAX;
    for(int i = 2; i < s.length(); i++){
        int d1 = s[i] - '0';
        int d2 = s[i - 1] - '0';
        int d3 = s[i - 2] - '0';

        int sum = (d3 * 100) + (d2 * 10) + d1;
        minn = min(minn, abs(sum - 753));
    }
    cout << minn << endl;

    return 0;
}