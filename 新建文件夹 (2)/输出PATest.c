#include<stdio.h>
#include<string.h>
#define N 10001
int main()
{
	char a[N];
	scanf("%s",a);
	int i,b[6];
	for(i=0;i<6;i++)b[i]=0;
	for(i=0;i<strlen(a);i++)
	{
		switch(a[i])
		{
			case 'P':{
				b[0]++;
				break;
			}
			case 'A':{
				b[1]++;
				break;
			}
			case 'T':{
				b[2]++;
				break;
			}
			case 'e':{
				b[3]++;
				break;
			}
			case 's':{
				b[4]++;
				break;
			}
			case 't':{
				b[5]++;
				break;
			}
			default:break;
		}
	}
	
	while(b[0]!=0||b[1]!=0|b[2]!=0||b[3]!=0||b[4]!=0||b[5]!=0)
	{
		if(b[0])
		{
			printf("%c",'P');
			b[0]--;
		}
		if(b[1])
		{
			printf("%c",'A');
			b[1]--;
		}
		if(b[2])
		{
			printf("%c",'T');
			b[2]--;
		}
		if(b[3])
		{
			printf("%c",'e');
			b[3]--;
		}
		if(b[4])
		{
			printf("%c",'s');
			b[4]--;
		}
		if(b[5])
		{
			printf("%c",'t');
			b[5]--;
		}
	}
}
