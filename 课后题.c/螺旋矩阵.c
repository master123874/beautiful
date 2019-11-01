#include<stdio.h>
int size,a[11][11],i,j,num;
int xuanzhuan(int n);
int main()
{
	i=j=1;
	num=1;
	scanf("%d",&size);
	xuanzhuan(size);
	for(i=1;i<=size;i++)
	{
		for(j=1;j<=size;j++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
} 
int xuanzhuan(int n)
{
	int k;
	if(n==0) return 0;
	if(n==1)
	{
		a[i][j]=num++;
		return 0;
	}
	for(k=1;k<n;k++,j++)
	  a[i][j]=num++;
	for(k=1;k<n;k++,i++)
	  a[i][j]=num++;
	for(k=1;k<n;k++,j--)
	  a[i][j]=num++;
	for(k=1;k<n;k++,i--)
	  a[i][j]=num++; 
	i++;
	j++;   
	xuanzhuan(n-2);     
}

