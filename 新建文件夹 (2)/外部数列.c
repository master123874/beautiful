#include<stdio.h>
#include<string.h>
#define N 10000
void insert(int *j,int s,char ch,char a[N],char b[N]);
int count;
int main()
{
	int m,n;
	char a[N],b[N];
	scanf("%d %d",&m,&n);
	b[0]=(char)(m+48);
	int t=1,length;
	int i,s;
	int j;
	for(;t<n;t++)
	{
		strcpy(a,b);
		s=strlen(a);
		count=0;
		i=0; 
		for(;i<s;)
		{
			switch(a[i])
			{
				case '0':{
					insert(&i,s,a[i],a,b); 
					break;
				}
				case '1':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '2':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '3':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '4':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '5':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '6':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '7':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '8':{
					insert(&i,s,a[i],a,b);
					break;
				}
				case '9':{
					insert(&i,s,a[i],a,b);
					break;
				}	
			}
		}
	}	
	printf("%s",b);		
} 
void insert(int *j,int s,char ch,char a[N],char b[N])
{
	int length=1;
	int z=*j+1;
	for(;z<s;z++)
	{
		if(ch==a[z])length++;
		else break;
    }
    *j=z;
	b[count++]=ch;
	b[count++]=(char)(length+48);
}
