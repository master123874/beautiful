#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"
int Ticket_Srv_FetchByID(int id,ticket_t *buf)
{
	if(Ticket_Perst_SelectByID(id,buf)==1)
	{
		return 1;
	}
	else
	{
		printf("��Ϣ��ѯʧ��");
		return 0; 
	}
}

