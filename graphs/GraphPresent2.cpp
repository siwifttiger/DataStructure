/*C++直接list实现邻接链表表示图*/
#include<iostream>
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
	//无向图
	void addEdge(int src, int dest){
		adj[src].push_back(dest);
		adj[dest].push_back(src);
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
	g.printGraph();
	
	
}
