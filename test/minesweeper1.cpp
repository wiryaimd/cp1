#include<iostream>

using namespace std;

int main(){

    int h, w;
    cin >> h >> w;

    string s[h];
    for(int i = 0; i < h; i++){
        cin >> s[i];
    }

    // for easily access index at left-top, left, top, top-right, etc
    int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1}; // for row
    int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1}; // for col

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){ // when its bomb, skip
                cout << '#';
                continue;
            }

            int cnt = 0; // count how much near this coordinate have bomb
            for(int k = 0; k < 8; k++){ // loop for 8 times, which is all index angles
                int cx = i + dx[k]; // check all coordinate index
                int cy = j + dy[k];
                if(cx < 0 || cx >= h || cy < 0 || cy >= w){ // check index bounding
                    continue;
                }
                
                if(s[cx][cy] == '#') cnt++; // if theres bomb then count + 1
            }
            cout << cnt;
        }
        cout << endl;
    }
    

    return 0;
}