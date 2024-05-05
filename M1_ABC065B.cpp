/*
 * Prob: Trained?
 * File Created: Sunday, 5th May 2024 9:21:37 pm (5mins)
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given xi value with n size,
        
        traverse value from x[x[i]] until found x == 2
        initial start from x[0]

        if impossible, print -1.
        you can check possibility by check if x[i]-th value already passed before
    */

    int n;
    cin >> n;

    int data[n];
    bool pass[n] = {false};
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    int curr = data[0];
    int cnt = 0;
    while(true){
        if(pass[curr - 1]){
            cout << -1 << endl;
            return 0;
        }

        cnt++;

        pass[curr - 1] = true;
        if(curr == 2){
            break;
        }
        curr = data[curr - 1];
    }

    cout << cnt << endl;

    return 0;
}