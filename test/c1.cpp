#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main(){

    set<int> a = {1, 2 ,3 ,4};
    // generate_subset(0);

    for(int m : a){
        cout << m << endl;
    }

    cout << "ya " << a.count(3) << endl;

    cout << "2^4: " << (1 << 4) << endl;

    cout << (0x1010011 & 0x100) << endl; // 0 == false, if > 0 (1, 2, 13, 15.. dst == true)
    // if(0x1010011 & 0x111){
    // if(0x1010011 & 0x010){
    if(0x1010011 & 0x100){
        cout << "t" << endl;
    }
    
    int gcdres = gcd(102408, 42512);
    cout << gcdres << endl;
    

    return 0;
}