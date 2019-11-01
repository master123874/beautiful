#include<stdio.h>
int main()
{
	int t,t1=0,t2=0,s1=0,s2=0;
	
	printf("请输入比赛时间：\n");
	scanf("%d",&t);
    while(t1<t&&t>0)
    {
    	if(s1>s2&&t1%10==0)
    	{
    		t2=t1+30;
    		while(t1<t2&&t1<t)
    		{
    			s2+=3;
    			t1++;
			}
		}
		else
		{
			t2=t1+10;
			while(t1<t2&&t1<t)
			{
				s1+=9;
				s2+=3;
				t1++;
			}
		}
	}
	if(s1>s2) printf("@_@ %d",s1);
	else if(s1==s2) printf("-_- %d",s1);
	else printf("^_^ %d",s2);
	
	return 0;
	
	

	


} 
