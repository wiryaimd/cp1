#include<iostream>

using namespace std;

int cnt = 0;
const int dim = 8;
bool blocked[dim][dim] = {false};
bool row_taken[dim] = {false};
bool diag1[dim * 2 - 1] = {false}, diag2[dim * 2 - 1] = {false};

void rec(int col){
    if(col == dim){
        cnt++;
        return;
    }

    for(int row = 0; row < dim; row++){
        if(blocked[row][col] || row_taken[row] || diag1[row + col] || diag2[row - col + dim - 1]){
            continue;
        }

        row_taken[row] = diag1[row + col] = diag2[row - col + dim - 1] = true;
        rec(col + 1);

        row_taken[row] = diag1[row + col] = diag2[row - col + dim - 1] = false;
    }
}

int main(){


    for(int i = 0; i < dim; i++){
        string s;
        cin >> s;
        for(int j = 0; j < dim; j++){
            blocked[i][j] = s[j] == '*';
        }
    }

    rec(0);

    cout << cnt << endl;

    return 0;
}