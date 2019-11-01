#include<stdio.h>
#include<string.h>
#define n 4
#define N 61
int main()
{
	char a[n][N];
	int i,j=0;
	char b[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	for(i=0;i<n;i++)
	  scanf("%s",a[i]);
	for(i=0;i<strlen(a[0])&&i<strlen(a[1]);i++)
	{
		if(j==1&&a[0][i]==a[1][i])
		{
			if(isdigit(a[0][i]))
			{
				j++;
				printf(" %02d",a[0][i]-'0');
				
			}
			else if(isupper(a[0][i]))
			{
				j++;
				printf(" %02d",a[0][i]-'A'+10);
			}
		}
		if(j==0&&a[0][i]==a[1][i]&&isupper(a[0][i]))
		{
			j++;
			printf("%s",b[a[0][i]-'A']);
		}
		if(j>1)break;	
	}
	for(i=0;i<strlen(a[2])&&i<strlen(a[3]);i++)
	{
		if(isalpha(a[2][i])&&a[2][i]==a[3][i])
		{
			printf(":%02d",i);
			break; 
		}
		
	}  
}
