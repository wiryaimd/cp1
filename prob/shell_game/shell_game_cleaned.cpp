#include<iostream>

using namespace std;
int main(){ // solusi lebih clean, dan optimized

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    int data[3] = {1, 2, 3};
    int cnt[3] = {0};
    for(int i = 0; i < n; i++){
        int a, b, g;
        cin >> a >> b >> g;

        swap(data[a - 1], data[b - 1]);
        cnt[data[g - 1] - 1]++;
    }

    int maxx = max(cnt[0], max(cnt[1], cnt[2]));
    cout << maxx << endl;

    return 0;
}