/*
 * Prob: Irreversible operation
 * File Created: Monday, 6th May 2024 10:10:35 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        count how much B and W can swap
        swap only able when B before W (eg: BBBWBWBBW) -> (final: WWWBBBBBB)

        just count B to the last n position - num_passed_b (pos)
    */

    freopen("M2.in", "r", stdin);

    string s;
    cin >> s;

    int n = s.length();
    // cout << n << endl;
    long long cnt = 0;
    int pos = 0;
    for(int i = 0; i < n; i++){
        if(s[n - i - 1] == 'B'){
            cnt += i - pos;
            pos++;
        }
    }

    cout << cnt << endl;

    return 0;
}