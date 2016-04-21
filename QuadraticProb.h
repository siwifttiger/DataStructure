#ifndef QUADRATICPROB_H
#define QUADRATICPROB_H
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int hash(const string& x){
    int len = x.length();
    int hashVal = 0;
    for(int i = 0; i < len; i++){
        hashVal = 37*hashVal + x[i];
    }
    return hashVal;
}

int hash(int key){
    return key;
}

bool isPrime(int x){
     if(x == 1)
         return false;
     if(x == 2 || x == 3)
         return true;
     for(int i = 2; i * i <= x; i++){
          if(x % i == 0)
              return false;
     }
     return true;
}

int nextPrime(int x){
     int n = x;
     if(n % 2 == 0)
         n++;
     for(;!isPrime(n);n+=2);
     return n;
}

template<typename HashObj>
class HashTable{
    public:
        explicit HashTable(int size =101)
            :array(nextPrime(size)){
                 makeEmpty();
            }

        bool contains(const HashObj& x) const{
             return isActive(findPos(x));
        }

        void makeEmpty(){
             currentSize = 0;
             for(int i = 0; i < array.size(); i++){
                 array[i].info = EMPTY;
             }
        }

        bool insert(const HashObj& x){
             int currentPos =findPos(x);
             if(isActive(currentPos))
                 return false;
             array[currentPos] = HashEntry(x,ACTIVE);
             ++currentSize;
             if(currentSize > array.size() / 2)
                rehash();
            return true;
        }

        bool remove(const HashObj& x){
             int currentPos = findPos(x);
             if(!isActive(x))
                 return false;
             array[currentPos].info = DELETED;
             return true;
        }

        enum EntryType{ACTIVE,EMPTY,DELETED};
    private:
        struct HashEntry{
             HashObj element;
             EntryType info;
             HashEntry(const HashObj& e = HashObj(),EntryType i = EMPTY):
                 element(e),info(i){};
        };

        vector<HashEntry> array;
        int currentSize;
        bool isActive(int  pos) const{
            return array[pos].info == ACTIVE;
        }

	//原本查找位置的函数为 h(x) + i^2
	//也即 h(x)+(i-1)^2 + 2i-1
	//下面的实现将 h(x) + (i-2)^2 当做currentPos
	//所以以后只用从1开始顺序加上奇数即可
	//利用offset，每次将offset加2，比第一个公式高效很多
        int findPos(const HashObj& x) const{
             int currentPos = myhash(x);
             int offset = 1;
             while(array[currentPos].info != EMPTY
                     && array[currentPos].element != x){
                  currentPos += offset;
                  offset += 2;   //计算ith probe
             }
             return currentPos;
        }

        void rehash(){
             vector<HashEntry> oldarray = array;
             array.resize(nextPrime(2*array.size()));
             for(int i = 0; i < array.size(); i++){
                 array[i].info = EMPTY;
             }

             currentSize = 0;
             for(int i = 0; i < oldarray.size(); i++){
                  insert(oldarray[i].element);
             }
        }

        int myhash(const HashObj& x) const{
             int hashVal = hash(x);
             hashVal %= array.size();
             if(hashVal < 0)
                 hashVal += array.size();
             return hashVal;
        }
};



#endif
