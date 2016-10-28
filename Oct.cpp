#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define INITSIZE  100
#define INCREMENT  10
using namespace std;
typedef struct Oct{
	int *base;
	int *top;
	int stacksize;
};

void InitStack(Oct &S){
	S.base=(int *)malloc(INITSIZE*sizeof(int));
    if(!S.base)	
      printf("error");
    S.top=S.base;
    S.stacksize=INITSIZE;
}

int StackEmpty(Oct &S){
    if(S.base==S.top)
      return 1;
    else
      return 0;
}

void Pop(Oct &S,int &e){
	e=*--S.top;
}

void Push(Oct &S,int e){
	if(S.top-S.base>=S.stacksize){
	  S.base=(int *)realloc(S.base,(S.stacksize+INCREMENT)*sizeof(int));
	  if(!S.base)
	    printf("error");
	  S.top=S.base+S.stacksize;
	  S.stacksize+=INCREMENT;
	}
	*S.top++=e;
}

int main(){
	Oct S;
    int n,e;
	InitStack(S);
	printf("请输入一个十进制数：\n");
	scanf("%d",&n);
	printf("转换为八进制数后为：\n");
	while(n){
		Push(S,n%8);
		n=n/8;
	}
	while(!StackEmpty(S)){
		Pop(S,e);
		printf("%d",e);
	}
	printf("\n");
	system("pause");
	return 0;
}
