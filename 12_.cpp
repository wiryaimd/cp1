#include<iostream>
#include<algorithm>

using namespace std;
int main(){

    /*
        there circular pound around pool with perimeter of K meters,
        and N house with Ai-th distance from top/northest position

        find minimum distance to travel all N house from i-th house

        the solution is sort Ai-th distance each, and check most minimum of total distance between house[i] to house[i - 1].
        
        for simplify
        you can using (k - data[i]) + data[i - 1] from i = 1 < n
        and data[n - 1] - data[0]; for i = 0
    */

    int n, k;
    cin >> k >> n;

    int data[n];
    for(int i = 0; i < n; i++){
        cin >> data[i];
    }

    sort(data, data + n);

    int minn = INT32_MAX;
    for(int i = 0; i < n; i++){
        // distance from house[i] to house[i - 1]
        // avoiding negative index
        int pos = (n + i - 1) % n;
        // cout << "pos " << pos << endl;
        if(pos < i){
            minn = min(minn, (k - data[i]) + data[pos]);
        }else{
            minn = min(minn, data[pos] - data[i]);
        }
    }

    cout << minn << endl;

    return 0;
}