#include<stdio.h>
#include<string.h>
#include"List.h"
#include"ticket.h"

void Ticket_UI_MgtEntry(int schedule_id)
{
	schedule_t buf;
	play_t data;
	char choice; 
	if(Schedule_Srv_FetchByID(schedule_id,&buf)==1)
	{
		printf("获取演出计划成功\n");
		if(Play_Srv_FetchByID(buf.play_id,&data)==1)
		{
			printf("获取剧目信息成功");
			printf("请输入你的选项a/A:生成演出票,b/B:重新生成票:");
			scanf("%c",&choice);
			switch(choice)
			{
				case 'a':
				case 'A':{
					if(Ticket_Srv_GenBatch(buf.id)>=0)
					{
						printf("\t\t\t生成票操作成功\n");
						printf("\t\t\t剧目名称    演出厅ID     演出日期      演出时间\n");
						printf("\t\t\t%s       %4d         %04d-%02d-%02d       %02d:%02d:%02d",data.name,buf.studio_id,buf.date.year,buf.date.month,buf.date.day,buf.time.hour,buf.time.minute,buf.time.second);
						
					else
					{
						printf("生成票操作失败");
					}
					break;
				} 
				case 'B':
				case 'b':{
					if(Ticket_Srv_DeleteBatch(buf.id)>=0)
					{
						printf("操作成功\n");
						if(Ticket_Srv_GenBatch(buf.id)==0)
						{
							printf("已经打印过,无法再次打印");
						}
						
						
					}
					else
					{
						printf("操作失败\n");
					}
					break;
				} 
				default:printf("无对应的选项\n");break;
				
			}
		}
		
	}
	else
	{
		printf("获取演出计划失败\n");
		return;
	}
}

