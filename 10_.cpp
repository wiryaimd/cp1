/*
 * Prob: Card Game for Two
 * File Created: Tuesday, 30th April 2024 8:16:35 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }
    sort(data, data + n);

    int a = 0, b = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            a += data[i];
        }else{
            b += data[i];
        }
    }

    cout << abs(a - b) << endl;

    return 0;
}