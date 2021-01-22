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
//��СK����
//���һ���㷨���ҳ���������С��k������������˳�򷵻���k��������
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Adjustdown(int* a, int n, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < n)
    {
        //�ж��Ƿ�����Һ���
        if (child + 1 < n && a[child + 1] > a[child])
        {
            ++child;
        }
        if (a[child] > a[parent])
        {
            //����
            int tmp = a[parent];
            a[parent] = a[child];
            a[child] = tmp;
            //���´�
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
    //��K�����Ĵ��
    //k-1�����һ���ڵ��±꣬(k-1-1)/2Ϊ�ýڵ㸸�ڵ���±�
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
