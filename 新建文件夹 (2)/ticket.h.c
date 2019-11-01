#ifndef tichet_t
#define ticket_t

typedef enum
{
	TICKET_AVL,
	TICKET_SOLD,
	TICKET_RESV
}ticket_status_t;
typedef struct{
	int id;
	int schedule_id;
	int seat_id;
	int price;
	ticket_status_t status;
}ticket_t;

typedef struct ticket_node
{
	ticket_t data;
	struct ticket_node *next,*prev;
}ticket_node_t,*ticket_list_t;

void Ticket_UI_MgeEntry(int schedule_id);

int Schedule_Srv_FetchByID(int id,schedule_t *buf);

int Ticket_Srv_GenBatch(int schedule_id);

int Ticket_Srv_DeleteBatch(int schedule_id);

int Seat_Srv_FetchValidByRoomID(list,schedule_id);

int Schedule_Perst_SelectByID(int id,schedule_t *buf);

void Ticket_Perst_Insert(ticket_list_t list);
int Seat_Srv_FetchValidByRoomID(list,schedule_id);
int Ticket_Perst_Rem(int schedule_id);

#endif
