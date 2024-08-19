/*
 * Prob: #
 * File Created: Sunday, 12th May 2024 6:31:49 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given n data
        find most maximum from n data that not include i-th value
    */

    // using first maximum and second maximum approach

    int n;
    cin >> n;

    int maxx = 0;
    int maxx2 = 0;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];

        if(a[i] >= maxx){
            maxx2 = maxx;
            maxx = a[i];
        }

        if(a[i] > maxx2 && a[i] < maxx){
            maxx2 = a[i];
        }
    }

    for(int i = 0; i < n; i++){
        if(a[i] == maxx){
            cout << maxx2 << endl;
        }else{
            cout << maxx << endl;
        }
    }

    return 0;
}