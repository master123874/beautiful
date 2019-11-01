#include<stdio.h>
typedef struct{
	int a,b;
}S;
int main()
{
    S t;
    int flag=0;
    int count=0;
    while(scanf("%d %d",&t.a,&t.b)!=EOF)
    {
    	
    	if(t.a!=0&&t.b!=0&&!flag)
    	{
    		flag=1;
			printf("%d %d",t.a*t.b,t.b-1);
		}
		else if(t.a!=0&&t.b!=0&&flag)printf(" %d %d",t.a*t.b,t.b-1);
		if (t.b!=0&&t.a!=0)
		{
			count++;
		}	
	}
	if(!count)printf("0 0");
	
} 
