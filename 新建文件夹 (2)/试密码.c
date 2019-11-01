#include<stdio.h>
#include<string.h>
#define M 1000
int main()
{
    int m;
    char correct[M];
    scanf("%s %d",correct,&m);
    int flag=1,t=0;
    char an[M]="";
    while(1)
    {
        char t1[M];
        scanf("%s",t1);
        if(!strcmp(t1,"#"))break;
        m--;
        if(m>=0)
        {
        	if(!strcmp(t1,correct))
        	{
            	strcat(an,"Welcome in\n");
        	}
        	else
        	{
        		strcat(an,"Wrong password: ");
        		strcat(an,t1);
        		strcat(an,"\n");
        		if(m==0)
        		{
        		   strcat(an,"Account locked");
        		}
			}
		}
    }
    printf("%s",an);
}
