#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> res;
    do{
        res.push_back(s);
    }while(next_permutation(s.begin(), s.end()));

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}