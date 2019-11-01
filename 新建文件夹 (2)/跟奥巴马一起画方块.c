#include<stdio.h>
void print(int n,int m,char ch)
{
	int i,j;
	for(i=0;i<n;i++)
    {
    	for(j=0;j<m;j++)
    	{
    		printf("%c",ch);
		}
		printf("\n");
	}
}
int main()
{
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    int i,j;
    if(n%2==0)print(n/2,n,ch);
    else print(n/2+1,n,ch);
    
}
