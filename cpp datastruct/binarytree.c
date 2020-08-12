#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "./list_queue.h"

typedef struct _treenode {
    int data;
    struct _treenode *lchild;
    struct _treenode *rchild;
}Tnode,Tree;

void binarytree_create(Tree **root)
{
    int a = 0;
	printf("\r\n输入节点数值((当输入为100时，当前节点创建完成))):");
	scanf("%d",&a);

    if (a == 100)
        *root = NULL;
    else{
        *root = (Tnode *)malloc(sizeof(Tnode));
        if (*root == NULL)
            return ;

        (*root)->data = a;
        printf("\r\n create node %d 的左孩子:",a);
		binarytree_create(&((*root)->lchild));
		printf("\r\n create node %d 的右孩子:",a);
		binarytree_create(&((*root)->rchild));
    }

    return ;
}

void binarytree_destory(Tree *root)
{
    if (root == NULL)
        return;

    binarytree_destory(root->lchild);
    binarytree_destory(root->rchild);
    free(root);
}

/****************************************
 * 先序遍历
 * 中序
 * 后序
 * 层级遍历
****************************************/
void binarytree_preorder(Tree *root)
{
    if (root == NULL)
        return ;

    printf("%d",root->data);
    binarytree_preorder(root->lchild);
    binarytree_preorder(root->rchild);

    return;
}
void binarytree_inorder(Tree *root)
{
    if (root == NULL)
        return ;

    binarytree_preorder(root->lchild);
    printf("%d",root->data);
    binarytree_preorder(root->rchild);    

    return ;
}
void binarytree_postorder(Tree *root)
{
    if (root == NULL)
        return ;

    binarytree_preorder(root->lchild);
    binarytree_preorder(root->rchild);   
    printf("%d",root->data); 

    return ;    
}

/**************************************************
 * 层级遍历
 * 1.创建链队列，通过出入队列实现遍历
 * 2.每次从队列出一个节点，同时将其子节点进行入队操作
 * 3.依次出左右节点来实现层级遍历
****************************************************/
void binarytree_levelorder(Tree *root)
{
    list_queue *queue = NULL;
    Tnode *node = NULL;

    if (root == NULL)
        return ;

    queue = list_queue_create();
    list_queue_enqueue(queue, (void *)root);
    
    while (!list_queue_is_empty(queue)) {
        list_queue_dequeue(queue, (void *)&node);
        printf("%d", node->data);

        if(node->lchild != NULL)
			list_queue_enqueue(queue,(void *)node->lchild);

		if(node->rchild != NULL)
			list_queue_enqueue(queue,(void *)node->rchild);
    }

    free(queue);
}

/***********************************************************
 * 打印叶子节点
 * 
***********************************************************/
void binarytree_printfleaf(Tree *root)
{
    if (root == NULL)
        return ;

    if ((root->lchild == NULL) && (root->rchild == NULL))
        printf("%d", root->data);
    else {
        binarytree_printfleaf(root->lchild);
        binarytree_printfleaf(root->rchild);
    }
}
/*****************************************************
 * 计算叶子节点个数
 * 
******************************************************/
int binarytree_getleafnum(Tree *root)
{
    if (root == NULL)
        return ;

    if ((root->lchild == NULL) && (root->rchild == NULL))
        return 1;   

    return binarytree_getleafnum(root->lchild) + binarytree_getleafnum(root->rchild);
}

/************************************************
 * 计算树的高度
 * 
************************************************/
int binarytree_gethigh(Tree *root)
{
    int lhigh = 0;
    int rhigh = 0;

    if (root == NULL)
        return 0;

    lhigh = binarytree_gethigh(root->lchild);
    rhigh = binarytree_gethigh(root->rchild);

    return ((lhigh > rhigh)? (lhigh + 1):(rhigh + 1));
}

int main()
{
    Tree *root = NULL;

    printf("\r\ncreate binarytree...");
    binarytree_create(&root);
	printf("\r\n中序遍历二叉树:");
	binarytree_inorder(root);
	printf("\r\n后序遍历二叉树:");
	binarytree_postorder(root);
	printf("\r\n层次遍历二叉树:");
	binarytree_levelorder(root);

	printf("\r\n打印二叉树叶子节点:");
	binarytree_printfleaf(root);
	printf("\r\n打印二叉树叶子节点个数:%d",binarytree_getleafnum(root));
	printf("\r\n打印二叉树高度:%d",binarytree_gethigh(root));

	binarytree_destory(root);

	return 0;
}

