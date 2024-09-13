#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){

    int n, q;
    string s;
    cin >> n >> s >> q;

    string a[q];
    for(int i = 0; i < q; i++){
        cin >> a[i];
    }

    for(int i = 0; i < q; i++){
        if(a[i] == s){
            cout << "YES" << endl;
            continue;
        }

        bool valid = true;
        int skip = 1;
        int curr = 0;
        for(int j = 0; j < n; j++){
            if(s[n - j - 1] == a[i][curr]){
                if(skip != 1){
                    if(s.substr(n - j - 1, skip) == a[i].substr(curr, skip)){
                        skip = 1;
                    }else{
                        // valid = false;
                        skip++;
                        continue;
                    }
                }
                curr = j + 1;
                continue;
            }

            skip++;
        }

        // if(skip != 1){
        //     cout << "NO" << endl;
        // }
        
        cout << (skip == 1 ? "YES" : "NO") << endl;
    }

    return 0;
}