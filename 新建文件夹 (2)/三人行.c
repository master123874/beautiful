#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int x,y;
	scanf("%d %d %d",&n,&x,&y);
	int i,j,k;
	int t[3];
	int flag=0;
	for(i=10;i<100;i++)
	{
		j=(i%10)*10+i/10;
		if(fabs((float)(i-j)/x)==(float)j/y)
		{
			flag=1;
			t[0]=i;
			t[1]=j;
			t[2]=j/y;
		}
	}
	if(!flag)
	{
		printf("No Solution");
		return 0;
	}
	printf("%d",t[0]);
	for(i=0;i<3;i++)
	{
		if(t[i]==n)printf(" Ping");
		else if(t[i]>n)printf(" Cong");
		else printf(" Gai");
	}
} 
