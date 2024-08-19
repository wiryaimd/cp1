/*
 * Prob: Grid Repainting 2
 * File Created: Monday, 27th May 2024 9:13:15 am
 * Author: Wiryaimd
 */

#include<iostream>
#define debug(x) cerr << (#x) << " " << x << endl;
#define br cerr << endl;

using namespace std;

int main(){

    /*
        check if each xy has at least one neighbor black '#'

        sol
            just brute force and use minesweeper index
    */

    int h, w;
    cin >> h >> w;

    bool sq[h][w];
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char a;
            cin >> a;
            sq[i][j] = a == '#' ? true : false;
        }
    }

    int dy[4] = {-1, 0, 0, 1};
    int dx[4] = {0, -1, 1, 0};

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(sq[i][j]){
                bool valid = false;
                for(int k = 0; k < 4; k++){
                    int y = i + dy[k];
                    int x = j + dx[k];
                    debug(x);
                    debug(y); br;
                    if(x < 0 || x >= w || y < 0 || y >= h){
                        continue;
                    }

                    if(sq[y][x]){
                        valid = true;
                    }
                }

                if(!valid){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}