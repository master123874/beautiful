#include<stdio.h>
#include<string.h>
#define N 1000
int main()
{
    char a[N],b[N],c[N];
    scanf("%s %s",a,b);
    int i,j;
    int count=0; 
    for(i=strlen(a)-1,j=strlen(b)-1;j>=0&&i>=0;j--,i--)
    {
        count++;
        if(count%2!=0)
        {
            int t=a[i]+b[j]-96;
            if(t%13==10)c[count-1]='J';
            else if(t%13==11)c[count-1]='Q';
            else if(t%13==12)c[count-1]='K';
            else c[count-1]=t%13+48;
        }
        else
        {
            int t1=b[j]-a[i];
            if(t1<0)c[count-1]=t1+10+48;
            else c[count-1]=t1+48;
        }
    }
    while(i>=0)
    {
    	count++;
        if(count%2!=0)c[count-1]=a[i];
        else c[count-1]='0'-a[i]+58;
        i--;
    }
    while(j>=0)
    {
    	c[count]=b[j];
    	count++;
    	j--;
    }
    int t1=0;
    char *d=c;
    c[count]='\0';
    while(*d!='\0')
      d++;
    d--;  
    while(*d=='0'&&t1<count)
	{
		t1++;
		d--;	
	}  
	if(count==t1)printf("0");
	else
	{
		for(i=count-t1-1;i>=0;i--)
		{
			printf("%c",c[i]);
		}
	}
    
}
