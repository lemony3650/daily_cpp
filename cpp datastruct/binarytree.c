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
	printf("\r\n����ڵ���ֵ((������Ϊ100ʱ����ǰ�ڵ㴴�����))):");
	scanf("%d",&a);

    if (a == 100)
        *root = NULL;
    else{
        *root = (Tnode *)malloc(sizeof(Tnode));
        if (*root == NULL)
            return ;

        (*root)->data = a;
        printf("\r\n create node %d ������:",a);
		binarytree_create(&((*root)->lchild));
		printf("\r\n create node %d ���Һ���:",a);
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
 * �������
 * ����
 * ����
 * �㼶����
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
 * �㼶����
 * 1.���������У�ͨ���������ʵ�ֱ���
 * 2.ÿ�δӶ��г�һ���ڵ㣬ͬʱ�����ӽڵ������Ӳ���
 * 3.���γ����ҽڵ���ʵ�ֲ㼶����
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
 * ��ӡҶ�ӽڵ�
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
 * ����Ҷ�ӽڵ����
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
 * �������ĸ߶�
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
	printf("\r\n�������������:");
	binarytree_inorder(root);
	printf("\r\n�������������:");
	binarytree_postorder(root);
	printf("\r\n��α���������:");
	binarytree_levelorder(root);

	printf("\r\n��ӡ������Ҷ�ӽڵ�:");
	binarytree_printfleaf(root);
	printf("\r\n��ӡ������Ҷ�ӽڵ����:%d",binarytree_getleafnum(root));
	printf("\r\n��ӡ�������߶�:%d",binarytree_gethigh(root));

	binarytree_destory(root);

	return 0;
}

