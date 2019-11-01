#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int y,f;
    for(y=1;y<=100;y++)
    {
        for(f=y;f<=100;f++)
        {
            if(f*100+y-n==2*y*100+2*f)
            {
            	printf("%d.%d",y,f);
            	return 0;
			}	 
        }
    }
    printf("No Solution");
}
