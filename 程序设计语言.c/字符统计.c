#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 1001
void sortof(int count[],int t1[],int t[],int s);
static int max;
char ch;
int count1=0; 
int main()
{
	char a[N];
	gets(a);
	int i;
	int j;
	int s=0;
	int temp=strlen(a);
	int count[temp];
    int t[temp];
	for(i=0;i<strlen(a);i++)
	{
		if(isalpha(a[i]))count[i]=1;
	}
	for(i=0;i<strlen(a)-1;i++)
	{
		if(a[i]!=-1&&isalpha(a[i]))
		{
			t[s]=i;
			s++;
			for(j=i+1;j<strlen(a);j++)
	    	if(tolower(a[i])==tolower(a[j]))
	        {
	        	count[i]++;
	        	a[j]=-1;
			}
		}
	}
	int t1[s];
	sortof(count,t1,t,s);        
	ch=a[t1[0]];
	for(i=1;i<count1;i++)
	  if(a[t1[i]]<ch)ch=a[t1[i]];
	printf("%c %d",tolower(ch),max); 
}
void sortof(int count[],int t1[],int t[],int s)
{
	register int i;
	max=count[t[0]];
	for(i=1;i<s;i++)
	  if(count[t[i]]>max)max=count[t[i]];
	for(i=0;i<s;i++)
	  if(max==count[t[i]])
	  {
	  	t1[count1]=t[i];
	  	count1++;
	  }   
}
