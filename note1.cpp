#include<iostream>

using namespace std;
int main(){

    // tuple, mirip seperti pair<> tapi ini bisa lebih dari 2 var
    tuple<int, int, string> t;
    tuple<int, string> t2; // tuple 2 var jg bisa kek pair<>
    // t = make_tuple(2, 3, "tot"); // atau
    t = {3, 5, "asede"};
    t2 = {10, "hoam"};

    int t1 = get<1>(t); // untuk get value tuple index ke 1
    string t2_1 = get<1>(t2);
    cout << "t1: " << t1 << endl;
    cout << "t2 s: " << t2_1 << endl;

    // lambda
    int lam = [](int a, int b){ // ngga perlu return type actually, (biasanya perlu (int a, int b)->int )
        a++; b++;
        return a * b;
    }(3, 4);
    cout << lam << endl;

    

    return 0;
}