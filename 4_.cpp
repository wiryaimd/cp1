/*
 * Prob: #
 * File Created: Wednesday, 24th April 2024 10:45:54 pm
 * Author: Adnya Sutha
 */


#include<iostream>

using namespace std;

int main(){

    int n;
    cin >> n;
    
    for(int i = n; i > 0; i--){
        // cout << "cek " << (int)(i * 1.08) << endl;
        if((int)(i * 1.08) == n){
            cout << i << endl;
            return 0;
        }

        // anti cast to int, *108 and /100 instead
        // if (i * 108 / 100 == N)
        // {
        //     cout << i << endl;
        //     return 0;
        // }
    }

    cout << ":(" << endl;

    return 0;
}