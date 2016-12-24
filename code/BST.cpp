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
		printf("����ʧ��\n");
	else
		if(key==T->data)
			printf("���ҳɹ�\n"); 
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
	printf("Ҫ������ٸ����ݣ�  ");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("�������%d����:  ",i);
		scanf("%d",&num); 
		Insert(Tree,num);
	}
} 

int main(){
	int op,k;
	printf("1.�������������\n2.����ĳ������\n3.�������������\n4.��ʽ����ӡ\n");
	
	while(scanf("%d",&op))
	{
	switch(op){
		case 1:Create();break;
		case 2:{
			printf("��Ҫ���ҵ������ǣ�  ");
			scanf("%d",&k);
			SearchBST(Tree,k);
			break;
		}
		case 3:{
			printf("ǰ�����Ϊ��");
			preorder(Tree);
			printf("\n�������Ϊ��");
			midorder(Tree);
			printf("\n�������Ϊ��");
			postorder(Tree); 
			printf("\n"); 
			break;
		} 
		case 4:{
			printf("��ӡ������£�\n");
			display(Tree);
			break;
		}
		case 0:{
			system("pause");
			return 0;
		}
	}
	printf("\n1.�������������\n2.����ĳ������\n3.�������������\n4.��ʽ����ӡ\n");
	}
}



