#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9 //数组元素个数
int array[N] = {2, 7, -6, 3, -1, 4, -2, -9, -4}; //原数组
int B[N]; //在动态规划中使用的数组,用于记录中间结果,其含义三言两语说不清,请参见博文的解释
int len; //用于标示B数组中的元素个数

int LIS(int *array, int n); //计算最长递增子序列的长度,计算B数组的元素,array[]循环完一遍后,B的长度len即为所求
int BiSearch(int *b, int len, int w); //做了修改的二分搜索算法

int main()
{
        printf("LIS: %d\n", LIS(array, N));

        int i;
        for(i=0; i<len; ++i)
        {
                printf("B[%d]=%d\n", i, B[i]);
        }

        return 0;
}


int LIS(int *array, int n)
{
        len = 1;
        B[0] = array[0];
        int i, pos = 0;

        for(i=1; i<n; ++i)
        {
                if(array[i] > B[len-1])
                {
                        B[len] = array[i];
                        ++len;
                }
                else
                {
                        pos = BiSearch(B, len, array[i]);
                        B[pos] = array[i];
                }
        }

        return len;
}


//做了修改的二分搜索算法,若要查找的数w在长为len的数组b中存在则返回下标,
//若不存在,则返回b数组中的刚刚大于w的那个元素的下标,该元素即需要被替换的元素
int BiSearch(int *b, int len, int w)
{
        int left = 0, right = len-1;
        int middle;
        while(left <= right)
        {
                middle = (left+right)/2;
                if(b[middle] > w)
                        right = middle - 1;
                else if(b[middle] < w)
                        left = middle + 1;
                else
                        return middle;
        }

        return (b[middle]>w) ? middle : middle+1; //即返回b数组中的刚刚大于w的那个元素的下标
}