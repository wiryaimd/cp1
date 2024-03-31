/*
 * Author: Wiryaimd
 * File Created: Sunday, 31st March 2024 4:26:34 pm
 * USACO cow gymnastics, 38mins cuz wrong using data[k][pos - 1] = j instead of data[i][pos - 1] = j
 */


#include<iostream>

using namespace std;
int main(){

    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;
    cin >> k >> n;

    int data[k][n];
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            int pos;
            cin >> pos;

            data[i][pos - 1] = j;
        }
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            bool left = true;
            bool right = true;
            for(int l = 0; l < k; l++){
                if(data[l][i] > data[l][j]){
                    left = false;
                }

                if(data[l][i] < data[l][j]){
                    right = false;
                }
            }

            if(left || right){
                cnt++;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}