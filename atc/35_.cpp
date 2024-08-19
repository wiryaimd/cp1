/*
 * Prob: Not Found
 * File Created: Sunday, 12th May 2024 9:47:12 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given lowercase string s
        find lowest alphabet (lexicography) that does not occur in string s
    */

    string s;
    cin >> s;

    bool check[26] = {false};
    for(int i = 0; i < s.length(); i++){
        check[s[i] - 'a'] = true;
    }

    for(int i = 0; i < 26; i++){
        if(!check[i]){
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}