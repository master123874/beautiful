#include<stdio.h>
#define N 3
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char a[n],b[n];
	int win=0,p=0,lose=0;
	int B=0,C=0,J=0;
	int B1=0,C1=0,J1=0;
	
	for(i=0;i<n;i++)
	{
		getchar();
		scanf("%c %c",&a[i],&b[i]);
		if((a[i]=='B'&&b[i]=='C')||(a[i]=='C'&&b[i]=='J')||(a[i]=='J'&&b[i]=='B'))
		{
			win++;
			if(a[i]=='B')B++;
			else if(a[i]=='C')C++;
			else J++;
		}
		else if(a[i]==b[i])p++;
		else
		{
			lose++;
			if(b[i]=='B')B1++;
			else if(b[i]=='C')C1++;
			else J1++;
		}	
	}
	printf("%d %d %d\n",win,p,lose);
	printf("%d %d %d\n",lose,p,win);
	int c[N]={B,C,J},d[N]={B1,C1,J1};
	char e[N]={'B','C','J'};
	int max=0,max1=0,t;
	int t1;
	for(i=0;i<N;i++)
	{
		if(c[i]>max)
		{
			t=i;
			max=c[i];
		}
		if(d[i]>max1)
		{
			t1=i;
			max1=d[i];
		}
		
	}
	printf("%c %c",e[t],e[t1]);
	
	return 0;
}
	
