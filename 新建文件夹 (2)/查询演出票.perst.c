#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"

int Ticket_Perst_SelByID(int id,ticket_t *buf)
{
	FILE fp;
	int found=0;
	ticket_t data;
	fp=fopen("Ticket.dat","rb+");
	if(!fp)
	{
		printf("%s文件打开失败");
		return 0; 
	}
	while(!feof(fp))
	{
		fread(&data,sizeof(ticket_t),1,fp);
		if(data.id==id)
		{
			found=1;
			buf=&data;
		}
	}
	fclose(fp);
	return found;
} 

