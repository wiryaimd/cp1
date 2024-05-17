/*
 * Prob: #
 * File Created: Monday, 13th May 2024 6:51:17 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    // using sort apprpoach

    int n;
    cin >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    int ori[n];
    copy(data, data + n, ori);
    sort(data, data + n);

    for(int i = 0; i < n; i++){
        if(ori[i] == data[n - 1]){
            cout << data[n - 2] << endl;
        }else{
            cout << data[n - 1] << endl;
        }
    }

    
    return 0;
}