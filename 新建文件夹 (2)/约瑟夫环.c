#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;         
    struct Node *next;     
}NODE;
NODE *link(int number); 
void Joseph(NODE *p,int number,int n);
int main()
{
    int m,n;   
    printf("请输入总人数n和密码m:\n");
    scanf("%d",&n);
    scanf("%d",&m);
    NODE *head=NULL;
    head=link(n);
    Joseph(head,n,m);
    return 0;
}
	
NODE *link(int number)
{
    NODE *head=NULL,*p=NULL,*q=NULL;
    int i=1;
    head=(NODE *)malloc(sizeof(NODE));
    head->data=i;
    p=head;
    for(i=2; i<=number; i++)
    {
        q=(NODE *)malloc(sizeof(NODE));
        if(q==0)
            return 0;
        p->next=q;
        p=q;
        p->data=i;
    }
    p->next=head;
    return head;
}
void Joseph(NODE *p,int number,int n)
{
    int i,j;
    NODE *q=NULL;
    for(i=1; i<=number; i++)
    {
        for(j=1; j<n-1; j++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        p=p->next;
        printf("第%3d个出圈的人是：%3d\n",i,q->data);
        free(q);
    }
    printf("\n");
    p->next=NULL;
}

