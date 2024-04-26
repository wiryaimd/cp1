/*
 * Prob: #
 * File Created: Friday, 26th April 2024 9:22:08 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    pair<int, int> pos[101];
    bool flag[3][3];

    for(int i = 0; i < 101; i++){
        pos[i] = make_pair(-1, -1);
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int a;
            cin >> a;
            pos[a] = make_pair(i, j);
            flag[i][j] = false;
        }
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        if(pos[b].first == -1){
            continue;
        }

        flag[pos[b].first][pos[b].second] = true;
    }

    for(int i = 0; i < 3; i++){
        bool r, c, d1, d2;
        r = c = d1 = d2 = true;
        for(int j = 0; j < 3; j++){
            if(!flag[i][j]){
                r = false;
            }
            if(!flag[j][i]){
                c = false;
            }
            if(!flag[j][j]){
                d1 = false;
            }
            if(!flag[3 - j - 1][j]){
                d2 = false;
            }
        }

        if(r || c || d1 || d2){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}