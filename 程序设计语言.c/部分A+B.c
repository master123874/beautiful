#include<stdio.h>
#include<math.h> 
int  main()
{
	long int b,d,count=0,coun=0,a,c;
	int e=0,f=0;
	scanf("%ld%ld%ld%ld",&a,&b,&c,&d);
	while(a!=0)
	{
		if(b==a%10)
		{
			e=e+b*pow(10,count);
			count++;
			
			
			
		}
		a/=10;
	}
	while(c!=0)
		
	{
		if(d==c%10)
		{
			f=f+d*pow(10,coun);
			coun++;
			
			
			
		}
		c/=10;
	}
	printf("%d",e+f);
	
	
	return 0;
} 
