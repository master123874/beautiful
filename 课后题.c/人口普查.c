#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct birth
{
    int year;
    int month;
    int day;
};
struct a
{
    char name[6];
    struct birth i1;
};
void search2(struct a stu[],int n);
void search1(struct a stu[],int *p,int n);
void search3(struct a stu[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    struct a stu[n];
    int temp=n;
    for(i=0;i<n;i++)
      scanf("%s %d/%d/%d",stu[i].name,&stu[i].i1.year,&stu[i].i1.month,&stu[i].i1.day);
    search1(stu,&temp,n);
    printf("%d",temp);
    search2(stu,n);
    search3(stu,n);
}
void search1(struct a stu[],int *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(2014-stu[i].i1.year>200)(*p)--;
        else if(2014-stu[i].i1.year<0)(*p)--;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month>9) (*p)--;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month==9&&stu[i].i1.day>6) (*p)--;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month<9)(*p)--;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month==9&&stu[i].i1.day<6)(*p)--;
    }
}
void search3(struct a stu[],int n)
{
    int i;
    static int t;
    for(i=0;i<n;i++)
    {
        if(2014-stu[i].i1.year>200)continue;
        else if(2014-stu[i].i1.year<0)continue;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month>9) continue;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month==9&&stu[i].i1.day>6) continue;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month<9)continue;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month==9&&stu[i].i1.day<6)continue;
        else
        {
            if(stu[i].i1.year>stu[t].i1.year) t=i;
            else if(stu[i].i1.year==stu[t].i1.year)
            {
                if(stu[i].i1.month>stu[t].i1.month) t=i;
                else if(stu[i].i1.month==stu[t].i1.month&&stu[i].i1.day>stu[t].i1.day) t=i;
            }
        }
    }
    printf(" %s",stu[t].name);
}
void search2(struct a stu[],int n)
{
    int i;
    static int t1;
    for(i=0;i<n;i++)
    {
        if(2014-stu[i].i1.year>200)continue;
        else if(2014-stu[i].i1.year<0)continue;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month>9) continue;
        else if(2014-stu[i].i1.year==0&&stu[i].i1.month==9&&stu[i].i1.day>6) continue;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month<9)continue;
        else if(2014-stu[i].i1.year==200&&stu[i].i1.month==9&&stu[i].i1.day<6)continue;
        else
        {
        	
            if(stu[i].i1.year<stu[t1].i1.year) t1=i;
            else if(stu[i].i1.year==stu[t1].i1.year)
            {
                if(stu[i].i1.month<stu[t1].i1.month) t1=i;
                else if(stu[i].i1.month==stu[t1].i1.month&&stu[i].i1.day<stu[t1].i1.day) t1=i;
            }
        }
    }
    printf(" %s",stu[t1].name);
}

