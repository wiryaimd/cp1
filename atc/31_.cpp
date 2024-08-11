/*
 * Prob: Varied
 * File Created: Saturday, 11th May 2024 5:05:12 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        check if all alphabet in string are unique
    */

    string s;
    cin >> s;

    bool alp[26] = {false};
    bool unique = true;
    for(int i = 0; i < s.length(); i++){
        if(alp[s[i] - 'a']){
            unique = false;
            break;
        }
        alp[s[i] - 'a'] = true;
    }

    cout << (unique ? "yes" : "no") << endl;

    return 0;
}