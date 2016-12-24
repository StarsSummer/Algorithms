#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int depth=0;

typedef struct BiNode{
	int data;
	BiNode *lchild,*rchild;
}BiNode,*BiTree;
BiTree Tree;

void Insert(BiTree &T,int e){
	 if(!T){	
	    T=(BiNode *)malloc(sizeof(BiTree));
	 	T->data=e;
	 	T->lchild=T->rchild=NULL;
	 }
	 else
	 {
	 	if(e>T->data)
	 		Insert(T->rchild,e);
	 	else
	 		Insert(T->lchild,e);
	  } 
     
}

void display(BiTree T)
{
	int i;
	if(T)
    {  
       depth++;
       display(T->rchild);
       for(i=1;i<depth;i++)
	     printf("  ");
	   printf("%d\n",T->data);
	   display(T->lchild);	   
       depth--;
    }
}

void SearchBST(BiTree &T,int key)
{
	if(!T)
		printf("查找失败\n");
	else
		if(key==T->data)
			printf("查找成功\n"); 
		else
			if(key>T->data)
				SearchBST(T->rchild,key);
			else
				SearchBST(T->lchild,key);
}

void preorder(BiTree T)
{
    if(T)
    {
       printf("%d ",T->data);
       preorder(T->lchild);
       preorder(T->rchild);
    }
}

void midorder(BiTree T)
{
	if(T)
	{
	   midorder(T->lchild);
	   printf("%d ",T->data);
	   midorder(T->rchild);
	}
}

void postorder(BiTree T)
{
	if(T)
	{
	  postorder(T->lchild);
	  postorder(T->rchild);
	  printf("%d ",T->data);
	}
}

void Create(){
	int n,num;
	printf("要输入多少个数据？  ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("请输入第%d个数:  ",i);
		scanf("%d",&num); 
		Insert(Tree,num);
	}
} 

int main(){
	int op,k;
	printf("1.创建排序二叉树\n2.查找某个数据\n3.遍历排序二叉树\n4.格式化打印\n");
	
	while(scanf("%d",&op))
	{
	switch(op){
		case 1:Create();break;
		case 2:{
			printf("你要查找的数据是？  ");
			scanf("%d",&k);
			SearchBST(Tree,k);
			break;
		}
		case 3:{
			printf("前序遍历为：");
			preorder(Tree);
			printf("\n中序遍历为：");
			midorder(Tree);
			printf("\n后序遍历为：");
			postorder(Tree); 
			printf("\n"); 
			break;
		} 
		case 4:{
			printf("打印结果如下：\n");
			display(Tree);
			break;
		}
		case 0:{
			system("pause");
			return 0;
		}
	}
	printf("\n1.创建排序二叉树\n2.查找某个数据\n3.遍历排序二叉树\n4.格式化打印\n");
	}
}



