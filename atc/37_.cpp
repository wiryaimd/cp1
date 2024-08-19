/*
 * Prob: Attack Survival
 * File Created: Sunday, 12th May 2024 12:22:14 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    int n, k, q;
    cin >> n >> k >> q;

    int scores[n] = {0};
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;

        scores[a - 1]++;
    }

    for(int i = 0; i < n; i++){
        if(k - (q - scores[i]) > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}