/*
 * Prob: Bingo
 * File Created: Friday, 26th April 2024 8:02:42 pm
 * Author: Wiryaimd
 */


#include<iostream>

using namespace std;

int main(){

    /*
        yes, if theres bingo pattern in 3x3 sheet by selecting index from specific given number
        otherwise, no
    */

    pair<int, bool> sheet[3][3];
    pair<int, int> pos[105];
    for(int i = 0; i < 105; i++){
        pos[i] = {-1, -1};
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int a;
            cin >> a;
            pos[a] = make_pair(i, j);
            sheet[i][j] = make_pair(a, false);
        }
    }

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int b;
        cin >> b;
        if(pos[b].first == -1 || pos[b].second == -1){
            continue;
        }
        sheet[pos[b].first][pos[b].second].second = true;
        // printf("cek %d %d\n", pos[b].first, pos[b].second);
    }

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << sheet[i][j].second << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < 3; i++){
        bool r = true, c = true;
        bool d1 = true, d2 = true;
        for(int j = 0; j < 3; j++){
            if(!sheet[i][j].second){
                r = false;
            }

            if(!sheet[j][i].second){
                c = false;
            }

            if(!sheet[j][j].second){
                d1 = false;
            }

            if(!sheet[3 - j - 1][j].second){
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