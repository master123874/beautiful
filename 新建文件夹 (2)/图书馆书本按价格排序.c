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
void sortof(S p[],int m)
{
	int i,j;
	S temp;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-i-1;j++)
		{
			if(p[j].price>p[j+1].price)
			{
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
			}
		}
	}
}
int main()
{
	int m;
	scanf("%d",&m);
	if(m>20)return 0;
	S p[m];
	int i;
	for(i=0;i<m;i++)
	{
		scanf("%d %s %s %s %d-%d-%d %lf",&p[i].id,p[i].name,p[i].author,p[i].section,&p[i].date.year,&p[i].date.month,&p[i].date.day,&p[i].price);
	}
	printf("\n");
	sortof(p,m);
	printf("编号 书名 作者 出版社 出版日期 价格\n"); 
	for(i=0;i<m;i++)
	{
		printf("%d %s %s %s %d年%d月%d日 %.2lf\n",p[i].id,p[i].name,p[i].author,p[i].section,p[i].date.year,p[i].date.month,p[i].date.day,p[i].price);
	}  

}
