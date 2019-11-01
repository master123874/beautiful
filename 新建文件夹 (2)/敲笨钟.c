#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 120
#define M 3
#define S "ong"
#define C " qiao ben zhong."
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	char a[N];
	getchar();
	int t;
	for(i=0;i<n;i++)
	{
		t=M;
		gets(a);
		char *s=a;
		char t2[M+1],t1[M+1];
		int count=0;
		while(*s!=',')s++;
		while(t)
		{
			t--;
			s--;
			t2[t]=*s;
		}
		t=M;
		while(*s!='.')s++;
		while(t)
		{
			t--;
			s--;
			t1[t]=*s;
		}
		if(!strcmp(t2,S)&&!strcmp(t1,S))
		{
			int z=3;
			s=&a[strlen(a)-1];
			while(z)
			{
				s--;
				if(*s==' ')z--;
			}
			*s='\0';
			strcat(a,C);
			printf("%s\n",a);
		}
		else printf("Skipped\n");
	}
}

