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
	printf("\t\t\tc/C:��ʾ�ݳ�Ʊ,s/S:�ݳ�Ʊ��Ϣ");
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
			printf("������Ʊ��ID:");
			scanf("%d",&id);
			fflush(stdin);
			if(Ticket_UI_SelectByID(id,&buf)==1)
			{
				printf("-----------------------------------------\n");
				printf("Ʊ���ݳ��ƻ�ID        Ʊ����λID      Ʊ��        Ʊ��״̬");
				printf("%d         %d            %d          %d",buf.schedule_id,buf.seat_id,buf.price,buf.status); 
			}
			else
			{
				printf("��ѯʧ��\n"); 
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
		printf("�ݳ�Ʊ����\n");
		
		return rtn;
	}
	else
	{
		printf("�ݳ�Ʊ������\n");
		return rtn;
	}
}
