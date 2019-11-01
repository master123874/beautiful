#include<stdio.h>
#include<math.h> 
/*判断两者是否有公因数 */
int ifs(long long a,long long b)
{
	int i,min;
	if (a<b) min=a;
	else min=b;
	for (i=min;i>=2;i--)
	{
		if (a%i==0&&b%i==0) return i;
	}
	return 0;
} 
int main()
{
	
	int N,i;
	long long a1,b1,a2,b2;
	int c=0,d=1,f; 
	scanf("%d",&N);
	for (i=0;i<N;i++)
	{
		scanf("%lld/%lld",&a2,&b2);
		if(b2==d)
		{
			c+=a2;
		}
		else
		{
			c=c*b2+d*a2;
			d=d*b2;
		}
	}
	if (c==0)
	{
		printf("0");
	}
	else if (c==d) printf("1"); 
	else if(c==-d)printf("-1");
	/*真分数*/
	else if (abs(c)<abs(d))
	{
		f=ifs(abs(c),abs(d));
		if (f == 0)
		{
			printf("%d/%d",c,d);
		}
		else if ((d/f)==1)
		{
			printf("%d",(c/f));
		}
		else if((d/f)==-1)printf("%d",-(c/f));
		else
		{
			printf("%d/%d",(c/f),(d/f));
		}
	}
	/*假分数*/
	else if(abs(c)>abs(d))
	{
		int x;
		f=ifs(abs(c),abs(d));
		if (f == 0)
		{
			x=c/d;
			c=c%d;
			printf("%d %d/%d",x,c,d);
		}
		else if ((d/f)==1)
		{
			printf("%d",(c/f));
		}
		else if((d/f)==-1)printf("%d",-(c/f));
		else
		{
			printf("%d %d/%d",c/d,(c/f)%(d/f),(d/f));
			
		}
	}
	return 0;
}
