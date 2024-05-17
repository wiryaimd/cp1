/*
 * Prob: Minesweeper
 * File Created: Friday, 17th May 2024 10:53:57 pm
 * Author: Wiryaimd
 */


#include<iostream>
#include<vector>

using namespace std;

int main(){

    /*
        just like minesweeper game.

        count how much bom near '#'
    */

    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }

    vector<vector<int>> num(h, vector<int>(w, 0));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                if(i > 0){
                    num[i - 1][j]++;
                    if(j < w - 1) num[i - 1][j + 1]++;
                    if(j > 0) num[i - 1][j - 1]++;
                }

                if(i < h - 1){
                    num[i + 1][j]++;
                    if(j > 0) num[i + 1][j - 1]++;
                    if(j < w - 1) num[i + 1][j + 1]++;
                }
                
                if(j < w - 1) num[i][j + 1]++;
                if(j > 0) num[i][j - 1]++;
            }
        }
    }    

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                cout << "#";
                continue;
            }
            cout << num[i][j];
        }

        cout << endl;
    }

    return 0;
}