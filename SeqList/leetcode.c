//������ʽ�������ӷ�
#include<stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //��K��λ��
    int Ksize = 0;
    int Knum = K;
    while (Knum)
    {
        ++Ksize;
        Knum /= 10;
    }
    //���ռ�
    int len = ASize > Ksize ? ASize : Ksize;
    int* retArr = (int*)malloc(sizeof(int) * (len + 1));
    //ĩλ��ӣ���ֵ(����)
    int Ai = ASize - 1;//A���һλ
    //int ret = 0;//��ʼ����ӵĽ��
    int reti = 0;//��Ž����λ��
    int nextnum = 0;//=1��λ��=0����λ
    while (len--)
    {
        //Խ��
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
    //����
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