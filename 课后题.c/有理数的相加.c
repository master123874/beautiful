#include<stdio.h>
#include<stdlib.h>
struct s
{
	int fenzi;
	int fenmu;
}p[2];
void yuefen();
int main()
{
	int i;
	for(i=0;i<2;i++)
	  scanf("%d/%d",&p[i].fenzi,&p[i].fenmu);
	yuefen();  
}
void yuefen()
{
	
	p[0].fenzi=p[0].fenzi*p[1].fenmu;
	p[1].fenzi=p[0].fenmu*p[1].fenzi;
	p[0].fenmu=p[0].fenmu*p[1].fenmu;
	int temp=p[0].fenzi+p[1].fenzi;
	printf("%d",temp);
	int temp1=temp>p[0].fenmu?p[0].fenmu:temp;
	if(temp%p[0].fenmu==0)
	{
		printf("%d",temp/p[0].fenmu);
		return;
	}
	int flag=0;
	while(temp1>1)
	{
		if(temp%temp1==0&&p[0].fenmu%temp1==0)
		{
			flag=1;
			if(p[0].fenmu/temp1==1)
			{
				printf("%d",temp/temp1);
				break;
			} 
			else
			{
				printf("%d/%d",temp/temp1,p[0].fenmu/temp1);
				break;
			}
		
		}
		else temp1--;
	}
	if(flag==0)printf("%d/%d",temp,p[0].fenmu);
	
	
	
	
	
		
	
	 
}

