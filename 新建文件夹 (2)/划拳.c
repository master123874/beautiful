#include<stdio.h>
typedef struct{
	int a,b,c,d;
}S;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int l1=0,l2=0;
	S t;
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&t.a,&t.b,&t.c,&t.d);
		if(t.b==t.a+t.c&&t.d!=t.a+t.c)l2++;
		else if(t.b!=t.a+t.c&&t.d==t.a+t.c)l1++;
	}
	printf("%d %d",l1,l2);
}
