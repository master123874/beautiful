#include<stdio.h>
#define N 10000
int main()
{
	int a[N];
	int k1=0;
	int i,digit=1;
	a[0]=1;
	int n;
	int j,k;
	int t; 
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		int num=0;
		for(j=0;j<digit;j++)
		{
			t=a[j]*i+num;
			a[j]=t%10;
			num=t/10;
		}
		while(num>0)
		{
			a[digit]=num%10;
			num/=10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)
       printf("%d",a[i]);
    printf("\n");   
    return 0;   
	   
} 
