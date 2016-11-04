#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <malloc.h>
using namespace std;
typedef struct Data {                                      //���е���Ϣ
	char name[20];
	float posx;
	float posy;
}Data;
typedef struct City {                                      //����
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
LinkList CreateCity( int n) {                             //��ʼ����������
	LinkList p;
	printf("\n");
	L = (LinkList)malloc(sizeof(City));
	L->next = NULL;
	for (int i = 0;i < n;i++) {
		p = (LinkList)malloc(sizeof(City));
		printf( "����������֣�");scanf("%s",&p->data.name);
		printf( "������к�����: ");scanf("%f",&p->data.posx);
		printf( "�������������: ");scanf("%f",&p->data.posy);
		p->next = L->next;L->next = p;
	}
	return L;
}

void ViewCity(LinkList L) {                              //���²鿴
	LinkList p;
	p = L->next;
	printf("\n ��ǰ�����³��У�\n");
	while (p) {
		printf("%s : (%.1f,%.1f) \n",p->data.name,p->data.posx,p->data.posy);
		p = p->next;
	}
}

void GetCity(LinkList L) {                               //��ȡ����λ��
	LinkList p;
	printf("\n");
	char i[20];
	printf("�����������: ");scanf("%s",&i);
	p = L;
	while (p->next && strcmp(p->data.name,i)) {
		p = p->next;
	}
	if (!strcmp(p->data.name, i))
		printf("���� %s ��λ��Ϊ(%.1f,%.1f) \n", i, p->data.posx, p->data.posy);
    else
		printf("error\n");
}
	

void AreaCity(LinkList L) {                             //��ȡ��Χ�ڳ���
	LinkList p;
	printf("\n");
	float px, py,x1,y1,d,s;
	px = py = x1 = y1 = d = s = 0.0;
	printf("����λ�õĺ�����: "); scanf("%f", &px);
	printf("����λ�õ�������: "); scanf("%f", &py);
	printf("�������: ");scanf("%f", &d);
	p = L->next;
	printf("\n�����ĳ��еľ���С�ڵ���%.1f�ĳ����У�",d);
	while (p) {
		x1 = p->data.posx;
		y1 = p->data.posy;
		s = sqrt((x1 - px)*(x1 - px) + (y1 - py)*(y1 - py));
		if (s <= d) printf("%s ", p->data.name);
		p = p->next;
	}
	printf(". \n" );
}

void InsertCity(LinkList &L) {                          //��������
	LinkList p;
	printf("\n");
	p = L;
	while (p) { p = p->next; }
	p = (LinkList)malloc(sizeof(City));
	p->next = L->next;L->next = p;
	printf("����������֣�");scanf("%s", &p->data.name);
	printf("������к�����: ");scanf("%f",&p->data.posx);
	printf("�������������: ");scanf("%f", &p->data.posy);
	
	printf("\n");
}

void DeleteCity(LinkList L,Data e) {                   //ɾ������ 
	LinkList p,q;
	char i[20];
	printf("\n �����������: ");scanf("%s",&i);
	q= p = L->next;
	while (p->next && strcmp(p->data.name, i)) {
		q = p;
		p = p->next;
	}
	if (!strcmp(p->data.name, i)) {
        q->next = p->next;
	    e = q->data;free(p);
	    printf("��ɾ��\n");
	}
	else
		printf("error\n");
	
}

int main() {
	int num = 1,option;
	Data empty;
	empty.name[20]= { 0 };empty.posx = 0;empty.posy = 0;
	printf("����������� by 2015212040 \n ---------- \n ��ʼ�������У�������Ҫ����������: ");
	scanf("%d",&num);
	CreateCity(num);
	while (true)
	{
		printf("\n ---------- \n 1---���³���������Ϣ \n 2---���ҳ���λ����Ϣ \n 3---�����µ�һ������ \n ");
		printf("4--- ɾ��ԭ��һ������ \n 5--- ������Χ���ҳ��� \n 0---�˳� \n");

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
