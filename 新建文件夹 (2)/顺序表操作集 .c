#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};
List MakeEmpty()
{
	List t=(List)malloc(sizeof(struct LNode));
	t->Last=-1;
	return t;
}
Position Find( List L, ElementType X )
{
	int i;
	for(i=0;i<=L->Last;i++)
	  if(L->Data[i]==X)return i;
	return ERROR;  
}
bool Insert( List L, ElementType X, Position P )
{
	bool t=false;
	if(L->Last==MAXSIZE-1)
	{
		printf("FULL");
		return t;
	}
	if(P<0||P>L->Last+1)return t;
	int i;
	for(i=L->Last;i>=P;i--)L->Data[i+1]=L->Data[i];
	L->Data[P]=X;
	L->Last++;
	t=true;
	return t;
}
bool Delete( List L, Position P )
{
	bool t=false;
	if(P<0||P>L->Last)
	{
		printf("POSITION %d EMPTY",P);
		return t;
	}
	int i;
	for(i=P;i<L->Last;i++)L->Data[i]=L->Data[i+1];
	L->Last--;
	t=true;
	return t;
}
int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false)
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}
