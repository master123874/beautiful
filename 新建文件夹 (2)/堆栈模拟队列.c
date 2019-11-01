#include<stdio.h>
#include<stdlib.h>
int m,n;
static int length=0;
void push(int *a,int t)
{
	a[length]=t;
	length++;
}
int main()
{
	scanf("%d %d",&m,&n);
	int a[m+n];
	while(1)
	{
		char c;
		scanf("%c",&c);
		if(c=='T')break;
		else if(c=='A')
		{
			int t;
			scanf("%d",&t);
			if(length+1==m+n)printf("ERROR:Full\n");
			else push(a,t);
		}
		else if(c=='D')
		{
			int t1;
			if(length==0)printf("ERROR:Empty\n");
			else
			{
				printf("%d\n",a[0]);
				int j;
				for(j=0;j<length-1;j++)a[j]=a[j+1];
				length--;
			}
		}
			
	}
}
