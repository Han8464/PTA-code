#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
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

/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( List L, ElementType X )
{
	int a = 0;
	int b = L->Last;
	if(X < L->Data[0] || X > L->Data[b])
		return NotFound;
	while(a < b)
	{
		int mid = (a + b)/2;
		if(L->Data[mid] == X)
		{
			return mid;
		}else if(L->Data[mid] > X)
		{
			b = mid - 1;
		}else
		{
			a = mid;
		}
	}
	return NotFound;
}