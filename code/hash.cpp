#include <stdio.h>
#include <stdlib.h>
#include <String>
#include <malloc.h>
typedef struct{
	const char *name;
	int key;
}NAME;
NAME N[31];
typedef struct{
	const char *name;
	int count;
	int hashk;
	int key;
}HashTable;
HashTable H[38];

void getkey(NAME *N){
	int i,j,k;
	for(i=1;i<=30;i++){
		j=0;k=0;
		while(*(N[i].name+j)!='\0')
		{
			k=k+*(N[i].name+j);
			j++;
			}
		N[i].key=k;	
	}

}


void CreateHash(HashTable *H)
{
	int i,s,hash,j,addr;
	for(i=1;i<=30;i++)
	{
		hash=(N[i].key)%37;
		if(H[hash].count==0)
		{
			H[hash].key=N[i].key;
			H[hash].hashk=(N[i].key)%37;
			H[hash].name=N[i].name;
			H[hash].count=1;
			}
		else
		{
			j=0,s=0;
			do
			{
				j++;
				s++;
				addr=(N[i].key+j)%37;		
			}while(H[addr].count!=0);
			H[addr].key=N[i].key;
			H[addr].hashk=(N[i].key)%37;
			H[addr].name=N[i].name;
			H[addr].count=s+1;
		}	
	}
}
void ShowHash(HashTable *H){
	printf("地址   关键字   搜索长度   H(k)     拼音 \n");
	for(int i=1;i<=37;i++)
	{ 
		printf("%-5d  %-8d %-10d %-8d %-20s\n",i,H[i].key,H[i].count,H[i].hashk,H[i].name);
	}
}

void SearchHash()
{
	int j,key,s,addr,find;
	char people[20];
	j=0;key=0;find=0;
	printf("请输入你要查找的人:");
	scanf("%s",&people);
	while(*(people+j)!='\0')
	{
		key=key+*(people+j);
		j++;
	}
	j=0;s=0;	
	do
	{
		addr=(key+j)%37;
		j++;
		s++;
		if(H[addr].count==0||s>10)
		{
			find=1;
			break;
		}
	}while(H[addr].key!=key);	
	if(find==1)
	  printf("无此记录\n");
	else
	  printf("姓名:%s 关键字:%d 查找长度:%d\n",H[addr].name,H[addr].key,H[addr].count);
}


int main(){
	int op,i;
	printf("1.显示哈希表\n2.查找人名\n0.退出程序\n");
	N[1].name="fuchaoxing";
	N[2].name="huixinyu";	
	N[3].name="zhaotianhao";
	N[4].name="mukai";
	N[5].name="limengjie";
	N[6].name="kangranhao";
	N[7].name="sunqiming";
	N[8].name="yangzhuo";
	N[9].name="wangtao";
	N[10].name="yuruotong";
	N[11].name="jianjiaqi";
	N[12].name="gongjinchen";
	N[13].name="mouliangyu";
	N[14].name="caoxipeng";
	N[15].name="qiuli";
	N[16].name="tanshngou";
	N[17].name="wuminghao";
	N[18].name="wumingyao";
	N[19].name="ouyangyanlong";
	N[20].name="luorongdi";
	N[21].name="changjiawei";
	N[22].name="cuiyunhao";
	N[23].name="zhangqingrui";
	N[24].name="chenhongyun";
	N[25].name="baiyunlong";
	N[26].name="linwenyi";
	N[27].name="dengqi";
	N[28].name="yangnihong";
	N[29].name="zuojialu";
	N[30].name="liboyan";
	for(i=1;i<=37;i++){
		H[i].count=0;
		H[i].hashk=0;
		H[i].key=0;
		H[i].name="";
	} 
	getkey(N);CreateHash(H);
	while(scanf("%d",&op))
	{
	switch(op){
		case 1:{
			ShowHash(H);
			break;
		}
		case 2:{
			SearchHash();
			break;
		}
		case 0:{
			system("pause");
			return 0;
		}
	}	
	printf("\n1.显示哈希表\n2.查找人名\n0.退出程序\n");
	}
}
