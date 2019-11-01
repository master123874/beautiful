#include<stdio.h>
int main()
{
	int a,j,k,i,c;
	for(a=1000;a<10000;a++)
	{
		j=a/100;
		k=a-j*100;
		
		i=(j+k)*(j+k);
		if(i==a)
		{
			c=i;
			printf("%d\n",c);
		}
		
	}

	
	return 0;
}
