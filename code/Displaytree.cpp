#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
char ch;
int depth=0;

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

void display(BiTree T)
{
	int i;
	if(T)
    {  
       depth++;
       display(T->rchild);
       for(i=1;i<depth;i++)
	     printf("  ");
	   printf("%c\n",T->data);
	   display(T->lchild);	   
       depth--;
    }
}

int main(){
	BiTree Atree;
	CreateTree(Atree);
	printf("打印二叉树如下：\n\n");
	display(Atree);
	printf("\n");
	system("pause");
	return 0;
}
