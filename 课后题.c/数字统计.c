#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define N pow(2,31)-1
int main()
{
	int n;
	int i;
	scanf("%d",&n);
	int count=0;
	static int count1[10]; 
	for(i=0;i<10;i++)
	  count1[i]=0;
	int a[100];
	for(i=1;i<=n;i++)
	{
		while(i>0)
		{
			a[count]=i%10;
			i/=10;
			count++;
		}
	}
	for(i=0;i<count;i++)
	{
		if(a[i]==0) count1[0]++;
		else if(a[i]==1)count1[1]++;
		else if(a[i]==2)count1[2]++;
		else if(a[i]==3)count1[3]++;
		else if(a[i]==4)count1[4]++;
		else if(a[i]==5)count1[5]++;
		else if(a[i]==6)count1[6]++;
		else if(a[i]==7)count1[7]++;
		else if(a[i]==8)count1[8]++;
		else if(a[i]==9)count1[9]++;
	}
	for(i=0;i<10;i++)
	  printf("%d\n",count1[i]);	 
} 
