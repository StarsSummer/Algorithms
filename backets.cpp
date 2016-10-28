#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define INITSIZE  100
#define INCREMENT  10
using namespace std;
typedef struct Backets{
	char *base;
	char *top;
	int stacksize;
};

void InitStack(Backets &S){
	S.base=(char *)malloc(INITSIZE*sizeof(char));
    if(!S.base)	
      printf("error");
    S.top=S.base;
    S.stacksize=INITSIZE;
}

int StackEmpty(Backets &S){
    if(S.base==S.top)
      return 1;
    else
      return 0;
}

void Pop(Backets &S,char &e){
	e=*--S.top;
}

void GetTop(Backets &S,char &e){
	if(S.top==S.base)
	  e='0';
	e=*(S.top-1);
}

void Push(Backets &S,char e){
	if(S.top-S.base>=S.stacksize){
	  S.base=(char *)realloc(S.base,(S.stacksize+INCREMENT)*sizeof(char));
	  if(!S.base)
	    printf("error");
	  S.top=S.base+S.stacksize;
	  S.stacksize+=INCREMENT;
	}
	*S.top++=e;
}
int Equal(char a,char b)
{
	if((a==')' && b=='(')||(a==']' && b=='['))
	  return 1;
	else
	  return 0;
}

int main(){
	Backets S;
	int i=0;
	char e;
	char match[50];
	InitStack(S);
	printf("«Î ‰»Î¥˝ºÏ—Èµƒ¿®∫≈¥Æ£∫\n"); 
	scanf("%s",match);
	while(match[i]){
		GetTop(S,e);
		if(Equal(match[i],e))
		   Pop(S,e);
		else
		   Push(S,match[i]);
		i++;		
	}
	if(StackEmpty(S))
	  printf("∆•≈‰\n");
	else
	  printf("¥À¥Æ¿®∫≈∆•≈‰≤ª∫œ∑®\n");
	system("pause");
	return 0;
}
