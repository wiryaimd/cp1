#include<iostream>
#include<vector>
#include<climits>

using namespace std;

vector<int> subset;
long long minn = LLONG_MAX;

void generate(int n, int data[], long long total, int index){
    if(index == n){
        long long cnt = 0;
        for(int i = 0; i < subset.size(); i++){
            cnt += subset[i];
        }

        minn = min(minn, abs(cnt - (total - cnt)));
        return;
    }

    subset.push_back(data[index]);
    generate(n, data, total, index + 1);

    subset.pop_back();
    generate(n, data, total, index + 1);
}

int main(){

    int n;
    cin >> n;

    int data[n];
    long long total = 0;
    for(int i = 0; i < n; i++){
        cin >> data[i];
        total += data[i];
    }

    generate(n, data, total, 0);

    cout << minn << endl;


    return 0;
}