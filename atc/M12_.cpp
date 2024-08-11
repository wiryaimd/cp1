/*
 * Prob: Grid Compression, 11mins
 * File Created: Thursday, 23rd May 2024 11:40:05 am
 * Author: Wiryaimd
 */

#include<iostream>

using namespace std;

int main(){

    /*
        given W x H matrix, with char '#' and '.'
            compress the matriks if theres line row '.' or col '.' 
            so that only col and row '#' in between that matrix

        the idea is
            when the line or col is full '.' then skip, otherwise print value
        
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

    bool del_row[h] = {false}; // mark which row is full '.'
    bool del_col[w] = {false}; // same for col
    for(int i = 0; i < h; i++){
        bool del = true;
        for(int j = 0; j < w; j++){
            if(sq[i][j]){
                del = false;
                break;
            }
        }

        del_row[i] = del;
    }

    for(int i = 0; i < w; i++){
        bool del = true;
        for(int j = 0; j < h; j++){
            if(sq[j][i]){
                del = false;
                break;
            }
        }

        del_col[i] = del;
    }

    for(int i = 0; i < h; i++){
        if(del_row[i]){ // if this row full '.' then skip
            continue;
        }
        for(int j = 0; j < w; j++){
            if(del_col[j]){ // if this col full '.' then skip
                continue;
            }
            cout << (sq[i][j] ? '#' : '.'); // else, print it
        }
        cout << endl;
    }

    return 0;
}