#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"schedule.h"
static const int a=5;

void Schedule_UI_MgtEntry(int play_id)
{
	play_t buf;
	schedule_t buf1;
	int id;
	Pagination_t paging;
	schedule_list_t list;
	char choice;
	schedule_node_t *pos;
	int i;
	int a,b,c,d,e,f;
	schedule_t data;
	if(Schedule_Srv_FetchByID(play_id,&buf)==1)
	{
		List_Init(list,schedule_node_t);
		count=Schedule_Srv_FetchByPlay(list,play_id)
		paging.offset=0;
		paging.pageSize=a;
		paging.totalRecords=count;
		Paging_Locate_FirstPage(list,paging);
		do
		{
			printf("---------------------------------------------------\n");
			printf("-------------------------��ǰ�ݳ��ƻ���Ϣ---------------------\n");
			printf("******************************************************************\n");
			printf("�ݳ��ƻ�ID      ��ӳ��ĿID        �ݳ���ID        ��ӳ����       ��ӳʱ��      ��λ��\n");
			Paging_ViewPage_Foreach(list,paging,schedule_node_t,pos,i){
				a=pos->data.date.year;
				b=pos->data.date.month;
				c=pos->data.date.day;
				d=pos->data.time.hour;
				e=pos->data.time.minute;
				f=pos->data.time.second;
				printf("%d         %d         %d\t\t%d-%d-%d\t\t%d:%d:%d\t\t%d",pos->data.id,pos->data.play_id,pos->data.studio_id,a,b,c,d,e,f,pos->data.seat_count);
				
			}
			printf("----------------------�ܼ�¼:%2d--------------------------------Page %2d/%2d----\n",paging.totalRecords,Paging_Curpage(paging),Paging_TotalPages(paging));
			printf("******************************************************************************************\n");
			
			printf("[t]:��ѯ�ݳ��ƻ�,[a]:����ݳ��ƻ�,[u]:�޸��ݳ��ƻ�,[d]:ɾ���ݳ��ƻ�,[p]:������һҳ,");
			printf("[n]:��һҳ,[r]:����\n");
			printf("���������ѡ��:");
			scanf("%c",&choice);
			fflush(stdin);
			printf("\n");
			switch(choice)
			{
				case 't':
				case 'T':{
					
					printf("����������ݳ��ƻ�ID\n");
					scanf("%d",&id);
					if(Schedule_Srv_FetchByID(id,&buf1)==1)
					{
						printf("��ȡ�ݳ��ƻ��ɹ�"); 
						getchar();
						paging.totalRecords=Schedule_Srv_FetchAll(list);
						List_Paging(list,paging,schedule_node_t);
						Ticket_UI_MgtEntry(id);
					}
					else
					{
						printf("��ȡ�ݳ��ƻ�ʧ��\n");
					} 
					break;
				}
				case 'a':
				case 'A':{
					printf("----------------------------------")
					printf("\t\t\t������Ҫ��ӵľ�Ŀ�ݳ��ƻ���Ϣ:\n");
					printf("�������Ŀ�ݳ��ƻ�ID:");
					scanf("%d\n",&data.id);
					printf("��������ӳ��ĿID:");
					scanf("%d",&data.play_id);
					printf("�������Ŀ�ݳ���ID:");
					scanf("%d\n",&data.studio_id);
					printf("�������Ŀ�ķ�ӳ����:");
					scanf("%04d-%02d-%02d\n",&data.date.year,&data.date.month,&data.date.day);
					printf("�������Ŀ��ӳʱ��:");
					scanf("%d:%d:%d\n",&data.time.hour,&data.time.minuete,&data.time.second)
					printf("�������Ŀ�ݳ�����λ��:");
					scanf("%d\n",&data.seat_count);
					printf("---------------------------------");
					paging.totalRecords=Schedule_Srv_FetchAll(list);
					List_Paging(list,paging,schedule_node_t);
					if(Schedule_Srv_Add(&data)==1)
					{
						printf("����ݳ���Ϣ�ɹ�\n"); 
						getchar();
					}
					else
					{
						printf("����ݳ��ƻ���Ϣʧ��\n");
					}
					break;
				}
				case 'u':
				case 'U':{
					printf("�������ݳ��ƻ�ID:");
					scanf("%d",&id);
					fflush(stdin);
					if(Schedule_UI_Modify(id)==1)
					{
						printf("�޸��ݳ��ƻ���Ϣ�ɹ�\n");
						if(Schedule_Srv_FetchByID(id,&buf)==1)
						{
							printf("��ȡ���ݳ��ƻ���Ϣ�ɹ�");
							printf("===================================\n");
							printf("�ݳ��ƻ�ID      ��ӳ��ĿID        �ݳ���ID        ��ӳ����       ��ӳʱ��      ��λ��\n");
							a=buf.date.year;
							b=buf.date.month;
							c=buf.date.day;
							d=buf.time.hour;
							e=buf.time.minute;
							f=buf.time.second;
							printf("%d         %d         %d\t\t%d-%d-%d\t\t%d:%d:%d\t\t%d",buf.id,buf.play_id,buf.studio_id,a,b,c,d,e,f,buf.seat_count);
							paging.totalRecords=Schedule_Srv_FetchAll(list);
							List_Paging(list,paging,schedule_node_t);
						}
						else
						{
							printf("��ȡ���ݳ���Ϣʧ��"); 
						}
					}
					else
					{
						printf("�޸�ʧ��\n"); 
					}
					break;
				}
				case 'p':
				case 'P':{
					if(!Paging_IsFirstPage(paging))
		    	   		Paging_Locate_OffsetPage(list,paging,-1,schedule_node_t);
					break;
				}	
				case 'N':
				case 'n':{
					if(!Paging_IsLastPage(paging))
				   		Paging_Locate_OffsetPage(list,paging,1,schedule_node_t);
					break;
				}
				case 'd':
				case 'D':{
					paging.totalRecords=Schedule_Srv_FetchAll(list);
					List_Paging(list,paging,schedule_node_t);
					printf("�������ݳ��ƻ�ID:");
					scanf("%d",&id);
					fflush(stdin);
					if(Schedule_UI_Delete(id)==1)
					{
						printf("ɾ���ɹ�\n");
						getche();
					}
					else
					{
						puts("ɾ��ʧ��");
					}
					break;
				}
				default:break;	
					
			} 
			
			
		}while(choice!='r'||choice!='R'); 
		List_Destroy(list,schedule_node_t);	
	}
	else
	{
		printf("��ȡ��Ŀ��Ϣʧ��\n");
		 
	}
} 
int Schedule_UI_Add(int play_id)
{
	schedule_t data;
	int newCount=0;
	char choice;
	data.play_id=play_id; 
	do
	{
		printf("----------------------------------")
		printf("\t\t\t������Ҫ��ӵľ�Ŀ�ݳ��ƻ���Ϣ:\n");
		printf("�������Ŀ�ݳ��ƻ�ID:");
		scanf("%d\n",&data.id);
		printf("�������Ŀ�ݳ���ID:");
		scanf("%d\n",&data.studio_id);
		printf("�������Ŀ�ķ�ӳ����:");
		scanf("%04d-%02d-%02d\n",&data.date.year,&data.date.month,&data.date.day);
		printf("�������Ŀ��ӳʱ��:");
		scanf("%d:%d:%d\n",&data.time.hour,&data.time.minuete,&data.time.second)
		printf("�������Ŀ�ݳ�����λ��:");
		scanf("%d\n",&data.seat_count);
		printf("---------------------------------");
		if(Sechedule_Srv_Add(&data)==1)
		{
			printf("��Ӿ�Ŀ�ݳ��ƻ��ɹ�\n");
			newCount++; 
			printf("�������Ƿ�����������Ӿ�Ŀ�ݳ��ƻ�[A]dd more|[R]eturn:");
			choice=getchar();
		}
		else
		{
			printf("��Ӿ�Ŀ�ݳ��ƻ�ʧ��\n"); 
			return 0;
		}
	}while(choice!='a'||choice!='A');
	
	return newCount;
	
}
int Schedule_UI_Modify(int id)
{
	int rtn=0;
	schedule_t buf;
	if(Schedule_Srv_FetchByID(id,&buf)==1)
	{
		printf("---------------------------");
		printf("�������޸ĵ���Ϣ\n");
		printf("�������Ŀ�ݳ��ƻ�ID:");
		scanf("%d\n",&buf.id);
		printf("�������Ŀ�ݳ��ƻ�ID:");
		scanf("%d",&buf.play_id);
		printf("�������Ŀ�ݳ���ID:");
		scanf("%d\n",&buf.studio_id);
		printf("�������Ŀ�ķ�ӳ����:");
		scanf("%04d-%02d-%02d\n",&buf.date.year,&buf.date.month,&buf.date.day);
		printf("�������Ŀ��ӳʱ��:");
		scanf("%d:%d:%d\n",&buf.time.hour,&buf.time.minuete,&buf.time.second)
		printf("�������Ŀ�ݳ�����λ��:");
		scanf("%d\n",&buf.seat_count);
		printf("--------------------------");
		if(Schedule_Srv_Modify(&buf)==1)
		{
			printf("�޸���Ϣ�ɹ�\n");
			rtn=1;
		}
		else
		{
			printf("�޸���Ϣʧ��\n");
			return 0;
		}
		 
	}
	else
	{
		printf("��ȡ�ݳ��ƻ�ʧ��\n");
		return 0;
	}
	return rtn;
}
int Schedule_UI_Delete(int id)
{
	int rtn=0;
	if(Schedule_Srv_DeleteByID(id)==1)
	{
		rtn=1;
		printf("ɾ����Ŀ�ݳ��ƻ��ɹ�\n");
		return rtn;
	}
	else
	{
		printf("ɾ����Ŀ�ݳ��ƻ�ʧ��\n");
		return 0;
	}
}
