#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"schedule.h"
int Schedule_Perst_SelectAll(schedule_list_t list)
{
	
	int recCount=0;
	FILE fp;
	fp=fopen("Schedule.dat","rb");
	if(!fp)
	{
		printf("%s文件打开失败");
		return 0;
	}
	list=NULL;
	schedule_list_t newNode,ptemp=list;
	newNode=(schedule_list_t)malloc(sizeof(schedule_node_t));
	while(!feof(fp))
	{
		fread(newNode,sizeof(schedule_list_t),1,fp);
		if(!list)
		{
			list=newNode;
		}
		else
		{
			ptemp->next=newNode;
			ptemp=newNode;
		}
		recCount++;
		newNode=(schedule_list_t)malloc(sizeof(schedule_node_t));
	}
	fclose(fp);
	return recCount;
}
int Play_Perst_SelectByName(play_list_t list,char condt[])
{
	int recCount=0;
	list=NULL;
	FILE fp;
	play_list_t newNode;
	play_list_t temp=list;
	fp=fopen("Play.dat","rb");
	if(!fp)
	{
		printf("%s文件打开失败");
		return 0;
	}
	while(!feof(fp))
	{
		fread(&newNode,sizeof(play_node_t),1,fp);
		if(!strstr(newNode.data.name,condt))
		{
			if(!list)
			{
				list=&newnode;
				temp=list;
			}
			else
			{
				ptemp=&newNode;
				ptemp=ptemp->next;
			}
			recCount++;
		}
		
	}
	fclose(fp);
	return recCount;	
}

