#ifndef AVLTREE_H
#define AVLTREE_H
#include<iostream>
#include"dsexceptions.h"
using namespace std;

template<typename Comparable>
class AVLTree{
    public:
        AVLTree(){
		root = NULL;
        }

        AVLTree(const AVLTree & rhs){
		root = NULL;
            *this = rhs;
        }

    const AVLTree & operator=( const AVLTree & rhs )
    {
        if( this != &rhs )
        {
            makeEmpty( );
            root = clone( rhs.root );
        }
        return *this;
    }

        ~AVLTree(){
            makeEmpty();
        }

        const Comparable& findMin() const{
	   	if(isEmpty()){throw UnderflowException();}
            return findMin(root)->data;
        }

        const Comparable& findMax() const{
	           if(isEmpty()){throw UnderflowException();}  
	     return findMax(root)->data;
        }

        bool contains(const Comparable& x) const{
            return contains(x,root);
        }

        bool isEmpty() const{
            return root==NULL;
        }
        void makeEmpty(){
            makeEmpty(root);
        }

        void insert(const Comparable& x){
            insert(x,root);
        }
        void remove(const Comparable& x){

        }



        void printTree() const{
            if(root == NULL)
                cout << "Empty Tree" << endl;
            else
                printTree(root);
        }
    private:
        struct AVLNode{
             Comparable data;
             int  height;
             AVLNode* left;
             AVLNode* right;
             AVLNode(const Comparable& element, AVLNode* l, AVLNode* r, int h = 0)
                 :data(element),left(l),right(r),height(h){}
        };
        AVLNode* root;
        bool contains(const Comparable& x, AVLNode* t) const{
            if(t == NULL)
                return false;
            else if(x < t->data){
                return contains(x,t->left);
            }
            else if(t->data < x){
                return contains(x,t->right);
            }
            else
                return true;
        }

        AVLNode* findMax(AVLNode* t) const{
            if(t == NULL) return NULL;
            if(t->right == NULL) return t;
            else return findMax(t->right);
        }

        AVLNode* findMin(AVLNode* t) const{
            if(t == NULL) return NULL;
            if(t->left==NULL) return t;
            else return findMin(t->left);
        }

        void makeEmpty(AVLNode*& t){
            if(t != NULL){
                makeEmpty(t->left);
                makeEmpty(t->right);
                delete t;
            }
            t = NULL;
        }

        void printTree(AVLNode* t) const{
            if(t!= NULL){
                printTree(t->left);
                cout << t->data << endl;
                printTree(t->right);
            }
        }

        AVLNode* clone(AVLNode* t) const{
            if(t == NULL)
                return NULL;
            else
                return new AVLNode(t->data, clone(t->left),clone(t->right),t->height);
        }
        int height(AVLNode * t){
             return t==NULL ?-1 :t->height;
        }
        void insert(const Comparable& x, AVLNode *& t){
            if(t == NULL){
                t = new AVLNode(x,NULL,NULL);
            }
            else if(x < t->data){
                insert(x,t->left);
                if(height(t->left) - height(t->right) > 1){
                    if(x < t->left->data)
                        rotateWithLeftChild(t);
                    else
                        doubleWithLeftChild(t);
                }
            }
            else if(t->data < x){
                 insert(x,t->right);
                 if(height(t->right) - height(t->left) > 1){
                     if(x > t->right->data){
                         rotateWithRightChild(t);
                     }
                     else{
                          doubleWithRightChild(t);
                     }
                 }
            }
            else;
            t->height = max(height(t->left),height(t->right))+1;
        }

        void rotateWithLeftChild(AVLNode *& k2){
            AVLNode *k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;
            k2->height = max(height(k2->left), height(k2->right)) + 1;
            k1->height = max(height(k1->left),k2->height) + 1;
            k2 = k1;
        }

        void rotateWithRightChild(AVLNode* &k2){
            AVLNode *k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;
            k2->height = max(height(k2->left),height(k2->right)) + 1;
            k1->height = max(height(k1->right),k2->height) + 1;
            k2 = k1;

        }

        void doubleWithLeftChild(AVLNode* &k3){
             rotateWithRightChild(k3->left);
             rotateWithLeftChild(k3);
        }

        void doubleWithRightChild(AVLNode*& k1){
             rotateWithLeftChild(k1->right);
             rotateWithRightChild(k1);

        }

};
#endif
