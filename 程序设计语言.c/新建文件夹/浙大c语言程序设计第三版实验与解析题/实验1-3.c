#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,count=0;
	
	while(1)
	{
		scanf("%d",&n);
		count++;
		if(count==1)printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
		if(count>5) break;
		switch(n)
		{
			case 1:printf("price = %.2f\n",3.00);break;
			case 2:printf("price = %.2f\n",2.5);break;
			case 3:printf("price = %.2f\n",4.10);break;
			case 4:printf("price = %.2f\n",10.2);break;
			case 0:printf("price = %.2f\n",0);exit(0);
		}
		
	}
} 
