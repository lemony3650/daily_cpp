#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/********************************************************
 * 时间复杂度较高，适合小规模的数据
 *          空间      时间              稳定      原地排序
 * 冒泡      O(1)     O(n*(n-1)/2)      1           1
 * 插入      O(1)     O(n^2)            1           1
 * 选择      O(1)     O(n^2)            0           1
---------------------------------------------------
 * 最好、最坏、平均时间复杂度 | 空间复杂度 | 稳定性
 * 同阶时的低阶系数
 * 比较和交换次数
----------------------------------------------------
 * 插入排序和冒泡都是n2，为什么更多用插入排序？？
   冒泡的交换实现（3行）要比插入（1行移位）繁琐许多
 * 若基于链表的实现，冒泡排序的比较次序一致，交换更复杂
 *                ，插入排序的比较次序一致，不需要后移
 *                ，选择排序的比较次序一致，交换也复杂
*********************************************************/


/***************************************************
 * 冒泡排序
 * 两两比较是否满足大小关系，内外圈都是次数
 * 一次冒泡出一个最终位置，内圈每次都从0开始重新冒泡
 * 最好 O(1)  最差O(n^2)  平均O(n*(n-1)/2)
 * 1.建立外圈、内圈的循环体，内圈len-i-1
 * 2.内圈逐一比较，确定末端位置
 * 3.利用标志位可以检测是否已经排好序
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
 * 插入排序
 * 有序区间和无序区间，默认有序为第一个元素，依次在无序中取元素插入有序
 * 1.取出要插入的数据，逐个与前面进行比较，从后往前比较，移位好移
 * 2.若前面的数据大于取出来的，向后移位
 * 3.插入取出的数据
 * 最好O(n) 最坏O(n^2) 平均O(n^2)
*************************************************************/
void insertSort(int *arr, int length)
{
    if(length <= 1)  return;

    for (int i = 1; i < length; i++) {
        int tmp = arr[i];
        int j = i-1;

        for (; j >= 0; j--) {
            if (arr[j] > tmp)
                arr[j+1] = arr[j];      //移位
            else 
                break;                   
        }   

        arr[j+1] = tmp;         //找到插入位置
    }
}

/********************************************************
 * 选择排序
 * 分为有序区间和无序区间，每次从无序中找最大或最小，找下标
 * 1.默认当前位置为最大，依次从后寻找比当前值大的下标
 * 2.替换已记录的最大下标
 * 3.将两个数值进行交换
 * 复杂度均为O(n^2)
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
 * 适合大规模的数据排序 O(nlogn)
 *              空间        时间            稳定      原地排序
 * 归并算法      O(n)       O(nlogn)          1         0
 * 快速排序      O(1)       O(nlogn)          0         1
 * 
 * 归并算法自下而上的依次进行合并，最终生成有序数据，需要开辟空间
 * 快排则是从上往下依次进行，有效规避空间开辟，但是不稳定
******************************************************************/

/*****************************************************************************
 * 归并算法
 * 时间复杂度O(nlogn) 与原数据是否有序无关
 * 1.利用分治的思想，将数据一分为二，采用递归方式继续分
 * 2.每次分为前后两个部分数据，建立临时空间通过比较大小来逐一合并两个部分数据
 * 3.每次进行合并即排序组合的过程
*****************************************************************************/
// 合并
void __merge(int *arr, int p, int q, int r)
{
    int *tmp;
    int i,j,k;

    // 申请临时空间
    tmp = (int *)malloc((r-p+1)*sizeof(int));
    if (!tmp)  
        abort();

    // 合并两个数组到一个tmp
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

//递归的分治实现  p-起始 r-终止 q-中间划分
void __merge_sort(int *arr, int p, int r) 
{
    int q;
    if (p >= r)  return;

    q = (p + r) / 2;
   	__merge_sort(arr, p, q);
	__merge_sort(arr, q + 1, r);

	__merge(arr, p, q, r);
}

// 主函数
void mergeSort(int *arr, int size)
{
    __merge_sort(arr, 0, size-1);
}

/********************************************************
 * 快速排序
 * 利用分治的思想，一般通过与末尾值进行比较划分子区间
 * 利用递归的编程思想进行递归操作，执行完毕数组便有序
 * 1.p q指向起始位置，r为分界区
 * 2.理论上让q先往前走，p跟着q再走，若出现大于分界线r，则p就不再走
 * 3.等待下一个小于出现时进行替换操作
 * 4.直到最后将r和分界进行交换即可,通过返回值标记分界
***************************************************************/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 以末尾元素为中位数进行划分
int partition(int *arr, int p, int r)
{
    int i,j;

    i = j = p;
    for (; j < r; j++) {            // i定位一直比末端小的元素位置
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

// 主函数
void quickSort(int *arr, int size)
{
    __quick_sort(arr, 0, size-1);
}



/*****************************************************
 * 二分查找 
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