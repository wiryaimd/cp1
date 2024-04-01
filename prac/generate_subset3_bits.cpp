#include<iostream>
#include<vector>
#include<set>

using namespace std;
int main(){

    int n = 3;
    // for (int b = 0; b < (1<<n); b++) {
    //     vector<int> subset;
    //     for (int i = 0; i < n; i++) {
    //         if (b&(1<<i)) subset.push_back(i);
    //     }

    //     for(int j = 0; j < subset.size(); j++){
    //         cout << subset[j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i = 0; i < (1 << n); i++){ // 1<<n == 2^n == 2^3 == 8
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                v.push_back(j);
            }
        }

        for(int j = 0; j < v.size(); j++){
            cout << v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}