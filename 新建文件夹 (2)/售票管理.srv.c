#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"sale.h"
void Sale_Srv_Add(const sale_t *data)
{
	Sale_Perst_Insert(data);
}
int Ticket_Srv_Modify(const ticket_t *data)
{
	int rtn;
	rtn=Ticket_Perst_Update(data);
	if(rtn==1)return rtn;
	return 0;
}
int Ticket_Srv_FetchBySchID(int ID,ticket_list_t list)
{
	return Ticket_perst_SelBySchID(ID,list);
}
ticket_node_t* Ticket_Srv_FetchBySeatID(ticket_list_t list,int seat_id)
{
	ticket_list_t temp=list;
	temp=list->next;
	while(temp!=list)
	{
		if(temp->id==ID)return temp;
		temp=temp->next;
	}
    return NULL;
} 
