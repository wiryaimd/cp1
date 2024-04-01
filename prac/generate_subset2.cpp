#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<int> subset;
// int data[3] = {1, 2, 3}; // data is ambigious, karena nama var data, sudah ada yg pakai di namespace std;
int data_all[3] = {1, 2, 2};
int n = 3;

set<vector<int>> res;

void generate_subset(int index){
    if(index == n){
        vector<int> sub;
        for(int i = 0; i < subset.size(); i++){
            cout << subset[i] << " ";
            sub.push_back(subset[i]);
        }
        cout << "" << endl;
        res.insert(sub);
        return;
    }

    // decision include to vector<> subset
    subset.push_back(data_all[index]);
    generate_subset(index + 1);

    // decision NOT include to vector<> subset
    subset.pop_back();
    generate_subset(index + 1);
}

int main(){

    generate_subset(0);
    cout << "cek" << endl;
    for(vector<int> sub : res){
        for(int j = 0; j < sub.size(); j++){
            cout << sub[j] << " ";
        }
        cout << endl;
    }

    return 0;
}