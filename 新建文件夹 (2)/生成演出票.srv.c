#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"
#include"schedule.h"
int Schedule_Srv_FetchByID(int id,schedule_t *buf)
{
	return Schedule_Perst_SelectByID(id,buf);
}
int Ticket_Srv_GenBatch(int schedule_id)
{
	schedule_list_t seat_head;
	List_Init(seat_head,schedule_node_t);
	int count;
	count=Seat_Srv_FetchValidByRoomID(list,schedule_id);
	if(count<0)return 0;
	else
	{
		Ticket_Perst_Insert(list,scedule_id);
		return count;
	}	
}
int Ticket_Srv_DeleteBatch(int schedule_id)
{
	int found;
	found=Ticket_Perst_Rem(schedule_id);
	if(found<0)
	{
		printf("É¾³ý²Ù×÷Ê§°Ü");
		return found;
	}
	return found;
}

  
