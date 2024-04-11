#include<iostream>
#include<vector>

using namespace std;

const int n = 3;

vector<int> v;
bool chosen[n];
int data[n] = {1, 2, 3};

void permut(){
    if(v.size() == n){
        for(int i = 0; i < n; i++){
            cout << v[i] << " ";
        }

        cout << " permut " << endl;
        return;
    }

    for(int i = 0; i < n; i++){
        if(chosen[i]){
            continue;
        }

        chosen[i] = true;
        v.push_back(data[i]);

        permut();

        chosen[i] = false;
        v.pop_back();
    }
}

int main(){

    permut();

    return 0;
}