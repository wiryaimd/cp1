#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cmath>

#define debug(x) std::cerr << (#x) << " " << (x) << std::endl;
#define br std::cerr << std::endl;

using ll = long long;

std::vector<int> v;

void f(int data[], int index){
    if(index == 3){
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
        return;
    }

    v.push_back(data[index]);
    f(data, index + 1);

    v.pop_back();
    f(data, index + 1);
}

int main(){

    int data[3] = {1, 2, 3};
    f(data, 0);

    return 0;
}