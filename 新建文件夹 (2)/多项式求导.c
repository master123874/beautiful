#include<stdio.h>
typedef struct{
	int a,b;
}S;
int main()
{
    S t;
    int flag=0;
    while(scanf("%d %d",&t.a,&t.b)!=EOF)
    {
    	
    	if(t.b!=0&&t.a!=0&&flag==0)
    	{
    		flag=1;
			printf("%d %d",t.a*t.b,t.b-1);
		}
		else if(t.b!=0&&t.a!=0&&flag)printf(" %d %d",t.a*t.b,t.b-1);
		if (t.b==0&&t.a==0&&getchar()=='\n')
		{
			printf("%d %d",0,0);
			return 0;
		}
		
	}
	
} 
