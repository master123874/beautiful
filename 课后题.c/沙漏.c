#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    char ch;
    scanf("%d %c",&n,&ch);
    int i,j;
    int ave=n/2;
    int count=0;
    for(i=1;i<ave;i++)
    {
        if(ave>(2*i+1))
        {
        	ave-=2*i+1;
        	count++;
		}
        else break;
    }
    for(i=0;i<2*count+1;i++)
    {
        for(j=0;j<count-abs(count-i);j++)
          printf(" ");
        for(j=0;j<2*abs(count-i)+1;j++)
		  printf("%c",ch);
		printf("\n");   
    }
    for(i=0;i<(2*count+1)/2;i++)
        n-=2*((2*count+1)-2*i);
    printf("%d",n-1);
    
}
