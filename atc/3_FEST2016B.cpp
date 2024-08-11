/*
 * Prob: #
 * File Created: Wednesday, 24th April 2024 10:13:58 pm
 * Author: Adnya Sutha
 */


#include<iostream>

using namespace std;

int main(){

    int n, a, b;
    string s;

    cin >> n >> a >> b >> s;

    int cnt = 0;
    int bth = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'c'){
            cout << "No" << endl;
            continue;
        }

        if(s[i] == 'a'){
            if(cnt < a + b){
                cnt++;
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
            continue;
        }

        if(s[i] == 'b'){
            if(bth >= b || cnt >= a + b){
                cout << "No" << endl;
                continue;
            }

            bth++;
            cnt++;
            cout << "Yes" << endl;
        }
    }

    return 0;
}