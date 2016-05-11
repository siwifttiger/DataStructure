/*图的深度优先遍历
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
	/****************************************
	对于这个函数思想的简单说明：
	这个而函数的本质还是DFS，从起点v开始，每一次
	访问到一个新的节点w，都说明存在一条从v到w
	的路径，同时将rs[w]标记。假设这时候从v访问到了
	一个节点x，对x DFS后访问到了一个节点w，发现这个
	w的rs[w]为真，说明w存在于v到x的路径中，也就是
	说存在一条从w到x的路径，但是w右能够通过x访问到，
	说明存在一条从x到w的路径，这就说明w与x能构成环
	的起点与终点。
	*****************************************/
	bool isCycleUtil(int v, bool visit[], bool *rs){
		if(visit[v] == false){
			visit[v] = true;
			rs[v] = true;
			list<int>::iterator it;
			for(it = adj[v].begin(); it != adj[v].end(); it++){
				if(!visit[*it] && isCycleUtil(*it,visit,rs)){
					return true;
				}
				else if(rs[*it])
					return true;
			}
		}
		rs[v] = false;
		return false;
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
	//非递归实现,但是也只能访问连通图的所有点
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
	//非递归，访问所有点
	void DFSNRec(){
		bool *visit = new bool[V];
		for(int i = 0; i < V; i++){
			visit[i] = false;
		}
		stack<int> s;
		for(int i = 0; i < V; i++){
			while(!s.empty())
				s.pop();
			if(visit[i] == false){
				s.push(i);
				visit[i] = true;
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
		}
	}
	
	bool isCycle(){
		bool * visit = new bool[V];
		bool *recStack = new bool[V];
		for(int i = 0; i < V; i++){
			visit[i] = false;
			recStack[i] = false;
		}
		for(int i = 0; i < V; i++){
			if(isCycleUtil(i,visit,recStack)){
				
				return true;
			}
		}
	
		return false;
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
   Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    if(g.isCycle())
        cout << "Graph contains cycle";
    else
        cout << "Graph doesn't contain cycle";
    return 0;

}

