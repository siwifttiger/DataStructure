#ifndef SEPERATECHAININGHASH_H
#define SEPERATECHAININGHASH_H

#include<vector>
#include<list>
#include<algorithm>
#include<string>
using namespace std;

bool isPrime(int n){
    if(n == 1 )
        return false;
    if(n == 2 || n == 3)
        return true;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0)
            return false;
        return true;
    }
}

int nextPrime(int n){
    if(n % 2 == 0)
        n++;
    for(;!isPrime(n);n+=2);
    return n;
}

template<typename HashObj>
class HashTable{
    public:
        explicit HashTable(int size = 101)
            :currentSize(0)
        {theList.resize(101);}

        bool contains(const HashObj& x) const{
             const list<HashObj>& whichList = theList[myhash(x)];
             return find(whichList.begin(),whichList.end(),x) != whichList.end();
        }

        void makeEmpty(){
            for(int i = 0; i < theList.size();i++){
                 theList[i].clear();
            }
        }

        bool insert(const HashObj& x) const{
             const list<HashObj>& whichList = theList[myhash(x)];
             if(find(whichList.begin(),whichList.end(),x) != whichList.end())
                 return false;
             whichList.push_back(x);
             ++currentSize;
             if((currentSize) >= theList.size())
                 rehash();
             return true;
        }

        bool remove(const HashObj& x){
             const list<HashObj>& whichList = theList[myhash(x)];
            typename list<HashObj>::iterator itr= find(whichList.begin(),whichList.end(),x);
             if(itr == whichList.end()){
                  return false;
             }
             whichList.erase(itr);
             --currentSize;
             return true;
        }
    private:
        vector<list<HashObj> > theList;
        int  currentSize;
        void rehash(){
             vector<list<HashObj> > oldList = theList;
             theList.resize(nextPrime(theList.size()*2));
             for(int j = 0; j < theList.size();j++){
                  theList[j].clear();
             }
             currentSize = 0;
             for(int i = 0; i < oldList.size(); i++){
               typename list<HashObj>::iterator itr;
               itr = oldList[i].begin();
               while(itr != oldList[i].end()){
                   insert(*itr++);
               }
             }
        }

        int myhash(const  HashObj& x) const{
             int hashVal = hash(x);
             hashVal %= theList.size();
             if(hashVal < 0)
                 hashVal += theList.size();
             return hashVal;
        }

};

int hash(const string& key){
    int hashVal = 0;
    for(int i = 0; i < key.length(); i++){
        hashVal = 37*hashVal + key[i];
    }
    return hashVal;
}

int hash(int key){
     return key;
}


#endif
