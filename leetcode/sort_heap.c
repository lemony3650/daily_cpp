#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


/*********************************************************
 * ������ 
 * ԭ�� | ʱ�临�Ӷ�O(nlogn)   ����nʱ�临�Ӷȸ��ȶ�
 * ������� �������϶ѻ�
 * ɾ������ ɾ���Ѷ�����ѵ����һ��Ԫ���滻
 * ������� ����滻���Ѷ�Ԫ�أ��������¶ѻ�
 * 1.���ŷ�����������Ծ�Եģ�CPU���治�Ѻ�
 * 2.�����򽻻������϶�
*********************************************************/

/********************************************************
 * ������Ӧ�ó���
 * 1.���ȼ����У������ȼ��ȳ����Ѷ�Ԫ��ʵ��
 * 2.��TOP kԪ�ص�ֵ����̬ά��һ��K�Ķ���
 * 3.����λ����ά���Եȵ�������
*********************************************************/




/************************************************
 * ���� 
 * 1.�������²���Ԫ��
 * 2.�������϶ѻ�   
 * ����
 * 1.���ڶѶ�Ϊ������СԪ��
 * 2.��ĩ��Ԫ���滻���������϶��¶ѻ�
************************************************/
#define MAX_HEAP_SIZE (1 << 8)

struct element {
    int data;
};

struct heap {
    union 
    {
        unsigned long elements;
        struct element *elem[MAX_HEAP_SIZE];
    };    
};

/*****************************************************************
 * ����
 * ��ʾ������
 * ��ӡ��
******************************************************************/
void dump(struct heap *heap, int elements)
{
	for (int i = 1; i <= elements; i++)
		printf("%4d", heap->elem[i]->data);

	printf("\n");
}

void swap(struct heap *heap, int i, int j)
{
	struct element *tmp;

	tmp = heap->elem[j];
	heap->elem[j] = heap->elem[i];
	heap->elem[i] = tmp;
}
/*
void dump_heap(struct heap *heap, int index)
{
    struct element *elem;
    int level;

    if (index > heap->elements)
        return;

    elem = heap->elem[index];
    level = fls(index);

    dump_heap(heap,index * 2 + 1);

    if (!(index % 2) && index != 1)
		printf("%*s\n", level*3, "|");

	printf("%*s - %05d\n", level*3, " ", elem->data);

	if (index % 2 && index != 1)
		printf("%*s\n", level*3, "|");

	dump_heap(heap, index * 2);        

}
*/


/***********************************************************
 * init_heap
 * 1.ָ���ʼ��
 * 2.�������
***********************************************************/
struct element* create_element(int data)
{
	struct element *elem;
	elem = (struct element *)malloc(sizeof(struct element));

	if (elem)
		elem->data = data;

	return elem;
}

void init_heap(struct heap *heap, int *arr, int length)
{
	int i;

    for (i = 0; i < MAX_HEAP_SIZE; i++)
        heap->elem[i] = NULL;

    for (i = 0; i < length; i++)
		heap->elem[i+1] = create_element(arr[i]);

	heap->elements = length;
}
/*************************************************************
 * ���ѵĹ���
 * �ݹ飬�ӵ����ڶ��㿪ʼ������ length/2
 * 1.�������͸��Ƚ�
 * 2.�������͸��Ƚ�
 * 3.��֤����󣬴Ӷ���֤�ϲ��ÿ������Ϊ�����
*************************************************************/
void heapify(struct heap *heap, int parent)
{
	struct element **elem = heap->elem;
	int elements = heap->elements;
	int left, right, max;

	while (true) {
		left = parent * 2;
		right = left + 1;
		
		max = parent;
		if (left <= elements && elem[max]->data < elem[left]->data)
			max = left;
		if (right <= elements && elem[max]->data < elem[right]->data)
			max = right;

		if (max == parent)
			break;

		swap(heap, max, parent);
		parent = max;
	}
}

void build_heap(struct heap *heap)
{
	for (int i = heap->elements / 2; i >= 1; i--)
		heapify(heap, i);
}

/*************************************************
 * ������
 * 
**************************************************/
void heap_sort(struct heap *heap)
{
	int elements = heap->elements;

	while (heap->elements) {
		swap(heap, 1, heap->elements);
		heap->elements--;
		heapify(heap, 1);
	}
}


int main()
{
	struct heap heap;

    int arr[] = {3,9,8,2,5,4,6,7};
	int len = sizeof(arr)/sizeof(arr[0]);

	init_heap(&heap, arr, len);
	build_heap(&heap);
	heap_sort(&heap);
	dump(&heap, len);

	return 0;
}

