#include<stdio.h>
#include<string.h>
int main()
{
	char ch,c[100000];
	int count=0,a=-1,i,t;
 	
	while(1)
	{
		scanf("%c",&ch);
		++a;
		c[a]=ch;
		if(ch=='.')break;

	}
	if(c[strlen(c)-2]==' ')
	{
	  for(i=strlen(c)-1;i>=0;i--)
	  {
	    if(c[i]!=' ') t=i;
	    break;
	  }
	  c[t+1]='.';
	  for(i=0;i<=t+1;i++)
	  {
		if(c[i]=='.')
		{
			if(count!=0)
			  printf("%d",count);

		}
		else if(c[i]==' '&&c[i+1]==' ')
		{
			if(count!=0) printf("%d",count);
			count=0;
		}
		else if(c[i]==' '&&c[i+1]!=' ')
		{
			if(count!=0)printf("%d ",count);
			count=0;
		}
		else if(c[i]!=' ')count+=1;
	  }
	}
	else
	{
		for(i=0;i<=strlen(c)-1;i++)
		
	   {
		if(c[i]=='.')
		{
			if(count!=0)
			  printf("%d",count);

		}
		else if(c[i]==' ')
		{
			if(count!=0) printf("%d ",count);
			count=0;
		}
		
		else if(c[i]!=' ')count+=1;
	   }
	}
	
	
	return 0;
}

	


	
	
