#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n, k;
    cin >> k >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);

    int minn = min((k + data[0]) - data[n - 1], data[n - 1] - data[0]);
    // for(int i = 0; i < n; i++){
    //     int r = k - data[i];
    //     int l = data[i];
    //     minn += min(l, r);
    // }

    // minn -= start;

    cout << minn << endl;

    return 0;
}