#include"List.h"
#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"

void Ticket_UI_Query()
{
	ticket_list_t list;
	List_Init(list,ticket_node_t);
	char choice;
	int count=Ticket_Srv_FetchAll(list);
	printf("\t\t\tc/C:显示演出票,s/S:演出票信息");
	scanf("%c",&choice);
	fflush(stdin);
	int count;
	ticket_t buf;
	int id;
	switch(choice)
	{
		case 'c':
		case 'C':{
			Ticket_UI_Query();
			break;
		}
		case 's':
		case 'S':{
			printf("请输入票的ID:");
			scanf("%d",&id);
			fflush(stdin);
			if(Ticket_UI_SelectByID(id,&buf)==1)
			{
				printf("-----------------------------------------\n");
				printf("票的演出计划ID        票的座位ID      票价        票的状态");
				printf("%d         %d            %d          %d",buf.schedule_id,buf.seat_id,buf.price,buf.status); 
			}
			else
			{
				printf("查询失败\n"); 
			} 
			break;
		}	
	}
	List_Destroy(list,ticket_node_t);
	return;
}
int Ticket_UI_ShowTicket(int ticket_id)
{
	int rtn=0;
	ticket_t buf;
	if(Ticket_Srv_Query(ticket_id,&buf)==1)
	{
		rtn=1;
		printf("演出票存在\n");
		
		return rtn;
	}
	else
	{
		printf("演出票不存在\n");
		return rtn;
	}
}
