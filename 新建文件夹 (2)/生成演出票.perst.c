#include<stdio.h>
#include<stdlib.h>
#include"ticket.h"
#include"List.h"
#include"schedule.h"
int Schedule_Perst_SelectByID(int id,schedule_t *buf)
{
	FILE fp;
	int found=0;
	schedule_t data;
	fp=fopen("Schedule.dat","rb");
	if(!fp)
	{
		printf("%s打开失败","Scnedule_dat");
		return 0;
	}
	while(!feof(fp))
	{
		fread(&data,sizeof(schedule_t),1,fp);
		if(data.id==id)
		{
			buf=&data;
			found=1;
			break;
		}
	}
	fclose(fp);
	return found;
}
int Ticket_Perst_Insert(ticket_list_t list)
{
	FILE fp;
	fp=fopen("Ticket.dat","ab+");
	if(!fp)
	{
		printf("%s打开失败","Ticket.dat");
		return 0;
	}
	int count=0;
	int cnt;
	ticket_t data;
	schedule_t sch;
	
	if(Schedule_Perst_SelectByID(schedule_id,&sch))
	{
		printf("载入信息成功"); 
	}
	else
	{
		printf("载入信息失败"); 
		getchar();
		return -1;
	}
	if(Play_Perst_SelectByID(sch.play_id))
	{
		printf("载入信息成功");
	}
	else
	{
		printf("载入信息失败");
		getche();
		return -1;
		 
	}
	ticket_list_t pos=list->next;
	while(pos!=list)
	{
		
		data=pos->data;
		data.id=EntKey_Perst_GetNewKeys("Ticket.dat",1);
		
		cnt=fwrite(&data,sizeof(ticket_t),1,fp);
		pos=pos->next;
	}
	fclose(fp);
	return cnt;
	
} 
int Ticket_Perst_Rem(int schedule_id)
{
	FILE fp;
	if(rename("Ticket.dat","TicketTmp.dat")<0)printf("文件名修改失败"); 
	fp=fopen("TicketTmp.dat","rb");
	if(!fp)
	{
		printf("%s文件打开失败","TicketTmp.dat");
		return 0;
	}
	FILE fp1;
	int found=0;
	ticket_t buf;
	fp1=fopen("Ticket.dat","wt");
	while(!feof(fp))
	{
		fread(&buf,sizeof(ticket_t),1,fp);
		if(buf.id==schedule_id)
		{
			found++;
		}
		else fwrite(&buf,sizeof(ticket_t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("TicketTmp.dat");
	return found;
}

