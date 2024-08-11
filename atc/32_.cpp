/*
 * Prob: #
 * File Created: Saturday, 11th May 2024 5:13:27 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    // increment when 'I' and dec when 'D', count the maximum for each operation

    int n;
    string s;

    cin >> n >> s;

    int x = 0;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'I'){
            x++;
        }else{
            x--;
        }

        maxx = max(maxx, x);
    }

    cout << maxx << endl;

    return 0;
}