#include<iostream>
#include<vector>

using namespace std;

vector<int> subset;

void generate_subset(int data[], int n, int index){
    if(index == n){
        for(int i = 0; i < subset.size(); i++){
            cout << subset[i] << " ";
        }
        cout << "crot " << endl;
        return;
    }

    generate_subset(data, n, index + 1);
    subset.push_back(data[index]);

    generate_subset(data, n, index + 1);
    subset.pop_back();
}

int main(){

    int data[3] = {1, 2, 3};
    generate_subset(data, 3, 0);

    return 0;
}