#include<iostream>
#include"Vector.h"
using namespace std;

int main(){
    Vector<int> vec(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    for(int i = 0; i < 3; ++ i){
        cout << vec[i] << endl;
    }
    cout << "[] is tested\n";
    Vector<int>::iterator itr = vec.begin();
    for(itr = vec.begin(); itr != vec.end(); itr++){
         cout << *itr << endl;
    }
}
