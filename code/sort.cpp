#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
using namespace std;
typedef struct{
	int key;
}Record;
typedef struct{
	Record num[101];
}List;
List R,L;
int com,mov,lop;
void Random(){
	srand(time(NULL));
	for(int i=1;i<101;i++)
	{
		R.num[i].key=rand()%101;
	}
}

void InsertSort(){
	int i,j;
	for(i=2;i<101;i++){
		com++;
		if(L.num[i].key<L.num[i-1].key){
			mov+=2;
			L.num[0]=L.num[i];
			L.num[i]=L.num[i-1];
			for(j=i-2;L.num[0].key<L.num[j].key;--j,com++){
				L.num[j+1]=L.num[j];
				mov++;
			}
			mov++;
			L.num[j+1]=L.num[0];
		}
		
	}
}

void BInsertSort(){
	int i,j,m,low,high;
	for(i=2;i<101;i++){
		mov++;
		L.num[0]=L.num[i];
		low=1;high=i-1;
		while(low<=high){
			m=(low+high)/2;
			com++;
			if(L.num[0].key<L.num[m].key)
				high=m-1;
			else
				low=m+1;
		}
		for(j=i-1;j>=high+1;--j){
			mov++;
			L.num[j+1]=L.num[j];
		}
		mov++;
		L.num[high+1]=L.num[0];	
	}	
}

void ShellInsert(){
	int i,j,k;
	int dk[]={63,31,15,7,3,1};
	for(k=0;k<6;++k){
		for(i=dk[k]+1;i<=100;i++){
			com++;
			if(L.num[i].key<L.num[i-dk[k]].key){
				mov++;
				L.num[0]=L.num[i];
				for(j=i-dk[k];j>0&&L.num[0].key<L.num[j].key;j-=dk[k],com++){
					mov++;
					L.num[j+dk[k]]=L.num[j];
				}
				mov++;
				L.num[j+dk[k]]=L.num[0];
			}
			
		}
	}		
}

void BubbleSort(){
	int i,count;
	do{
	count=0;
	for(i=1;i<100;i++){
		com++;
		if(L.num[i].key>L.num[i+1].key){
			count++; 
			mov+=3;
			L.num[0]=L.num[i+1];
			L.num[i+1]=L.num[i];
			L.num[i]=L.num[0];
		}
	}
	}while(count!=0);
} 

int Partition(int low,int high){
	mov++;
	L.num[0]=L.num[low];
	int pivot=L.num[low].key;
	while(low<high){
		com+=2;
		while(low<high&&L.num[high].key>=pivot){
			com++;--high;
		}
		mov++;
		L.num[low]=L.num[high];
		while(low<high&&L.num[low].key<=pivot){
			com++;++low;
		}
		mov++;
		L.num[high]=L.num[low];
	}
	mov++;
	L.num[low]=L.num[0];
	return low;
}
void QuickSort(int low,int high){
	if(low<high){
		int pivot=Partition(low,high);
		QuickSort(low,pivot-1);
		QuickSort(pivot+1,high);
	}
}

int SelectMinKey(int min){
	int key;
	mov++;
	key=min;
	for(int i=min+1;i<101;i++,com++)
		if(L.num[i].key<L.num[key].key){
			mov++;
			key=i;
		}
	return key;		
}
void SelectSort(){
	for(int i=1;i<101;i++){
		int j=SelectMinKey(i);
		if(i!=j)
			{
				mov+=3;
				L.num[0]=L.num[i];
				L.num[i]=L.num[j];
				L.num[j]=L.num[0];
			}
	}
}

void HeapAdjust(int s,int m){
	int j;
	Record rc;
	rc=L.num[s];
	for(j=2*s;j<=m;j*=2){
		com+=2;
		if(j<m&&L.num[j].key<L.num[j+1].key)
			++j;
		if(rc.key>=L.num[j].key)
			break;
		mov++;
		L.num[s]=L.num[j];
		s=j;
	}
	L.num[s]=rc;
}
void HeapSort(){
	int i;
	for(i=50;i>0;--i)
		HeapAdjust(i,100);
	for(i=100;i>1;--i)
	{	
		mov+=3; 
		L.num[0]=L.num[1];
		L.num[1]=L.num[i];
		L.num[i]=L.num[0];
		HeapAdjust(1,i-1);
	 } 
} 

void Merge(Record SR[],Record TR[],int s,int m,int e){
 	int j,k,n;
	for(j=m+1,k=s;s<=m&&j<=e;++k){
		com++;mov++;
		if(SR[s].key<=SR[j].key)
			TR[k]=SR[s++];
		else
			TR[k]=SR[j++];
	}
	if(s<=m)
		for(n=0;n<=m-s;n++){
			TR[k+n]=SR[s+n];mov++;
		}
			
	if(j<=e)
		for(n=0;n<=e-j;n++){
			TR[k+n]=SR[j+n];mov++;
		}
			
}
void MSort(Record SR[],Record TR[],int s,int e){
	int m;
	Record TR1[101];
	if(s==e)
		TR[s]=SR[s];
	else{
		m=(s+e)/2;
		MSort(SR,TR1,s,m);
		MSort(SR,TR1,m+1,e);
		Merge(TR1,TR,s,m,e); 
	}
}
void MergeSort(){
	MSort(L.num,L.num,1,100);
}

int main(){
	int i,op;
	int coms[8]={0},movs[8]={0};
	printf("100个数字的排序\n-------------------------------");
	Random();
	printf("\n100个随机数如下：\n");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",R.num[i]);
	}	
	printf("\n\n1.插入排序\n2.折半插入排序\n3.希尔插入排序\n4.冒泡排序\n5.快速排序\n6.简单选择排序\n7.堆排序\n8.归并排序\n0.退出\n");			
	L=R;
	mov=com=0;
	
	
	while(scanf("%d",&op))
	{
	switch(op){
	case 1:{
	InsertSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}	
	printf("\nInsert Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	break;
	}
	
	case 2:{
	BInsertSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nBInsert Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	break;
	}
	
	case 3:{
	ShellInsert();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nShellInsert Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	break;
	}
	
	case 4:{
	BubbleSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nBubble Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	coms[3]=coms[3]+com;movs[3]=movs[3]+mov;
	break;
	}
	
	case 5:{
	QuickSort(1,100);
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nQuick Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	coms[4]=coms[4]+com;movs[4]=movs[4]+mov;
	break;
	}
	
	case 6:{
	SelectSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nSimple Selection Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	break;
	}
	
	case 7:{
	HeapSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nHeep Sort is OK!\ncompare:%-5d, moves:%d",com,mov);
	break;
	}
	
	case 8:{
	MergeSort();
	printf("\n排序结果如下：");
	for(i=1;i<101;i++)
	{
		if(i%10==1)
			printf("\n");
		printf("%-3d",L.num[i]);
	}
	printf("\nMerging Sort is OK!\ncompare:%-5d, moves:%d\n",com,mov);
	break;
	}
	
	case 0:{
			system("pause");
			return 0;
		}
	}
	
	L=R;
	mov=com=0;
	printf("\n\n\n1.插入排序\n2.折半插入排序\n3.希尔插入排序\n4.冒泡排序\n5.快速排序\n6.简单选择排序\n7.堆排序\n8.归并排序\n0.退出\n");			
	
	}
	
}
