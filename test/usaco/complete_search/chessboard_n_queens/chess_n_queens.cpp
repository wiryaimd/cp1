#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    // using permutation method

    int dim = 8;

    // bool cek[dim * 2 - 1]; // not initialized value not always == 0, but theres 34, 21, 52 etc, so theres some true (set default instead)
    // for(int i = 0; i < dim * 2 - 1; i++){
    //     printf("%d ", cek[i]);
    // }

    bool blocked[dim][dim];
    for(int i = 0; i < dim; i++){
        string s;
        cin >> s;

        for(int j = 0; j < dim; j++){
            blocked[i][j] = s[j] == '*';
        }
    }
    
    vector<int> queens = {0, 1, 2, 3, 4, 5, 6, 7};
    int cnt = 0;
    do{

        bool works = true;

        for (int i = 0; i < dim; i++){ // i == row
            if(blocked[queens[i]][i]){
                works = false;
                break;
            }
        }

        bool taken[dim * 2 - 1] = {false}; // set default value to false MUST IMPORTANT!
        bool taken2[dim * 2 - 1] = {false};

        for(int i = 0; i < dim; i++){
            if(taken[i + queens[i]]){
                works = false;
                break;
            }
            taken[i + queens[i]] = true;
        }

        for(int i = 0; i < dim; i++){
            // int inv = (dim - i - 1) + (dim - queens[i] - 1); // wrong index
            int inv = queens[i] - i + dim - 1;
            if(taken2[inv]){
                works = false;
                break;
            }
            taken2[inv] = true;
        }
        
        if(works){
            cnt++;
        }

    }while(next_permutation(queens.begin(), queens.end()));

    cout << cnt << endl;

    return 0;
}

