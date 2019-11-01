#include <stdio.h>
int main() 
{
	int n;
	float height;
	scanf("%d",&n);
	char c;
	int i;
	for(i = 0; i < n; i++) 
	{
	
		scanf(" %c %f",&c,&height); 
		if (c == 'M')
		 printf("%.2f\n", height / 1.09);
	    else
		 printf("%.2f\n", height * 1.09);
	}
	return 0;
}

