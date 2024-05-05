/*
 * Prob: Candy Distribution Again
 * File Created: Saturday, 4th May 2024 7:12:33 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    /*
        sorting approach problem
    */

    int n, x;
    cin >> n >> x;
    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);

    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(x < data[i]){
            break;
        }
        x -= data[i];
        cnt++;
    }

    if(cnt == n && x > 0){
        cnt--;
    }

    cout << cnt << endl;

    return 0;
}