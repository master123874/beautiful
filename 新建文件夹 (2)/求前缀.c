#include<stdio.h>
#include<string.h>
#define N 21
int main()
{
	
	int t;
	scanf("%d",&t);
	char a[t][N],b[t][N];
	int i,j;
	char temp[N];
	int flag=0; 
	int count=0;
	for(i=0;i<t;i++)
	  scanf("%s %s",a[i],b[i]);
	for(i=0;i<t;i++)
	{
		for(j=0;j<strlen(a[i])&&j<strlen(b[i]);j++)
		{
			if(a[i][j]==b[i][j])
			{
				temp[j]=a[i][j];
				flag=1;
			}
			else break;
		}
		temp[j]='\0';
		if(flag&&!count)
		{
			printf("%s",temp);
			flag=0;
			count++;
		}
		else if(count&&flag)
		{
			printf("\n%s",temp);
			flag=0;
		}
		else
		{
			printf("\n无公共前缀"); 
			return 0;	
		}
		
	}  
	
}
 
