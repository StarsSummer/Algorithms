#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
char ch;

typedef struct BiNode{
	char data;
	BiNode *lchild,*rchild;
}BiNode,*BiTree;

void CreateTree(BiTree &T){
	scanf("%c",&ch);
	  if(ch=='#')
	  	T=NULL;
      else{
      	T=(BiNode *)malloc(sizeof(BiTree));       
		T->data = ch ;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
     }
}

void preorder(BiTree T)
{
    if(T)
    {
       printf("%c ",T->data);
       preorder(T->lchild);
       preorder(T->rchild);
    }
}

void midorder(BiTree T)
{
	if(T)
	{
	   midorder(T->lchild);
	   printf("%c ",T->data);
	   midorder(T->rchild);
	}
}

void postorder(BiTree T)
{
	if(T)
	{
	  postorder(T->lchild);
	  postorder(T->rchild);
	  printf("%c ",T->data);
	}
}

int main(){
	BiTree Atree;
	CreateTree(Atree);
	printf("\n前序遍历为： "); 
	preorder(Atree);
	printf("\n中序遍历为： ");
	midorder(Atree);
	printf("\n后序遍历为： ");
	postorder(Atree);
	printf("\n");
	system("pause");
	return 0;
}
