#ifndef STACK_H
#define STACK_H
#include "DoublyLinkedList.h"
template<typename Object>
class Stack{
    private:
        DoublyLinkedList<Object> list;
    public:
        Stack(){}
        bool empty() const{
            return list.empty();
        }

        int size() const{
             return list.size();
        }

        void push_back(const Object& item){
            list.push_back(item);
        }

        void pop(){
             list.pop_back();
        }
        Object& top(){
            return list.back();
        }

        void  top(Object& data){
             data = list.back();
        }
        void clear(){
             list.clear();
        }
};

#endif
