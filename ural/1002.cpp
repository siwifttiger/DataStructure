#include<iostream>
#include<string>
#include<limits.h>
using namespace std;

int graph[102][102];
int dist[102];
bool visit[102];
string map(string& s){
    int len = s.length();
    string str;
    for(int i = 0; i < len; ++i){
        switch(s[i]){
            case 'i':
            case 'j':
                str+="1";
                break;
            case 'a':
            case 'b':
            case 'c':
                str+="2";
                break;
            case 'd':
            case 'e':
            case 'f':
                str+="3";
                break;
            case 'g':
            case 'h':
                str+="4";
                break;
            case 'k':
            case 'l':
                str+="5";
                break;
            case 'm':
            case 'n':
                str += "6";
                break;
            case 'p':
            case 'r':
            case 's':
                str+= "7";
                break;
            case 't':
            case 'u':
            case 'v':
                str += "8";
                break;
            case 'w':
            case 'x':
            case 'y':
                str += "9";
                break;
            case 'o':
            case 'q':
            case 'z':
                str += "0";
                break;


        }
    }
    return str;
}

int minDistance(int length){
     int min = INT_MAX, minIndex;
     for(int i = 0; i <= length; ++i){
         if(visit[i] == false && dist[i] < min){
              min = dist[i];
              minIndex = i;
         }
         return minIndex;
     }
}

void dijkstra(int graph[102][102], int src, int length){
    for(int i = 1; i <= length; i++){
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for(int count = 0; count < length -1; count++){
        cout << visit[src] << endl;
         int u = minDistance(length);
         visit[u] = true;
         cout << u << " " << visit[u] << endl;
         for(int j = 1; j <= length; j++){
              if(!visit[j] && graph[u][j] && dist[u] != INT_MAX
                      && dist[u] + graph[u][j] < dist[j]){
                  dist[j] = dist[u]+graph[u][j];
              }
         }
    }
    if(dist[length] != INT_MAX){
         cout << dist[length] << endl;
    }else{
        cout << "No solution" << endl;
    }
}

void createGraph(string& pString, string& subStr){
    int position = 0;
    while((position = pString.find(subStr,position)) != string::npos){
        graph[position+1][position+subStr.length()+1] = 1;
        position += subStr.length();
    }
}


int main(){
     string callNum;
     string subStr;
     int num;
     while(true){
         cin >> callNum;
         if(callNum == "-1") break;
         cin >> num;
         for(int i = 0; i < num; ++ i){
              cin >> subStr;
              string temp = map(subStr);
              createGraph(callNum,temp);
         }
         for(int i = 1; i <= callNum.length() + 1; i++){
             for(int j = 1; j <= callNum.length()+1; j++){
                 cout << graph[i][j] << ' ';
             }
             cout << endl;
         }

        dijkstra(graph,1,callNum.length()+1);
     }
}
