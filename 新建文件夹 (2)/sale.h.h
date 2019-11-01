#ifndef sale_h
#define sale_h
#include"ticket.h"
typedef enum{
	SALE_SELL=1,  //“— € 
	SALE_REFOUND=-1  // Œ¥ € 
}sale_type_t;
typedef struct{
	long id;
	int user_id;
	int ticket_id;
	ttms_date_t date;
	ttms_time_t time;
	int value;
	sale_type_t type;
}sale_t;

typedef struct sale_node{
	sale_t data;
	struct sale_node *next,*prev;
}sale_node_t,*sale_list_t;
void Sale_UI_MgtEntry();

void Sale_UI_ShowScheduler(int playID);

int Sale_UI_SellTicket(ticket_list_t tickList,seat_list_t seatList);

int Sale_Srv_Add(const sale_t *data);

int Ticket_Srv_Modify(const ticket_t *data);

int Ticket_Srv_FetchBySchID(int id,ticket_list_t list);

ticket_node_t *Ticket_Srv_FetchBySeatID(ticket_list_t list,int seat_id);

int Sale_Perst_Insert(const sale_t *data);

int Ticket_Perst_Update(const ticket_t *data);

int Ticket_Srv_SelBySchID(int id,ticket_list_t list);

void Sale_UI_RetfundTicket();


#endif


