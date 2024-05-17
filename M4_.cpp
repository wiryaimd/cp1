/*
 * Prob: ss
 * File Created: Wednesday, 15th May 2024 10:54:13 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        valid when concat half + half of the string is same and even
        
        delete char at the end of string one by one and check which length is valid concat
    */

    string s;
    cin >> s;

    int r = s.length() - 1;
    while(true){
        if(r % 2 == 1){
            r--;
            continue;
        }

        bool valid = true;
        for(int i = 0; i < r / 2; i++){
            if(s[i] != s[r / 2 + i]){
                valid = false;
            }
        }

        if(valid){
            break;
        }
        r--;
    }

    cout << r << endl;

    return 0;
}