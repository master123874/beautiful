#include<stdio.h>
#include"List.h"
#include<stdlib.h>
#include"sale.h"

int Sale_Srv_Add(const sale_t *data)
{
	return Sale_Perst_Insert(data);
}

int Ticket_Srv_Modify(const ticket_t *data)
{
	return Ticket_Perst_Update(data);
}

int Ticket_Srv_FetchBySchID(int ID,ticket_list_t list)
{
	return Ticket_Srv_SelBySchID(ID,list);
}
ticket_node_t *Ticket_Srv_FetchBySeatID(ticket_list_t list,int seat_id)
{
    ticket_list_t temp=list->next;
    while(temp!=list)
    {
    	if(temp->data.id==seat_id)return temp;
	}
	return NULL;
}

