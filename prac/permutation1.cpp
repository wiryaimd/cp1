#include<iostream>
#include<algorithm>

using namespace std;
int main(){

    // int data[] = {2, 3, 4, 5}; // data perlu di sort terlebih dahulu,
    int data[] = {1, 2, 3};
    // karena function next_permutation menghasilkan nilai dari paling terurut hingga ke n!

    // 4! == 24 == 4 x 3 x 2 x 1

    int i = 1;
    do{
        cout << i << ": ";
        // cout << data[0] << " hoh " << data[1] << " hoh " << data[2] << " " << data[3] << endl;
        cout << data[0] << " " << data[1] << " " << data[2] << endl;
        i++;
    }while(next_permutation(begin(data), end(data)));
    // function next permut ngeprint berdasarkan lexicographical order

    // next_permutation();

    return 0;
}