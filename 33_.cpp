/*
 * Prob: Postal Code
 * File Created: Saturday, 11th May 2024 5:19:42 pm
 * Author: Wiryaimd
 */

#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    string s;
    cin >> s;

    if(s[a] == '-' && count(s.begin(), s.end(), '-') == 1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    // int cnta = 0;
    // bool hyphen = false;
    // bool valid = true;
    // for(int i = 0; i < a + b + 1; i++){
    //     if(i == a){
    //         if(s[i] != '-'){
    //             valid = false;
    //             break;
    //         }
    //         hyphen = true;
    //         continue;
    //     }

    //     if(hyphen && !isdigit(s[i])){
    //         valid = false;
    //         break;
    //     }
    // }

    // cout << (valid ? "Yes" : "No") << endl;

    return 0;
}