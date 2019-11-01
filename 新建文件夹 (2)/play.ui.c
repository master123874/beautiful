#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#include<ctype.h>

#include"play.h"

int Play_UI_Modify(int id)
{
	int rtn=0;
	Play_t buf;
	if(Play_Srv_FetchByID(id,&buf)==1)
	{
		printf("---------------------------");
		printf("请输入修改的信息\n");
		printf("请输入剧目ID:");
		scanf("%d\n",&buf.id);
		printf("请输入剧目名称:");
		scanf("%s",&buf.name);
		printf("请输入剧目类型:");
		scanf("%d\n",&buf.type);
		printf("请输入剧目出品地区:");
		scanf("%s\n",&buf.area);
		printf("请输入剧目等级:");
		scanf("%d\n",&buf.rating);
		printf("请输入剧目时长:");
		scanf("%d\n",&buf.duration);
		printf("请输入剧目开放放映日期:");
		scanf("%d-%d-%d\n",&buf.start_date.year,&buf.start_date.month,&buf.start_date.day); 
		printf("请输入剧目结束放映日期:");
		scanf("%d-%d-%d\n",&buf.end_date.year,&buf.end_date.month,&buf.end_date.day);
		printf("请输入剧目票价:");
		scanf("%d\n",&buf.price); 
		printf("--------------------------");
		if(Play_Srv_Modify(&buf)==1)
		{
			printf("修改信息成功\n");
			rtn=1;
		}
		else
		{
			printf("修改信息失败\n");
			return 0;
		}
		 
	}
	else
	{
		printf("获取演出计划失败\n");
		return 0;
	}
	return rtn;
}
int Play_UI_Delete(int id)
{
	int rtn=0;
	if(Play_Srv_DeleteByID(id)==1)
	{
		rtn=1;
		printf("删除剧目演出计划成功\n");
		return rtn;
	}
	else
	{
		printf("删除剧目演出计划失败\n");
		return 0;
	}
}
int Play_UI_Add()
{
	play_t data;
	int newCount=0;
	char choice;
	do
	{
		printf("----------------------------------")
		printf("请输入修改的信息\n");
		printf("请输入剧目ID:");
		scanf("%d\n",&buf.id);
		printf("请输入剧目名称:");
		scanf("%s",&buf.name);
		printf("请输入剧目类型:");
		scanf("%d\n",&buf.type);
		printf("请输入剧目出品地区:");
		scanf("%s\n",&buf.area);
		printf("请输入剧目等级:");
		scanf("%d\n",&buf.rating);
		printf("请输入剧目时长:");
		scanf("%d\n",&buf.duration);
		printf("请输入剧目开放放映日期:");
		scanf("%d-%d-%d\n",&buf.start_date.year,&buf.start_date.month,&buf.start_date.day); 
		printf("请输入剧目结束放映日期:");
		scanf("%d-%d-%d\n",&buf.end_date.year,&buf.end_date.month,&buf.end_date.day);
		printf("请输入剧目票价:");
		scanf("%d\n",&buf.price);
		printf("---------------------------------");
		if(Play_Srv_Add(&data)==1)
		{
			printf("添加新剧目成功\n");
			newCount++; 
			printf("请输入是否继续继续增加新剧目:");
			choice=getchar();
		}
		else
		{
			printf("添加新剧目失败\n"); 
			return 0;
		}
	}while(choice!='a'||choice!='A');
	
	return newCount;
	
}
int Play_UI_Query(int id)
{
	int rtn=0;
	if(Play_UI_FetchByID(id)==1)
	{
		rtn=1;
		printf("查询剧目界面成功");
		return rtn;
	}
	else
	{
		prinf("查询剧目界面失败");
		return 0;
	}
}
