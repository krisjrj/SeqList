//数组形式的整数加法
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //求K的位数
    int Ksize = 0;
    int Knum = K;
    while (Knum)
    {
        ++Ksize;
        Knum /= 10;
    }
    //给空间
    int len = ASize > Ksize ? ASize : Ksize;
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));
    //末位相加，赋值(倒置)
    int Ai = ASize - 1;//A最后一位
    //int ret = 0;//初始化相加的结果
    int reti = 0;//存放结果的位数
    int nextnum = 0;//=1进位，=0不进位
    while (len--)
    {
        //越界
        int a = 0;
        if (Ai >= 0)
        {
            a = A[Ai];
            Ai--;
        }
        int ret = a + K % 10 + nextnum;

        K /= 10;
        if (ret > 9)
        {
            ret -= 10;
            nextnum = 1;
        }
        else
        {
            nextnum = 0;
        }
        retArr[reti] = ret;
        ++reti;
    }
    if (nextnum == 1)
    {
        retArr[reti] = 1;
        ++reti;
    }
    //逆置
    int right = reti - 1;
    int left = 0;
    while (left < right)
    {
        int tmp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right] = tmp;
        ++left;
        --right;
    }
    *returnSize = reti;
    return retArr;
}
//最小K个数
//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Adjustdown(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        //判断是否存在右孩子
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }
        if (a[child] > a[parent])
        {
            //交换
            int tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            //向下传
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
int* smallestK(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    int* retArr = (int*)malloc(sizeof(int) * k);
    if (k == 0)
    {
        return retArr;
    }
    for (int i = 0; i < k; ++i)
    {
        retArr[i] = arr[i];
    }
    //建K个数的大堆
    //k-1是最后一个节点下标，(k-1-1)/2为该节点父节点的下标
    for (int i = (k - 1 - 1) / 2; i >= 0; --i)
    {
        Adjustdown(retArr, k, i);
    }
    for (int j = k; j < arrSize; j++)
    {
        if (arr[j] < retArr[0])
        {
            retArr[0] = arr[j];
            Adjustdown(retArr, k, 0);
        }
    }

    return retArr;
}
