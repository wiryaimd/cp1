/*
 * Prob: Cut and Count
 * File Created: Tuesday, 21st May 2024 11:50:52 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given string S
        it will split into two string X and Y

        count how many possible character that 'contains' in both X and Y string
        when it split at xi to s.len string

        eg
        aabbca
        the possible max is = 2
        left = aab (a, b)
        right = bca (a, b)
        
    */

    int n;
    cin >> n;

    string s;
    cin >> s;

    int maxx = 0;

    for(int i = 1; i < n; i++){
        bool l[26] = {false}, r[26] = {false};
        for(int j = 0; j < i; j++){
            l[s[j] - 'a'] = true;
        }
        for(int j = i; j < n; j++){
            r[s[j] - 'a'] = true;
        }
        
        int cnt = 0;
        for(int j = 0; j < 26; j++){
            if(l[j] && r[j]){
                cnt++;
            }
        }

        maxx = max(maxx, cnt);
    }

    cout << maxx << endl;

    return 0;
}