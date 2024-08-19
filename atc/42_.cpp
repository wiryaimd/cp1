#include<iostream>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    int data[m] = {0};
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int a;
            cin >> a;
            data[a - 1]++;
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(data[i] == n){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}