#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
struct t{
	int year;
	int month;
	int day;
};
typedef struct book{
	char name[N+1];
	char section[N+1];
	int id;
	char author[N+1];
	struct t date;
	double price;
}S;
void insert(S p[],int m,S temp,int n)
{
	int i;
	for(i=m;i>n-1;i--)
	{
		p[i]=p[i-1];
	}
	p[i]=temp;
}
int main()
{
	int m,n;
	scanf("%d",&m);
	if(m>20)return 0;
	S p[m+1],temp;
	int flag=0;
	int i;
	for(i=0;i<m;i++)
	  scanf("%d %s %s %s %d-%d-%d %lf",&p[i].id,p[i].name,p[i].author,p[i].section,&p[i].date.year,&p[i].date.month,&p[i].date.day,&p[i].price);
	scanf("%d",&n);
	if(n<=0)return 0;
	scanf("%d %s %s %s %d-%d-%d %lf",&temp.id,temp.name,temp.author,temp.section,&temp.date.year,&temp.date.month,&temp.date.day,&temp.price);
	insert(p,m,temp,n);
	printf("编号 书名 作者 出版社 出版日期 价格"); 
	for(i=0;i<m+1;i++)
	{
		printf("\n%d %s %s %s %d年%d月%d日 %.2lf",p[i].id,p[i].name,p[i].author,p[i].section,p[i].date.year,p[i].date.month,p[i].date.day,p[i].price);
	
	}  
}
