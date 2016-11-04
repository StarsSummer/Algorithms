#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
using namespace std;
typedef struct{
	char *ch;
	int len;
}SString;

int next[100];
void GetNext(SString &T)
{
	int j,k;
	j=1,k=0,next[1]=0;
	while(j<T.len){
		if(k==0 || T.ch[j]==T.ch[k]){
			j++;k++;next[j]=k;
		}
		else
		    k=next[k];
	}
}
void StrAssign(SString &T,char *chars)
{
	int i=0;
	while(chars[i])
	{
		i++;
	}
	if(!(T.ch=(char*)malloc((i+1)*sizeof(char))))
	 printf("OVERFLOW"); 
	else
   	 for(int j=0;j<i;j++)
      T.ch[j+1]=chars[j];		
	T.len=i;
}

int kmp(SString major,SString sub){
   int i=1,j=1;
   while(i<=major.len && j<=sub.len){
   	if(j==0 || major.ch[i]==sub.ch[j])
   		{++i;++j;}
   	else
   	    j=next[j];
   	if(j>sub.len)
   	  return i-sub.len;
   }
	return -1;
}
int main(){
	int ans;
	char ch1[100],ch2[100];
	SString str1,str2;
	printf("请输入主串:\n");
	scanf("%s",&ch1);
	printf("请输入子串:\n");
	scanf("%s",&ch2);
	StrAssign(str1,ch1);
	StrAssign(str2,ch2);
	GetNext(str2);
	ans=kmp(str1,str2);
	if(ans==-1)
	  printf("匹配失败\n");
	else
	  printf("匹配到的位置是%d\n",ans);
	system("pause");
	return 0;
}
