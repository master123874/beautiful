#include<stdio.h>
#include<string.h>
#define N 100
int judge(char a)
{
	int i;
	if(a=='a'||a=='i'||a=='e'||a=='o'||a=='u'||a=='y')
	  return 0;
	return 1;  
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	char a[N];
	for(i=0;i<n;i++)
	{
		scanf("%s",a);
		for(j=0;j<strlen(a);j++)
		{
			if(j==0)printf("%c",a[j]);
			else if(judge(a[j]))printf("%c",a[j]);
		}
		printf("\n");
	}
	int b=(int)'5';
	printf("%d",b);
}
 
