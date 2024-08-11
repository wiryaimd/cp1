/*
 * Prob: Go to School
 * File Created: Friday, 3rd May 2024 1:40:38 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        using index mapping approach
    */

    int n;
    cin >> n;
    int data[n];
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        data[a - 1] = i + 1;
    }

    for(int i = 0; i < n; i++){
        cout << data[i] << " ";
    }

    return 0;
}