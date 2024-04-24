/*
 * Prob: #
 * File Created: Wednesday, 24th April 2024 10:00:53 pm
 * Author: Adnya Sutha
 */


#include<iostream>
#include<cmath>

using namespace std;

int main(){

    int n;
    cin >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    int minn = INT32_MAX;
    for(int i = 0; i < 100; i++){
        int count = 0;
        for(int j = 0; j < n; j++){
            count += pow(data[j] - (i + 1), 2);
        }

        if(count < minn){
            minn = count;
        }
    }

    cout << minn << endl;

    return 0;
}