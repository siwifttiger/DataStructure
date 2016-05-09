/*图的广度优先遍历
图用邻接链表表示*/
#include<iostream>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph{
private:
	int V;
	list<int> *adj;
	void DFSUtil(int v, bool visit[]){
		visit[v] = true;
		cout << v << " ";
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end(); it++){
			if(!visit[*it]){
				DFSUtil(*it,visit);
			}
		}
	}
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
	
	//这种DFS方法只能访问到连通图中的所有顶点，对与不连通的点则无法访问到
	void DFS(int v){
		bool *visit = new bool[V];
		for(int i = 0; i < V; i++)
			visit[i] = false;
		DFSUtil(v,visit);
	}
	
	//下面这种DFS可以访问到图中所有顶点
	void DFS(){
		bool *visit = new bool[V];
		for(int i = 0; i < V; i++){
			visit[i] = false;
		}		
		for(int i = 0; i < V; i++){
			if(!visit[i])
				DFSUtil(i,visit);
		}
	}
	//非递归实现
	void DFSNRec(int v){
		bool *visit = new bool[V];
		for(int i = 0; i < V; i++){
			visit[i] = false;
		}
		stack<int> s;
		s.push(v);
		visit[v] = true;
		while(!s.empty()){
			int top = s.top();
			cout << top << " ";
			s.pop();
			for(list<int>::iterator it = adj[top].begin(); it != adj[top].end(); it++){
				if(!visit[*it]){
					visit[*it] = true;
					s.push(*it);
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
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	cout << "从顶点0开始广度遍历图\n";
	g.BFS(0);
	
	cout << "\n深度优先遍历1\n";
	g.DFS(0);
	cout << "\n深度优先遍历2\n";
	g.DFS();
	cout << "\n深度优先遍历3\n";
	g.DFSNRec(0);
}

