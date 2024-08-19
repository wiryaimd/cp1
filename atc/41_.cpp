/*
 * Prob: #
 * File Created: Tuesday, 14th May 2024 10:37:30 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        count how much i that xi < xj
        when j < i

        the solution is just count how much xi > most_minimum then n - cnt
    */

    int n;
    cin >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    int minn = data[0];
    int cnt = 0;
    for(int i = 1; i < n; i++){
        if(data[i] > minn){
            cnt++;
        }
        minn = min(minn, data[i]);
    }

    cout << (n - cnt) << endl;

    return 0;
}