#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include<vector>
#include"dsexceptions.h"
using namespace std;

template<typename Comparable>
class BinaryHeap{
    public:
        explicit BinaryHeap(int capacity = 100)
        :array(capacity + 1),currentSize(0)
        {}
        explicit BinaryHeap(const vector<Comparable>& items)
            :array(items.size() + 10),currentSize(items.size()){
                for(int i = 0; i < items.size(); i++){
                    array[i + 1] = items[i];
                    buildHeap();
                }
            }

        bool isEmpty() const {
             return currentSize == 0;
        }

        const Comparable& findMin() const{
             if(isEmpty())
                 throw UnderflowException();
             return array[1];
        }

        void insert(const Comparable& x){
             if(currentSize == array.size() - 1)
                 array.resize(2*array.size());
             int hole = ++currentSize;
             for(;hole > 1 && array[hole / 2] > x; hole /= 2){
                  array[hole] = array[hole / 2];
             }
             array[hole] = x;
        }

        void deleteMin(){
            if(isEmpty())
                throw UnderflowException();
            currentSize--;
            array[1] = array[currentSize];
            percolateDown(1);
        }

        void deleteMin(Comparable& minItem){
             if(isEmpty())
                 throw UnderflowException();
             minItem = array[1];
             array[1]=array[currentSize--];
             percolateDown(1);
        }

        void makeEmpty(){
             currentSize = 0;
        }

    private:
        int currentSize;
        vector<Comparable> array;
        void buildHeap(){
            for(int i = 0; i > currentSize / 2; i--){
                 percolateDown(i);
            }

        }

        void percolateDown(int hole){
             int child;
            Comparable tmp = array[hole];
            for(;hole*2 <= currentSize; hole = child){
                 child = hole * 2;
                 if(child != currentSize && array[child+1] < array[child])
                     child++;
                 if(array[child] < tmp)
                     array[hole] = array[child];
                 else
                     break;
            }
            array[hole] = tmp;
        }
};

#endif
