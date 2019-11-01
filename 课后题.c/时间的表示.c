#include<stdio.h>
#include<stdlib.h>
struct s
{
	int h,m,s;
};
int main()
{
	struct s m1;
	scanf("%d:%d:%d",&m1.h,&m1.m,&m1.s);
	int n;
	scanf("%d",&n);
	if(m1.s+n>=60)
	{
		m1.s=(m1.s+n)%60;
		m1.m++;
		if(m1.m>=60)
		{
			m1.m=m1.m%60;
			m1.h++;
			if(m1.h>=24)
			  m1.h=m1.h%24;
			printf("%02d:%02d:%02d",m1.h,m1.m,m1.s);
			return 0;
			
		}
	}
	printf("%02d:%02d:%02d",m1.h,m1.m,m1.s+n);
	
}
