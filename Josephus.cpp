#include<iostream>
#include"DoublyLinkedList.h"
using namespace std;

DoublyLinkedList<int> josephus;

void create(int n){
    for(int i = 1; i <= n; i++){
        josephus.push_back(i);
    }
}
