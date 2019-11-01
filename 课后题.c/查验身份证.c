#include<stdio.h>
#include<string.h>
#define N 20
int main()
{
	int a[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int n;
	scanf("%d",&n);
	char b[n][19];
	char c[11]={'1','0','X','9','8','7','6','5','4','3','2'};
	int i,j,count=0;
	long int s=0;
	for(i=0;i<n;i++)
	  scanf("%s",b[i]); 
	for(i=0;i<n;i++)
	{
		for(j=0;j<17;j++)
		{
			s+=a[j]*(b[i][j]-48);
		}
		if(b[i][j]==c[s%11]) count++;
		else printf("%s\n",b[i]);
		if(count==n)
		{
			printf("All passed");
			return 0;
		}
		s=0;
	} 
	
	return 0; 
	  
	
}
