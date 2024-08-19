/*
 * Prob: ATCoder
 * File Created: Friday, 3rd May 2024 3:49:52 pm
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        count longest substring that contains 'ACGT' in the string
    */

    string s;
    cin >> s;

    int maxx = 0;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'){
            cnt++;
        }else{
            cnt = 0; // reset if s[i] not contain A C G or T
        }
        maxx = max(maxx, cnt);
    }

    cout << maxx << endl;

    return 0;
}