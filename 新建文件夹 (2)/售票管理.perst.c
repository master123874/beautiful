#include<stdio.h>
#include<stdlib.h>
#include"sale.h"
#include"ticket.h"
int Sale_Perst_Insert(const sale_t *data)
{
	FILE fp;
	fp=fopen("Sale.dat","rb");
	if(!feof(fp))
	{
		printf("%s文件打开失败");
		return 0; 
	}
	int rtn;
	rtn=fwrite(data,sizeof(sale_t),1,fp);
	fclose(fp);
	return rtn;
}
int Ticket_Perst_Update(const ticket_t *data)
{
	FILE fp;
	ticket_t rec;
	fp=fopen("Ticket.data","rb+");
	if(!fp)
	{
		printf("%s文件打开失败");
		return 0;
	}
	int rtn;
	int i;
	while(!feof(fp))
	{
		fread(&rec,sizeof(ticket_t),1,fp);
		i=ftell(fp);
		if(rec.id==data->id)
		{
			fseek(fp,i,SEEK_CUR);
			rtn=fwrite(data,sizeof(ticket_t),1,fp);
			break;
		}
	}
	fclose(fp);
	return rtn;
}
int Ticket_Srv_SelBySchID(int id,ticket_list_t list)
{
	list=NULL;
	FILE fp;
	int count=0;
	fp=fopen("Ticket.dat","rb");
	if(!fp)
	{
		printf("%s文件打开失败");
		return 0; 
	}
	ticket_list_t newNode;
	ticket_t data;
	while(!feof(fp))
	{
		fread(&data,sizeof(ticket_t),1,fp);
		if(data.id==id)
		{
			
			newNode=(ticket_list_t)malloc(sizeof(tick_node_t));
			newNode->data=data;
			newNode->next=list;
			newNode->prev=list->prev;
			list->prev->next=newNode;
			list->prev=newNode;
			count=1;
		}
	}
	fclose(fp);
	
	return count;
}
