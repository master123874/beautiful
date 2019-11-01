#include<stdio.h>
#include<math.h>
typedef struct{
	int x,y;
	char a[5];
	float temp;
}S;
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	S max,min;
	S t;
	int flag=0;
	for(i = 0;i<n;i++)
	{
		scanf("%s %d %d",t.a,&t.x,&t.y);
		t.temp=sqrt(t.x*t.x+t.y*t.y);
		if(!flag)
		{
			max=t;
			min=t;
			flag=1;
		}
		else
		{
			if(max.temp<t.temp)max=t;
			if(min.temp>t.temp)min=t;
		}
	}
	printf("%s %s",min.a,max.a);
}
