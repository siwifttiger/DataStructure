/*图的广度优先遍历
图用邻接链表表示*/
#include<iostream>
#include<queue>
#include<list>
using namespace std;

class Graph{
private:
	int V;
	list<int> *adj;
public:
	Graph(int V){
		this->V =V;
		adj = new list<int>[V];
	}
	//有向图
	void addEdge(int src, int dest){
		adj[src].push_back(dest);
		
	}
	
	void BFS(int s){
		bool * v = new bool[V]; //标识数组，用来标识是否已被访问过
		queue<int> q;
		q.push(s);
		v[s] = true;
		while(!q.empty()){
			int top = q.front();
			cout << top << " ";
			q.pop();
			for(list<int>::iterator it = adj[top].begin(); it != adj[top].end(); it++){
				if(v[*it] == false){
					v[*it] = true;
					q.push(*it);
				}
			}
		}
			
	}
	
	void printGraph(){
		for(int i = 0; i < V; i++){
			cout << "\n顶点"  << i << "的邻接链表是：\n";
				while(!adj[i].empty()){
					cout << adj[i].back() << " ";
					adj[i].pop_back();
				}
			cout << endl;
		}
	}
};

int main(){
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	cout << "从顶点0开始广度遍历图\n";
	g.BFS(0);
	cout << endl;
}

