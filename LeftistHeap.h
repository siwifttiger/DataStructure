#ifndef LEFTISTHEAP_H
#define LEFTISTHEAP_H
#include<iostream>
template<typename Comparable>
class LeftistHeap{
    public:
        LeftistHeap(){

        }

        LeftistHeap(const LeftistHeap& rhs){

        }

        ~LeftistHeap(){

        }

        bool isEmpty() const {

        }

        const Comparable& findMin() const{

        }

        void insert(const Comparable& x){

        }

        void deleteMin(){

        }

        void deleteMin(Comparable & x){

        }

        void makeEmpty(){

        }

        void merge(LeftistHeap& rhs){

        }

        const LeftistHeap& operator=(const LeftistHeap& rhs){

        }

    private:
        struct LeftistNode{
          Comparable element;
          LeftistNode *left;
          LeftistNode *right;
          int npl;
          LeftistNode(const Comparable& theElement,LeftistNode *lt = NULL, LeftistNode *rt = NULL,
                  int theNpl = 0)
              :element(theElement),left(lt),right(rt),npl(theNpl){

              }
        };

        LeftistNode *merge(LeftistNode *h1,LeftistNode *h2){

        }

        LeftistNode *merge1(LeftistNode *h1, LeftistNodee *h2){

        }

        void swapChildren(LeftisNode *t){

        }

        void reclaimMemory(LeftistNode *t){

        }

        LeftistNode *clone(LeftistNode *t) const{

        }

};


#endif
