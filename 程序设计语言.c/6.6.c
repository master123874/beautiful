#include<stdio.h>
#include<math.h>

int main()
{
	int k=1,n=1,s=1,count=0;
	double z,b,x,t,a=0 c ;
	scanf("%f",&x);
	
	b=x;
	z=x*x;
	while(fabs(b)>=1e-5)
	{
		a+=b; 
		s=-s;
		n=n+2;
		count++;
		x*=z;
		k=k*n*(n-1);
		b=s*x/k;
		
		
		
		
	}
	
	printf("%f,%d",a,count);
	return 0;
	
} 
