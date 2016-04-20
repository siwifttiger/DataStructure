#include<iostream>
#include"separateChainingHash.h"
using namespace std;
int main(  )
{
        HashTable<int> H;
	const int NUMS = 4000;
        const int GAP  =   37;
        int i;
        cout << "Checking... (no more output means success)" << endl;

        for( i = GAP; i != 0; i = ( i + GAP  ) % NUMS  )
            H.insert( i  );
	//将所有的奇数都删除了
        for( i = 1; i < NUMS; i += 2  )
            H.remove( i  );
	//检测偶数，如果由某个偶数不存在就输出失败
        for( i = 2; i < NUMS; i += 2  )
            if( !H.contains( i  )  )
          	cout << "Contains fails " << i << endl;
	//如果发现还有奇数，就输出一个异常
        for( i = 1; i < NUMS; i += 2  )
        {
            if( H.contains( i  )  )
                  cout << "OOPS!!! " <<  i << endl;

        }

       return 0;

}
