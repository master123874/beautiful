#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput()
{
	int n;
	scanf("%d",&n);
	List t=(List)malloc(sizeof(struct LNode));
	t->Last=n;
	int i;
	for(i=1;i<=n;i++)scanf("%d",&t->Data[i]);
	return t;
}
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
Position BinarySearch( List L, ElementType X )
{
    int i;
    int t=L->Last;
    int low=1;
    int mid=(low+t)/2;
    while(low<=t)
    {
        if(L->Data[mid]==X)return mid;
        else if(X>L->Data[mid])
        {
            low=mid+1;
            mid=(low+t)/2;
        }
        else
        {
            t=mid-1;
            mid=(low+t)/2;
        }
    }
    return NotFound;
}
