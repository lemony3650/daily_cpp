#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/********************************************************
 * ʱ�临�ӶȽϸߣ��ʺ�С��ģ������
 *          �ռ�      ʱ��              �ȶ�      ԭ������
 * ð��      O(1)     O(n*(n-1)/2)      1           1
 * ����      O(1)     O(n^2)            1           1
 * ѡ��      O(1)     O(n^2)            0           1
---------------------------------------------------
 * ��á����ƽ��ʱ�临�Ӷ� | �ռ临�Ӷ� | �ȶ���
 * ͬ��ʱ�ĵͽ�ϵ��
 * �ȽϺͽ�������
----------------------------------------------------
 * ���������ð�ݶ���n2��Ϊʲô�����ò������򣿣�
   ð�ݵĽ���ʵ�֣�3�У�Ҫ�Ȳ��루1����λ����������
 * ������������ʵ�֣�ð������ıȽϴ���һ�£�����������
 *                ����������ıȽϴ���һ�£�����Ҫ����
 *                ��ѡ������ıȽϴ���һ�£�����Ҳ����
*********************************************************/


/***************************************************
 * ð������
 * �����Ƚ��Ƿ������С��ϵ������Ȧ���Ǵ���
 * һ��ð�ݳ�һ������λ�ã���Ȧÿ�ζ���0��ʼ����ð��
 * ��� O(1)  ���O(n^2)  ƽ��O(n*(n-1)/2)
 * 1.������Ȧ����Ȧ��ѭ���壬��Ȧlen-i-1
 * 2.��Ȧ��һ�Ƚϣ�ȷ��ĩ��λ��
 * 3.���ñ�־λ���Լ���Ƿ��Ѿ��ź���
****************************************************/
void bubbleSort(int *arr, int length)
{
    int tmp;
    bool flag;

    if(length <= 1)  return;

    for (int i = 0; i < length; i++) {
        flag = false;
        for (int j = 0; j < length-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = true;
            }
        }
        if (!flag)  break;
    }
}

/************************************************************
 * ��������
 * ����������������䣬Ĭ������Ϊ��һ��Ԫ�أ�������������ȡԪ�ز�������
 * 1.ȡ��Ҫ��������ݣ������ǰ����бȽϣ��Ӻ���ǰ�Ƚϣ���λ����
 * 2.��ǰ������ݴ���ȡ�����ģ������λ
 * 3.����ȡ��������
 * ���O(n) �O(n^2) ƽ��O(n^2)
*************************************************************/
void insertSort(int *arr, int length)
{
    if(length <= 1)  return;

    for (int i = 1; i < length; i++) {
        int tmp = arr[i];
        int j = i-1;

        for (; j >= 0; j--) {
            if (arr[j] > tmp)
                arr[j+1] = arr[j];      //��λ
            else 
                break;                   
        }   

        arr[j+1] = tmp;         //�ҵ�����λ��
    }
}

