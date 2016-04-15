//4种算法计算最大连续子序列和

#include<iostream>
#include<vector>
using namespace std;

int max3(int a, int b, int c){
    return max(max(a,b),c);
}

int maxSubSum1(const vector<int>& a){
    int size = a.size();
    int maxSum = 0;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            int thisSum = 0;
            for(int k = i; k <= j; k++){
                thisSum += a[k];
                if(thisSum > maxSum){
                     maxSum = thisSum;
                }
            }
        }
    }
    return maxSum;
}

int maxSubSum2(const vector<int>& a){
     int size = a.size();
     int maxSum = 0;
     for(int i = 0; i < size; ++i){
         int thisSum = 0;
         for(int j = i; j < size; ++j){
             thisSum += a[j];
             if(thisSum > maxSum){
                  maxSum = thisSum;
             }
         }
     }
     return maxSum;
}

int maxSubSum3(const vector<int>& a, int left, int right){
    if(left == right){
        if(a[left] > 0)
            return a[left];
        else
            return 0;
    }

    //这个算法要比较的是左半边，右半边，和跨越左右半边的子序列的最大和
    int center = (left + right)/2;
    int maxLeftSum = maxSubSum3(a, left,center);
    int maxRightSum = maxSubSum3(a,center+1,right);
    int maxLeftBorderSum = 0, rightBorderSum = 0;
    int maxRightBorderSum = 0, leftBorderSum = 0;
    for(int i = center; i >= left; i--){
         leftBorderSum += a[i];
         if(leftBorderSum > maxLeftBorderSum){
             maxLeftBorderSum = leftBorderSum;
         }
    }

    for(int i = center+1; i<= right; ++i){
         rightBorderSum += a[i];
         if(rightBorderSum > maxRightBorderSum){
             maxRightBorderSum = rightBorderSum;
         }
    }

    return max3(maxLeftSum,maxRightSum,maxRightBorderSum + maxLeftBorderSum);
}

int maxSubSum4(const vector<int>& a){
     int thisSum = 0,maxSum = 0;
     int start = 0, len = 1;
     for(int i = 0; i < a.size(); ++i){
         thisSum += a[i];
         if(thisSum > maxSum){
              maxSum = thisSum;
              ++len;
         }
         else if(thisSum < 0){
             thisSum = 0;
             len = 1;
             start = i+1;
         }


     }
     cout << a[start] << " " << a[start+len-1] << endl;
     return maxSum;
}

int main(){
     vector<int> test;
     test.push_back(1);
     test.push_back(2);
     test.push_back(-1);
     test.push_back(-3);
     test.push_back(4);
     test.push_back(-1);
     test.push_back(5);
     cout << maxSubSum1(test) << endl << maxSubSum2(test) << endl
          << maxSubSum3(test,0,6) << endl << maxSubSum4(test) << endl;
}
