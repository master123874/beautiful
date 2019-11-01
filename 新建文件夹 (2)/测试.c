#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[10000];
	a[0]=1;
	int i,j;
	int digit=1;
	int temp,num=0;
	for(i=2;i<=n;i++)
	{
		for(j=0;j<digit;j++)
		{
			temp=a[j]*i+num;
			a[j]=temp%10;
			num=temp/10;
		}
		while(num)
		{
			a[digit]=num%10;
			num/=10;
			digit++;
		}
	}
	for(i=digit-1;i>=0;i--)printf("%d",a[i]);
	
}
