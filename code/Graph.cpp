#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define MAX_VERTEX_NUM 30
using namespace std;
bool visited[MAX_VERTEX_NUM];

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

LinkQueue q;
void EnQueue(int e)
{
	QNode *p;
	p=(QueuePtr)malloc(sizeof(QNode));
	p->data=e;
	p->next=NULL;
	q.rear->next=p;
	q.rear=p;
}
void DeQueue(int &e)
{
	QNode *p=q.front->next;
	e=p->data;
	q.front->next=p->next;
	if(q.rear==p)
		q.rear=q.front;
	free(p);
}



typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
    int data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

void Create(ALGraph &G)
{
	int i,head,tail;
	ArcNode *p,*q;
	printf("请输入无向图的结点数: "); 
	scanf("%d",&G.vexnum);
	printf("请输入无向图的边数: ");
	scanf("%d",&G.arcnum);
	for(i=1;i<=G.vexnum;i++)
	{
		G.vertices[i].data=i;
		G.vertices[i].firstarc=NULL;
	}
	for(i=1;i<=G.arcnum;i++)
	{
		printf("请输入一条边(a,b)： ");
		scanf("%d,%d",&head,&tail);
		p=(ArcNode *)malloc(sizeof(ArcNode)); 
        q=(ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex=head;
		q->adjvex=tail;
		p->nextarc=G.vertices[tail].firstarc;
	    G.vertices[tail].firstarc=p;
	    q->nextarc=G.vertices[head].firstarc;
	    G.vertices[head].firstarc=q;
	}
}
void PrintG(ALGraph *G)
{
	int i;
	printf("\n打印无向图如下:\n");
	for(i=1;i<=G->vexnum;i++){
		printf("%d:  %d->",i,i);
		while(G->vertices[i].firstarc->nextarc!=NULL){
			printf("%d->",G->vertices[i].firstarc->adjvex);
			G->vertices[i].firstarc = G->vertices[i].firstarc->nextarc;
		}
		printf("%d\n",G->vertices[i].firstarc->adjvex);
	} 
}

int FirstAdjVex(ALGraph G,int v){
	ArcNode *p=G.vertices[v].firstarc;
	if(p)
		return p->adjvex;
	else
		return -1;
}
int NextAdjVex(ALGraph G,int v,int w){
	ArcNode *p=G.vertices[v].firstarc;
	while(p){
		if(p->adjvex==w)
			break;
		p=p->nextarc;
	}
	if(p->adjvex!=w || !p->nextarc)
		return -1;
	return p->nextarc->adjvex;
}

void DFS(ALGraph G,int v){
	visited[v]=true;
	printf("%d ",v);
	for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
		if(!visited[w])
			DFS(G,w);
}
void BFSTraverse(ALGraph G){
	int v,u;
	for(v=1;v<=G.vexnum;++v)
		visited[v]=false;
	for(v=1;v<=G.vexnum;++v)
		if(!visited[v]){
			visited[v]=true;
			printf("%d ",v);
			EnQueue(v);
			while(q.front!=q.rear)
				DeQueue(u);
				for(int w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
					if(!visited[w]){
						visited[w]=true;
						printf("%d ",w);
						EnQueue(w);	
					}
					
		} 
}

int main(){
	int k;
	ALGraph G;
	q.front=q.rear =(QueuePtr)malloc(sizeof(QNode));
    q.front->next=NULL;
	Create(G);
	printf("从第几个点开始深度优先遍历\n");
	scanf("%d",&k);
	DFS(G,k);
	printf("\n从第1个点开始广度优先遍历\n");
	BFSTraverse(G);
	PrintG(&G);
	return 0;
}
