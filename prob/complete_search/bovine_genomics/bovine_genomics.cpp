#include<iostream>

using namespace std;
int main(){

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    string spot[n], plain[n];
    for(int i = 0; i < n; i++){
        cin >> spot[i];
    }

    for(int i = 0; i < n; i++){
        cin >> plain[i];
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        bool dupe = false;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(spot[j][i] == plain[k][i]){
                    dupe = true;
                    goto skip;
                }
            }
        }

        skip:

        if(!dupe){
            cnt++;
        }
    }

    cout << cnt << endl;


    /*
        other solution, using hash set

        int poss_positions = 0;
        for (int i = 0; i < m; i++) {
            std::set<char> seen;
            for (int j = 0; j < n; j++) { seen.insert(plain_cows[j][i]); }

            bool dupe = false;
            for (int j = 0; j < n; j++) {
                if (seen.count(spotted_cows[j][i]) > 0) {
                    dupe = true;
                    break;
                }
            }

            if (!dupe) { poss_positions++; }
        }
    */

    return 0;
}