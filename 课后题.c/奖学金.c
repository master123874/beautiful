#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct student
{
	int p;
	int c,m,e;
	int total;
}stu[300];
void initial()
{
	int i;
	for(i=0;i<300;i++)
	{
		stu[i].total=0;
		stu[i].p=i+1;
	}
}
void input_student_score(int n)
{
	int i;
	for(i=0;i<n;i++)
	  scanf("%d%d%d",&stu[i].c,&stu[i].m,&stu[i].e);
}
void total_score(int n)
{
	int i;
	for(i=0;i<n;i++)
	   stu[i].total=stu[i].c+stu[i].m+stu[i].e;
}
void sort(int n)
{
	int i,j;
	struct student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(stu[j].total>stu[i].total)
			{
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
			else if(stu[j].total==stu[i].total)
			{
				if(stu[j].c>stu[i].c)
				{
					temp=stu[i];
				    stu[i]=stu[j];
				    stu[j]=temp;
				}
			}
		}
	}
}
main()
{
	int n;
	scanf("%d",&n);
	initial();
	input_student_score(n);
	total_score(n);
	sort(n);
	int i;
	for(i=0;i<5;i++)
    {
    	printf("%d %d",stu[i].p,stu[i].total);
    	if(i<4) printf("\n");   
	}
	return 0;   
}

