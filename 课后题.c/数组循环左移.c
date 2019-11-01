#include<stdio.h>
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int a[m];
	int i;
	for(i=0;i<m;i++)
	  scanf("%d",&a[i]);
	int t[m];  
	for(i=0;i<m;i++)
	  t[i]=a[i];
	if(n%m==0)/*移动数组长度个单位或不移动*/ 
	{
		for(i=0;i<m;i++)
		{
			printf("%d",a[i]);
			if(i<m-1)printf(" ");
		}	
	}
	else
	{
		for(i=0;i<m;i++)
		{
			if(i+n>=m)
			  a[(i+n)%m]=t[i];
			else a[i+n]=t[i];  
		}
		for(i=0;i<m;i++)
		{
			printf("%d",a[i]);
			if(i<m-1)printf(" ");
		}
	}  
}