/********************************************************
 * ѡ������
 * ��Ϊ����������������䣬ÿ�δ���������������С�����±�
 * 1.Ĭ�ϵ�ǰλ��Ϊ������δӺ�Ѱ�ұȵ�ǰֵ����±�
 * 2.�滻�Ѽ�¼������±�
 * 3.��������ֵ���н���
 * ���ӶȾ�ΪO(n^2)
**********************************************************/
void selectSort(int *arr, int length)
{
    if(length <= 1)  return;

    for(int i = 0; i < length; i++) {
        int min = i;
        for (int j = i+1; j < length; j++) {
            if(arr[j] < arr[min])
                min = j;
        }
        if (min != i) {
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}


/*****************************************************************
 * �ʺϴ��ģ���������� O(nlogn)
 *              �ռ�        ʱ��            �ȶ�      ԭ������
 * �鲢�㷨      O(n)       O(nlogn)          1         0
 * ��������      O(1)       O(nlogn)          0         1
 * 
 * �鲢�㷨���¶��ϵ����ν��кϲ������������������ݣ���Ҫ���ٿռ�
 * �������Ǵ����������ν��У���Ч��ܿռ俪�٣����ǲ��ȶ�
******************************************************************/

/*****************************************************************************
 * �鲢�㷨
 * ʱ�临�Ӷ�O(nlogn) ��ԭ�����Ƿ������޹�
 * 1.���÷��ε�˼�룬������һ��Ϊ�������õݹ鷽ʽ������
 * 2.ÿ�η�Ϊǰ�������������ݣ�������ʱ�ռ�ͨ���Ƚϴ�С����һ�ϲ�������������
 * 3.ÿ�ν��кϲ���������ϵĹ���
*****************************************************************************/
// �ϲ�
void __merge(int *arr, int p, int q, int r)
{
    int *tmp;
    int i,j,k;

    // ������ʱ�ռ�
    tmp = (int *)malloc((r-p+1)*sizeof(int));
    if (!tmp)  
        abort();

    // �ϲ��������鵽һ��tmp
    for (i = p, j = q + 1, k = 0; i <= q && j <= r;) {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
            tmp[k++] = arr[j++];
    }

    if (i == q + 1) {
        for (; j <= r;)
            tmp[k++] = arr[j++];
    }else {
        for (; i <= q;)
            tmp[k++] = arr[i++];       
    }

	memcpy(arr+p, tmp, (r-p+1)*sizeof(int));
	free(tmp);
}

//�ݹ�ķ���ʵ��  p-��ʼ r-��ֹ q-�м仮��
void __merge_sort(int *arr, int p, int r) 
{
    int q;
    if (p >= r)  return;

    q = (p + r) / 2;
   	__merge_sort(arr, p, q);
	__merge_sort(arr, q + 1, r);

	__merge(arr, p, q, r);
}

// ������
void mergeSort(int *arr, int size)
{
    __merge_sort(arr, 0, size-1);
}

/********************************************************
 * ��������
 * ���÷��ε�˼�룬һ��ͨ����ĩβֵ���бȽϻ���������
 * ���õݹ�ı��˼����еݹ������ִ��������������
 * 1.p qָ����ʼλ�ã�rΪ�ֽ���
 * 2.��������q����ǰ�ߣ�p����q���ߣ������ִ��ڷֽ���r����p�Ͳ�����
 * 3.�ȴ���һ��С�ڳ���ʱ�����滻����
 * 4.ֱ�����r�ͷֽ���н�������,ͨ������ֵ��Ƿֽ�
***************************************************************/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// ��ĩβԪ��Ϊ��λ�����л���
int partition(int *arr, int p, int r)
{
    int i,j;

    i = j = p;
    for (; j < r; j++) {            // i��λһֱ��ĩ��С��Ԫ��λ��
        if (arr[j] < arr[r]) {
            if (i != j) {
                swap(arr+i, arr+j);
            }
            i++;
        }
    }
    swap(arr + i, arr +r);

    return i;
}

void __quick_sort(int *arr, int p, int r)
{
    int q;
    if (p >= r)
        return;

    q = partition(arr, p, r);
    __quick_sort(arr, p, q-1);
    __quick_sort(arr, q+1, r);
}

// ������
void quickSort(int *arr, int size)
{
    __quick_sort(arr, 0, size-1);
}



/*****************************************************
 * ���ֲ��� 
 * 
 * 
******************************************************/
int bsearch(int *arr, int length, int value)
{
    int low = 0;
    int high = length - 1;

    while (low <= high) {
        int mid = (high - low)/2 + low;
        if (arr[mid] == value) {
            return mid;
        }else if (arr[mid] > value){
            high = mid - 1;
        }else
            low = mid + 1;
    }

    return -1;
}


/*****************************************************
 * 
 * 
*****************************************************/
int main()
{
    int arr[] = {3,9,8,2,5,4,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,len);

    for (int i = 0; i < len; i++)
        printf("%d ",arr[i]);
    printf("\n");

    return 0;
}