#include<iostream>
using namespace std;

class Graph{
private:
	struct Edge{
		int src;
		int dest;
	};
	int V;  //顶点的数量
	int E; //边的数量
	Edge *edge;
	int *id;    //一维数组，里面的元素用来代表每一个而顶点的父节点
public:
	Graph(int V, int E){
		this->V = V;
		this->E = E;
		edge = new Edge[E];
		id = new int[V];
		for(int i = 0; i < V; i++){
			id[i] = i;
		}
	}
	
	//找到某个节点的根节点
	int find(int p){
		while(id[p] != p){
			p = id[p];
		}
		return p;
	}
	
	void unionVec(int p, int q){
		int i = find(p);
		int j = find(q);
		if(i == j) return;
		id[i] = j;
	}
	
	void addEdge(int num,int s, int d){
		edge[num].src = s;
		edge[num].dest = d;
		
	}
	
	bool isCycle(){
	//寻找到edge[i].src的根节点和edge[i].dest的根节点
	//如果两者的根节点相同，则包含环
		for(int i = 0; i < E; i++){
			int xset = find(edge[i].src);
			int yset = find(edge[i].dest);
			cout << "root of " << edge[i].src << " is" << xset << endl;
			cout << "root of " << edge[i].dest << " is" << yset << endl;
 			if(xset == yset)
				return true;
			unionVec(xset,yset);
		}
		return false;
	}
	
};

int main(){
	Graph g(3,3);
	g.addEdge(0,0,1);
	g.addEdge(1,1,2);
	g.addEdge(2,0,2);
	if(g.isCycle())	cout << "Graph cotains cycle.\n";
	else cout << "Graph does not contain cycles.\n";
}
