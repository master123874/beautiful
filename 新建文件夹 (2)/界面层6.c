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
		printf("  �ݳ��ƻ�ID         ��ӳ��ĿID         �ݳ���ID          ��ӳ����         ��ӳʱ��       ��λ��\n");
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
		printf("----------------------�ܼ�¼:%2d--------------------------------Page %2d/%2d----\n",paging.totalRecords,Paging_Curpage(paging),Paging_TotalPages(paging));
		printf("******************************************************************************************\n");
		printf("[P]��һҳ|[N]��һҳ| [Q] ���ݾ�Ŀ���ƻ�ȡ�ݳ��ƻ� [r]����\n");
		
		printf("��������Ҫ�����ҵ��:");
		fflush(stdin);
		scanf("%c",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 'q':
			case 'Q':{
				printf("�������Ŀ����:");
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
	//�ͷ�����ռ� 
	List_Destroy(list,schedule_node_t);
} 
int Schedule_UI_Query(char *play_name)
{
	play_list_t list_p,temp1;
	schedule_list_t list_s,temp;
	List_Init(list_p,play_node_t);
	List_Init(list_s,schedule_node_t);
	int count=Play_Srv_FetchByName(list_p,playname);
	printf("һ����%d���йظþ�Ŀ���Ƶ���Ϣ:\n");
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
	printf("һ����%d���ݳ��ƻ���Ϣ",count1);
	printf("\t\t\t��Ŀ����     ʱ��     �ݳ������      �ݳ�����      ��ʼʱ��   ��λ��       Ʊ��\n"); 
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
