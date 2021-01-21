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
    if (left < right)
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
int main()
{
    int A[] = { 1, 2, 0, 0 };
    int ASize = 4;
    int K = 34;
    int* returnSize=
    addToArrayForm(*A, ASize, K, int* returnSize);
    return 0;
}