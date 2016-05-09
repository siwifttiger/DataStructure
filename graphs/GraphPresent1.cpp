/*C语言邻接链表实现图的表示*/
#include<iostream>
#include<cstdlib>
using namespace std;

/*邻接链表中，单个节点的数据结构*/
struct AdjListNode{
	int dest;     //哪一个顶点
	AdjListNode* next;
};

/*一条链表的数据结构*/
struct AdjList{
	AdjListNode* head; //只需要一个表头即可
};

/*一个图的数据结构*/
struct Graph{
	int V; //顶点的数量
	AdjList* array; //链表	
};

/*创建一个新的节点*/
struct AdjListNode* newAdjListNode(int dest)
{
    AdjListNode* newNode =new AdjListNode;
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

//创建一个图，初始化
struct Graph* creatGraph(int V)
{
    Graph* graph = new Graph;
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = new AdjList[V];
 
     // Initialize each adjacency list as empty by making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
/*在src 和 dest 添加一条边*/
void addEdge(Graph* g, int src, int dest){
	AdjListNode* newNode = newAdjListNode(dest);
	//在表头插入，下面的方法很巧妙
	newNode->next = g->array[src].head;
	g->array[src].head = newNode;
	//建立的是无向图，所以在dest和src间也要插入一条边
	newNode = newAdjListNode(src);
	newNode->next = g->array[dest].head;
	g->array[dest].head = newNode;
	
}

void printGraph(Graph* g){
	for(int i = 0; i < g->V; i++){
		AdjListNode* p = g->array[i].head;
		cout << "\n顶点" << i << "的邻接链表是:\n";
		while(p){
			cout << p->dest << " ";
			p = p->next;
		}
		cout << endl;
	}
}

int main(){
	int V = 5;
	Graph* graph = creatGraph(5);
	addEdge(graph,0,1);
	addEdge(graph,0,4);
	addEdge(graph,1,2);
	addEdge(graph,1,3);
	addEdge(graph,1,4);
	addEdge(graph,2,3);
	addEdge(graph,3,4);
	printGraph(graph);
}
