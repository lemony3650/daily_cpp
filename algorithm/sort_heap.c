#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


/*********************************************************
 * 堆排序 
 * 原地 | 时间复杂度O(nlogn)   趋于n时间复杂度更稳定
 * 插入操作 从下往上堆化
 * 删除操作 删除堆顶，与堆的最后一个元素替换
 * 排序操作 逐个替换掉堆顶元素，自上向下堆化
 * 1.堆排访问数组是跳跃性的，CPU缓存不友好
 * 2.堆排序交换次数较多
*********************************************************/

/********************************************************
 * 堆排序应用场景
 * 1.优先级队列，高优先级先出，堆顶元素实现
 * 2.求TOP k元素的值，动态维护一个K的顶堆
 * 3.求中位数，维护对等的两个堆
*********************************************************/




/************************************************
 * 建堆 
 * 1.自上向下插入元素
 * 2.自下向上堆化   
 * 排序
 * 1.基于堆顶为最大或最小元素
 * 2.与末端元素替换，重新自上而下堆化
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
 * 交换
 * 显示堆数据
 * 打印堆
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
 * 1.指针初始化
 * 2.添加数据
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
 * 建堆的过程
 * 递归，从倒数第二层开始建数据 length/2
 * 1.左子树和根比较
 * 2.右子树和根比较
 * 3.保证根最大，从而保证上层的每个根都为最最大
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
 * 堆排序
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

