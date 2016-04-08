#include<iostream>
#include"Vector.h"
#include"DoublyLinkedList.h"
//#include"List.h"
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
    DoublyLinkedList<int> douLinkedList;
    DoublyLinkedList<int>::iterator itr1 = douLinkedList.begin();
    douLinkedList.push_back(1);

    douLinkedList.push_back(2);
    douLinkedList.push_back(3);
   for(;itr1 != douLinkedList.end(); itr1++){
         cout << *itr1 << endl;
   }   
    while(!douLinkedList.empty()){
         cout << douLinkedList.back() << endl;
         douLinkedList.pop_back();
    }
}
