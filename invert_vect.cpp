#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    cout << "Vect: ";
    int size = vec.size();
    for(int i=0; i<size; i++){
        cout << vec[i] << " ";
    }

    cout << "Size: " <<size;
    cout << endl;

    for (int i=0; i<size; i++){
        vec[i] = vec[size-i];
    }

    cout << "New Vect: ";
    for(int i=0; i<size; i++){
        cout << vec[i] << " ";
    }

    return 0;
}
