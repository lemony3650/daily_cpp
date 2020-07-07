#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_queue.h"

// 链队列队头创建
list_queue *list_queue_create()
{
    list_queue *queue = NULL;

    queue = (list_queue *)malloc(sizeof(list_queue));
    if (queue == NULL)
        return NULL;

    queue->num = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

int list_queue_enqueue(list_queue *queue, void *data)
{
    queue_node *ptmp = NULL;

    if (queue == NULL)
        return -1;

    ptmp = (queue_node *)malloc(sizeof(queue_node));
    if (ptmp == NULL)
        return -1;

    ptmp->data = data;
    ptmp->next = NULL;

    if (queue->head == NULL)
        queue->head = ptmp;
    else 
        queue->tail->next = ptmp;
    
    queue->tail = ptmp;
    queue->num++;

    return 0;
}

int list_queue_dequeue(list_queue *queue, void **data)
{
    queue_node *ptmp = NULL;

    if ((queue == NULL) || (data == NULL) || (list_queue_is_empty(queue)))
        return -1;

    *data = queue->head->data;
    ptmp = queue->head;
    queue->head = queue->head->next;
    queue->num--;

    if (queue->head == NULL)
        queue->tail = NULL;

    free(ptmp);
    return 0;
}