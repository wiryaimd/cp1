/*
 * Author: Wiryaimd
 * File Created: Saturday, 30th March 2024 9:10:52 pm
 * USACO bovine shuffle, simulation, 9.10-9.43
 */


#include<iostream>

using namespace std;
int main(){

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;

    int swap[n];
    for(int i = 0; i < n; i++){
        cin >> swap[i];
    }

    int data[4][n];
    for(int i = 0; i < n; i++){
        cin >> data[0][i];
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            data[i + 1][j] = data[i][swap[j] - 1];
            // data[swap[j] - 1] = tmp;

            // untuk inversenya bisa pakai
            // data[i + 1][swap[j] - 1] = data[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        cout << data[3][i] << endl;
    }

    return 0;
}