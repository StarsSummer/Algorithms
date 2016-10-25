#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
int a[10000]; 

typedef struct Loop{
	int data;
	int password;
	struct Loop *next;
}Loop, *LinkList;
	
LinkList CreateLoop(int n){                        //����ѭ������ 
    LinkList p,q,head;
    int i;
    p=(LinkList)malloc(sizeof(Loop));
    head=p;
    p->data=1;p->password=a[0];
    p->next=p;
    for(i=2;i<=n;i++)
    {
    	q=(LinkList)malloc(sizeof(Loop));
    	q->data=i;
    	q->password=a[i-1];
    	p->next=q;
    	p=q;
	}
	p->next=head;
	return head;
}
void begin(LinkList head,int n){                   //Լɪ������ִ�й��� 
    int i,m;
    m=n;
    LinkList p=head,q;
    printf("���е�˳��Ϊ��");
    while(p->next!=p)
    {
    	for(i=1;i<m;i++)
    	{
    		q=p;
    		p=p->next;
		}
		printf(" %d ",p->data);
		m=p->password;
		q->next=p->next;
		free(p);
		p=q->next;
	}
    printf(" %d\n",p->data);
    free(p);
}

int main()
{

	int i,m,num; 
	printf("������Լɪ���е�����: ");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("��%d���˵�������: ",i+1);
		scanf("%d",&a[i]);
	 } 
	LinkList Head=CreateLoop(7);
	printf("�������ʼ�ı���ֵ�� ");
	scanf("%d",&m); 
	begin(Head,m);
	system("pause");
	return 0;
}

/*������� 
int main()
{
	int a[]={3,1,7,2,4,8,4};
	LinkList Head=CreateLoop(7);
	begin(Head,20);
	system("pause");
	return 0;
}
*/

