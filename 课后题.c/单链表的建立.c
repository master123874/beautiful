#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
	int xh;
	char sex;
	int old;
	int score;
	struct student *next;
};
int icount;
struct student *create()
{
	struct student *phead='NULL',*pnew,*pend;
	icount=0;
	pend=pnew=(struct student *)malloc(sizeof(struct student));
	if(pnew=NULL) exit(0);
	printf("性别请输入m或M或w或W\n");
	scanf("%c%d%d%d",&(pnew->sex),&(pnew->xh),&(pnew->old),&(pnew->score));
	while(pnew->score>=0&&pnew->old>=0)
	{
		icount++;
		if(icount==1)
		{
			pnew->next=phead;
			phead=pnew;
			pend=pnew;
		}
		else
		{
			pend->next=pnew;
			pnew->next=NULL;
			pend=pnew;
		}
		pnew=(struct student *)malloc(sizeof(struct student));
		scanf("%c%d%d%d",&(pnew->sex),&(pnew->xh),&(pnew->old),&(pnew->score));
		
	}
	free(pnew);
	return phead;
	
}
int main()
{
	*create();
	printf("总共有%d个学生",icount);
	struct student *ptemp;
	while(ptemp->next!=NULL)
	{
		printf("%c%d%d%d",ptemp->sex,ptemp->xh,ptemp->old,ptemp->score);
		ptemp=ptemp->next;
	}
	return 0;
}
 
