#include<stdio.h>
int main()
{
	
	int  s=0;
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char c[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int n;
	scanf("%d",&n);
	char b[n][19];
	int i,j;
	char t;
	for(i=0;i<n;i++)
	  scanf("%s",b[i]);
	if(b[0][17]==c[6])printf("hjads");
} 
