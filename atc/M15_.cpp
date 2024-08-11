/*
 * Prob: KEYENCE (14mins?)
 * File Created: Monday, 27th May 2024 10:34:52 am 
 * Author: Wiryaimd
 */


#include<iostream>
#define debug(x) cerr << (#x) << " " << (x) << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        given string s;
        find if s can be "keyence" if we remove contiguous substring only once
    */

    string s;
    cin >> s;

    string key = "keyence";
    int k = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == key[k]){
            k++;
            continue;
        }
        break;
    }

    int rem = key.length() - k;
    bool valid = false;
    string a = s.substr(s.length() - rem, rem);
    string b = key.substr(k, key.length() - k);
    debug(a); debug(b);
    if(a == b){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    /*
        more optmize solution:
        just brute force all possible substring, eg if(s.start + s.end == "keyence")

        for (int i = 0; i < S.size(); i++) {
            for (int j = i - 1; j < S.size(); j++) {
                string V = S.substr(0, i) + S.substr(j + 1, S.size() - (j + 1));
                if (V == "keyence") {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
        cout << "NO" << endl;
    */

    return 0;
}