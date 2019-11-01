#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"List.h"
#include"schedule.h"
static const int a=5;
void Schedule_UI_ListAll()
{
	schedule_list_t list;
	char choice;
	char name[31];
	int i;
	List_Init(list,schedule_node_t);
	Pagination_t paging;
	schedule_node_t *pos;
	paging.pageSize=a;
	paging.offset=0;
	int count=Schedule_Srv_FetchAll(list);
	paging.totalRecords=Schedule_Srv_FetchAll(list);
	int a,b,c,d,e,f;
	Paging_Locate_FirstPage(list,paging);
	do
	{
		printf("\n==========================================================\n");
		printf("  演出计划ID         上映剧目ID         演出厅ID          放映日期         放映时间       座位数\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		Paging_ViewPage_Foreach(list,paging,schedule_node_t,pos,i){
			a=pos->data.date.year;
			b=pos->data.date.month;
			c=pos->data.date.day;
			d=pos->data.time.hour;
			e=pos->data.time.minute;
			f=pos->data.time.second;
			printf("%d\t\t%d\t\t%d\t\t%04d-%04d-%04d\t\t%02d:%02d:%02d\t\t%d \n",pos->data.id,pos->data.play_id,pos->data.studio_id,a,b,c,d,e,f,pos->data.seat_count);
		}
		printf("----------------------总记录:%2d--------------------------------Page %2d/%2d----\n",paging.totalRecords,Paging_Curpage(paging),Paging_TotalPages(paging));
		printf("******************************************************************************************\n");
		printf("[P]上一页|[N]下一页| [Q] 根据剧目名称获取演出计划 [r]返回\n");
		
		printf("请输入你要办理的业务:");
		fflush(stdin);
		scanf("%c",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 'q':
			case 'Q':{
				printf("请输入剧目名称:");
				scanf("%s",name);
				fflush(stdin);
				if(Schedule_UI_Query(name))
				{
					paging.totalRecords=Schedule_Srv_FetchAll(list);
					List_Paging(list,paging,schedule_node_t);
				}
				break;
			}	
			case 'p':
		    case 'P':{
		    	if(!Paging_IsFirstPage(paging))
		    	   Paging_Locate_OffsetPage(list,paging,-1,schedule_node_t);
				break;
			}
			case 'n':
			case 'N':{
				if(!Paging_IsLastPage(paging))
				   Paging_Locate_OffsetPage(list,paging,1,schedule_node_t);
				break;
			}	
		} 
	}while(choice!='r'||choice!='R');
	//释放链表空间 
	List_Destroy(list,schedule_node_t);
} 
int Schedule_UI_Query(char *play_name)
{
	play_list_t list_p,temp1;
	schedule_list_t list_s,temp;
	List_Init(list_p,play_node_t);
	List_Init(list_s,schedule_node_t);
	int count=Play_Srv_FetchByName(list_p,playname);
	printf("一共有%d个有关该剧目名称的信息:\n");
	temp1=list_p->next;
	int count1=0;
	while(temp1!=list_p)
	{
		count1+=Schedule_Srv_FetchByPlay(list_s,temp1->data.id);
		temp1=temp1->next; 
	}
	temp1=list_p->next; 
	temp=list_s->next;
	int a,b,c,d,e,f;
	printf("一共有%d个演出计划信息",count1);
	printf("\t\t\t剧目名称     时长     演出厅编号      演出日期      开始时间   座位数       票价\n"); 
	printf("---------------------------------------------------------------------------------------");
	while(temp!=list)
	{
		a=temp->data.date.year;
		b=temp->data.date.month;
		c=temp->data.date.day;
		d=temp->data.time.hour;
		e=temp->data.time.minute;
		f=temp->data.time.second;
		printf("\t\t\t%s       %d       %d      %d-%d-%d         %d:%d:%d         %d      %d",temp1->data.name,temp1->data.duration,temp->data.studio_id,a,b,c,d,e,f,temp->data.seat_count,temp1->data.price);
		temp=temp->next;
		temp1=list->next; 
	}
	printf("---------------------------------------------------------------------------------------");
	return count1;
}
