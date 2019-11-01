#include<stdio.h>
#include<string.h>
#define N 7
typedef struct{
    int score;
    char name[N];
    char school_name[N];
    int total,count;
    int rank;
}S;
static int num=0;
void process(S *a,int n)
{
    int i,j;
    float t;
    for(i = 0;i<n;i++)
    {
        if(a[i].score!=-1)
        {
        	a[i].count=1;
            t=0;
            if(a[i].name[0]=='A')t+=a[i].score;
            else if(a[i].name[0]=='B')t+=a[i].score/1.5;
            else if(a[i].name[0]=='T')t+=a[i].score*1.5;
            for(j=i+1;j<n;j++)
            {
            	if(!strcmp(strlwr(a[i].school_name),strlwr(a[j].school_name)))
            	{
            		a[i].count++;
            		if(a[j].name[0]=='A')t+=a[j].score;
            		else if(a[j].name[0]=='B')t+=a[j].score/1.5;
            		else if(a[j].name[0]=='T')t+=a[j].score*1.5;
            		a[j].score=-1;
				}
			}
            a[i].total=(int)t;
            a[num]=a[i]; 
            num++;
        }
    }
}
void sort(S *a)
{
    int i,j,change=1;
    for(i=0;i<num&&change;i++)
    {
        change=0;
        for(j=0;j<num-i-1;j++)
        {
            if(a[j].total<a[j+1].total)
            {
                change=1;
                S t;
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;    
            }
        }

    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    S a[n];
    for(i=0;i<n;i++)
    {
        scanf("%s %d %s",a[i].name,&a[i].score,a[i].school_name);
    }
    process(a,n);
    sort(a);
    int t,flag=0;
    printf("%d\n",num);
    int cou=1;
    int temp;
    for(i=0;i<num;i++)
    {
        if(!flag)
        {
        	temp=a[i].total;
        	a[i].rank=cou;
        	t=cou;
        	flag=1;
		}
		else
		{
			cou++;
			if(temp==a[i].total)
			{
				a[i].rank=t;
			}
			else 
			{
				t=cou;
				temp=a[i].total;
				a[i].rank=t;
			}
		}
        printf("%d %s %d %d\n",a[i].rank,strlwr(a[i].school_name),a[i].total,a[i].count);
    }
}
