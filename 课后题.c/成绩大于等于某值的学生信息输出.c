#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node {
     int    num;
     char   name[20];
     int    score;
     struct stud_node *next;
};
struct stud_node *Creat_Stu_Doc();
struct stud_node *DeleteDoc(struct stud_node *head,int min_score);
void Ptrint_Stu_Doc(struct stud_node *head);
int main()
{
    struct stud_node *head;
    int min;
    head=Creat_Stu_Doc();
    scanf("%d",&min);
    head=DeleteDoc(head,min);
    Ptrint_Stu_Doc(head);
    return 0;
}
struct stud_node *Creat_Stu_Doc()
{
    struct stud_node *L=NULL,*pnew,*pend;
    int icount=0;
    pnew=pend=(struct stud_node *)malloc(sizeof(struct stud_node));
    scanf("%d",&pnew->num);
    if(pnew->num==0)return L;
    scanf("%s %d",pnew->name,&pnew->score);
    while(1)
    {
        icount++;
        if(icount==1)
        {
            pnew->next=L;
            L=pnew;
            pend=pnew;
        }
        else
        {
            pnew->next=NULL;
            pend->next=pnew;
            pend=pnew;
        }
        pnew=(struct stud_node *)malloc(sizeof(struct stud_node));
        scanf("%d",&pnew->num);
        if(pnew->num==0)break;
        scanf("%s %d",pnew->name,&pnew->score);
    }
    free(pnew);
    return L;
}
struct stud_node *DeleteDoc(struct stud_node *head,int min_score)
{
	struct stud_node *h,*p,*q;
    h=head;
    while((h->score<min_score)&&(h->next!=NULL)){
        p=h->next;
        free(h);
        h=p;
    }
    if(h->score<min_score){
        return NULL;
    }
    p=h;
    q=h->next;
    while(q){
        if(q->score<min_score){
        p->next=q->next;
        free(q);
        q=p->next;
        continue;
        }
        else{
            p=q;
            q=p->next;
        }
    }
    return h;
}
void Ptrint_Stu_Doc(struct stud_node *head)
{
	struct stud_node *temp=head;
    while(temp)
    {
    	printf("%d %s %d\n",temp->num,temp->name,temp->score);
    	temp=temp->next;
	} 
}
