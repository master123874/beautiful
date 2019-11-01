#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"schedule.h"
static const int a=5;

void Schedule_UI_MgtEntry(int play_id)
{
	play_t buf;
	schedule_t buf1;
	int id;
	Pagination_t paging;
	schedule_list_t list;
	char choice;
	schedule_node_t *pos;
	int i;
	int a,b,c,d,e,f;
	schedule_t data;
	if(Schedule_Srv_FetchByID(play_id,&buf)==1)
	{
		List_Init(list,schedule_node_t);
		count=Schedule_Srv_FetchByPlay(list,play_id)
		paging.offset=0;
		paging.pageSize=a;
		paging.totalRecords=count;
		Paging_Locate_FirstPage(list,paging);
		do
		{
			printf("---------------------------------------------------\n");
			printf("-------------------------当前演出计划信息---------------------\n");
			printf("******************************************************************\n");
			printf("演出计划ID      上映剧目ID        演出厅ID        放映日期       放映时间      座位数\n");
			Paging_ViewPage_Foreach(list,paging,schedule_node_t,pos,i){
				a=pos->data.date.year;
				b=pos->data.date.month;
				c=pos->data.date.day;
				d=pos->data.time.hour;
				e=pos->data.time.minute;
				f=pos->data.time.second;
				printf("%d         %d         %d\t\t%d-%d-%d\t\t%d:%d:%d\t\t%d",pos->data.id,pos->data.play_id,pos->data.studio_id,a,b,c,d,e,f,pos->data.seat_count);
				
			}
			printf("----------------------总记录:%2d--------------------------------Page %2d/%2d----\n",paging.totalRecords,Paging_Curpage(paging),Paging_TotalPages(paging));
			printf("******************************************************************************************\n");
			
			printf("[t]:查询演出计划,[a]:添加演出计划,[u]:修改演出计划,[d]:删除演出计划,[p]:返回上一页,");
			printf("[n]:下一页,[r]:返回\n");
			printf("请输入你的选择:");
			scanf("%c",&choice);
			fflush(stdin);
			printf("\n");
			switch(choice)
			{
				case 't':
				case 'T':{
					
					printf("请输入你的演出计划ID\n");
					scanf("%d",&id);
					if(Schedule_Srv_FetchByID(id,&buf1)==1)
					{
						printf("获取演出计划成功"); 
						getchar();
						paging.totalRecords=Schedule_Srv_FetchAll(list);
						List_Paging(list,paging,schedule_node_t);
						Ticket_UI_MgtEntry(id);
					}
					else
					{
						printf("获取演出计划失败\n");
					} 
					break;
				}
				case 'a':
				case 'A':{
					printf("----------------------------------")
					printf("\t\t\t请输入要添加的剧目演出计划信息:\n");
					printf("请输入剧目演出计划ID:");
					scanf("%d\n",&data.id);
					printf("请输入上映剧目ID:");
					scanf("%d",&data.play_id);
					printf("请输入剧目演出厅ID:");
					scanf("%d\n",&data.studio_id);
					printf("请输入剧目的放映日期:");
					scanf("%04d-%02d-%02d\n",&data.date.year,&data.date.month,&data.date.day);
					printf("请输入剧目放映时间:");
					scanf("%d:%d:%d\n",&data.time.hour,&data.time.minuete,&data.time.second)
					printf("请输入剧目演出厅座位数:");
					scanf("%d\n",&data.seat_count);
					printf("---------------------------------");
					paging.totalRecords=Schedule_Srv_FetchAll(list);
					List_Paging(list,paging,schedule_node_t);
					if(Schedule_Srv_Add(&data)==1)
					{
						printf("添加演出信息成功\n"); 
						getchar();
					}
					else
					{
						printf("添加演出计划信息失败\n");
					}
					break;
				}
				case 'u':
				case 'U':{
					printf("请输入演出计划ID:");
					scanf("%d",&id);
					fflush(stdin);
					if(Schedule_UI_Modify(id)==1)
					{
						printf("修改演出计划信息成功\n");
						if(Schedule_Srv_FetchByID(id,&buf)==1)
						{
							printf("获取新演出计划信息成功");
							printf("===================================\n");
							printf("演出计划ID      上映剧目ID        演出厅ID        放映日期       放映时间      座位数\n");
							a=buf.date.year;
							b=buf.date.month;
							c=buf.date.day;
							d=buf.time.hour;
							e=buf.time.minute;
							f=buf.time.second;
							printf("%d         %d         %d\t\t%d-%d-%d\t\t%d:%d:%d\t\t%d",buf.id,buf.play_id,buf.studio_id,a,b,c,d,e,f,buf.seat_count);
							paging.totalRecords=Schedule_Srv_FetchAll(list);
							List_Paging(list,paging,schedule_node_t);
						}
						else
						{
							printf("获取新演出信息失败"); 
						}
					}
					else
					{
						printf("修改失败\n"); 
					}
					break;
				}
				case 'p':
				case 'P':{
					if(!Paging_IsFirstPage(paging))
		    	   		Paging_Locate_OffsetPage(list,paging,-1,schedule_node_t);
					break;
				}	
				case 'N':
				case 'n':{
					if(!Paging_IsLastPage(paging))
				   		Paging_Locate_OffsetPage(list,paging,1,schedule_node_t);
					break;
				}
				case 'd':
				case 'D':{
					paging.totalRecords=Schedule_Srv_FetchAll(list);
					List_Paging(list,paging,schedule_node_t);
					printf("请输入演出计划ID:");
					scanf("%d",&id);
					fflush(stdin);
					if(Schedule_UI_Delete(id)==1)
					{
						printf("删除成功\n");
						getche();
					}
					else
					{
						puts("删除失败");
					}
					break;
				}
				default:break;	
					
			} 
			
			
		}while(choice!='r'||choice!='R'); 
		List_Destroy(list,schedule_node_t);	
	}
	else
	{
		printf("获取剧目信息失败\n");
		 
	}
} 
int Schedule_UI_Add(int play_id)
{
	schedule_t data;
	int newCount=0;
	char choice;
	data.play_id=play_id; 
	do
	{
		printf("----------------------------------")
		printf("\t\t\t请输入要添加的剧目演出计划信息:\n");
		printf("请输入剧目演出计划ID:");
		scanf("%d\n",&data.id);
		printf("请输入剧目演出厅ID:");
		scanf("%d\n",&data.studio_id);
		printf("请输入剧目的放映日期:");
		scanf("%04d-%02d-%02d\n",&data.date.year,&data.date.month,&data.date.day);
		printf("请输入剧目放映时间:");
		scanf("%d:%d:%d\n",&data.time.hour,&data.time.minuete,&data.time.second)
		printf("请输入剧目演出厅座位数:");
		scanf("%d\n",&data.seat_count);
		printf("---------------------------------");
		if(Sechedule_Srv_Add(&data)==1)
		{
			printf("添加剧目演出计划成功\n");
			newCount++; 
			printf("请输入是否继续继续增加剧目演出计划[A]dd more|[R]eturn:");
			choice=getchar();
		}
		else
		{
			printf("添加剧目演出计划失败\n"); 
			return 0;
		}
	}while(choice!='a'||choice!='A');
	
	return newCount;
	
}
int Schedule_UI_Modify(int id)
{
	int rtn=0;
	schedule_t buf;
	if(Schedule_Srv_FetchByID(id,&buf)==1)
	{
		printf("---------------------------");
		printf("请输入修改的信息\n");
		printf("请输入剧目演出计划ID:");
		scanf("%d\n",&buf.id);
		printf("请输入剧目演出计划ID:");
		scanf("%d",&buf.play_id);
		printf("请输入剧目演出厅ID:");
		scanf("%d\n",&buf.studio_id);
		printf("请输入剧目的放映日期:");
		scanf("%04d-%02d-%02d\n",&buf.date.year,&buf.date.month,&buf.date.day);
		printf("请输入剧目放映时间:");
		scanf("%d:%d:%d\n",&buf.time.hour,&buf.time.minuete,&buf.time.second)
		printf("请输入剧目演出厅座位数:");
		scanf("%d\n",&buf.seat_count);
		printf("--------------------------");
		if(Schedule_Srv_Modify(&buf)==1)
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
int Schedule_UI_Delete(int id)
{
	int rtn=0;
	if(Schedule_Srv_DeleteByID(id)==1)
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
