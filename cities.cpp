#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <malloc.h>
using namespace std;
typedef struct Data {                                      //城市的信息
	char name[20];
	float posx;
	float posy;
}Data;
typedef struct City {                                      //城市
	Data data;
	struct City *next;
}City, *LinkList;
LinkList L;

int strcmp( char a[],char b[]){
	int i;
	for(i=0;i<20;i++)
	  if(a[i]!=b[i])
	    return 1;
	else
	  return 0;
}
LinkList CreateCity( int n) {                             //初始化创建城市
	LinkList p;
	printf("\n");
	L = (LinkList)malloc(sizeof(City));
	L->next = NULL;
	for (int i = 0;i < n;i++) {
		p = (LinkList)malloc(sizeof(City));
		printf( "输入城市名字：");scanf("%s",&p->data.name);
		printf( "输入城市横坐标: ");scanf("%f",&p->data.posx);
		printf( "输入城市纵坐标: ");scanf("%f",&p->data.posy);
		p->next = L->next;L->next = p;
	}
	return L;
}

void ViewCity(LinkList L) {                              //更新查看
	LinkList p;
	p = L->next;
	printf("\n 当前有以下城市：\n");
	while (p) {
		printf("%s : (%.1f,%.1f) \n",p->data.name,p->data.posx,p->data.posy);
		p = p->next;
	}
}

void GetCity(LinkList L) {                               //获取城市位置
	LinkList p;
	printf("\n");
	char i[20];
	printf("输入城市名字: ");scanf("%s",&i);
	p = L;
	while (p->next && strcmp(p->data.name,i)) {
		p = p->next;
	}
	if (!strcmp(p->data.name, i))
		printf("城市 %s 的位置为(%.1f,%.1f) \n", i, p->data.posx, p->data.posy);
    else
		printf("error\n");
}
	

void AreaCity(LinkList L) {                             //获取范围内城市
	LinkList p;
	printf("\n");
	float px, py,x1,y1,d,s;
	px = py = x1 = y1 = d = s = 0.0;
	printf("输入位置的横坐标: "); scanf("%f", &px);
	printf("输入位置的纵坐标: "); scanf("%f", &py);
	printf("输入距离: ");scanf("%f", &d);
	p = L->next;
	printf("\n离中心城市的距离小于等于%.1f的城市有：",d);
	while (p) {
		x1 = p->data.posx;
		y1 = p->data.posy;
		s = sqrt((x1 - px)*(x1 - px) + (y1 - py)*(y1 - py));
		if (s <= d) printf("%s ", p->data.name);
		p = p->next;
	}
	printf(". \n" );
}

void InsertCity(LinkList &L) {                          //新增城市
	LinkList p;
	printf("\n");
	p = L;
	while (p) { p = p->next; }
	p = (LinkList)malloc(sizeof(City));
	p->next = L->next;L->next = p;
	printf("输入城市名字：");scanf("%s", &p->data.name);
	printf("输入城市横坐标: ");scanf("%f",&p->data.posx);
	printf("输入城市纵坐标: ");scanf("%f", &p->data.posy);
	
	printf("\n");
}

void DeleteCity(LinkList L,Data e) {                   //删除城市 
	LinkList p,q;
	char i[20];
	printf("\n 输入城市名字: ");scanf("%s",&i);
	q= p = L->next;
	while (p->next && strcmp(p->data.name, i)) {
		q = p;
		p = p->next;
	}
	if (!strcmp(p->data.name, i)) {
        q->next = p->next;
	    e = q->data;free(p);
	    printf("已删除\n");
	}
	else
		printf("error\n");
	
}

int main() {
	int num = 1,option;
	Data empty;
	empty.name[20]= { 0 };empty.posx = 0;empty.posy = 0;
	printf("城市链表程序 by 2015212040 \n ---------- \n 开始创建城市，请输入要创建的数量: ");
	scanf("%d",&num);
	CreateCity(num);
	while (true)
	{
		printf("\n ---------- \n 1---更新城市链表信息 \n 2---查找城市位置信息 \n 3---插入新的一个城市 \n ");
		printf("4--- 删除原有一个城市 \n 5--- 给定范围查找城市 \n 0---退出 \n");

	    while(!scanf("%d",&option))
        {
          fflush(stdin);
          printf("error\n");
        }
			switch (option)
			{
			case 1:ViewCity(L);break;
			case 2:GetCity(L);break;
			case 3:InsertCity(L);break;
			case 4:DeleteCity(L, empty);break;
			case 5:AreaCity(L);break;
			case 0:	return 0;
			default:printf("error");break;
			}
	}

}
