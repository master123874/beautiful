#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
     struct ListNode *p = L;
     while (p) {
           printf("%d ", p->data);
           p = p->next;
     }
     printf("\n");
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    scanf("%d", &m);
    L = deletem(L, m);
    printlist(L);

    return 0;
}

struct ListNode *readlist()
{
	int count=0;
	struct ListNode *phead=NULL;
	struct ListNode *pend,*pnew;
	pend=pnew=(struct ListNode *)malloc(sizeof(struct ListNode));
	scanf("%d",&pnew->data );
	while(pnew->data != -1)
	{
		count++;
		if ( count == 1 )
		{
			pnew->next=NULL;
			pend=pnew;
			phead=pnew;
		}
		else
		{
			pnew->next =NULL;
			pend->next =pnew;
			pend=pnew;
		}
		pnew=(struct ListNode *)malloc(sizeof(struct ListNode));
		scanf("%d",&pnew->data );
	}
	free(pnew);
	return phead;
}
struct ListNode *deletem( struct ListNode *L, int m )
{
	struct ListNode *ppre;
	struct ListNode *ptemp,*h=L;
	ptemp=h;
	ppre=h;
	while (ptemp)
	{
		if ( ptemp->data == m)
		{
			if ( ptemp == h )
			{
				free(h);
				h=ppre->next ;
				ptemp=h;
				ppre=ptemp;
			}
			else
			{
				ppre->next =ptemp->next ;
				free(ptemp);
				ptemp=ppre->next ;
			}
		}
		else
		{
			ppre=ptemp;
			ptemp=ptemp->next;
		}
	}
	return h;
}

