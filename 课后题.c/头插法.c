#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};
struct ListNode *createlist()
{
    struct ListNode *head=NULL;
    struct ListNode *p;
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    scanf("%d",&p->data);
    while(p->data!=-1)
    {
        p->next=head;
        head=p;
        p=(struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d",&p->data);
    }
    return head;
}


int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");

    return 0;
}

