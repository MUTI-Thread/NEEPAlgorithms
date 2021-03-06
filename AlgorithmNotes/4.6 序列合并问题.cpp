/**
* 广义上的two pointers是利用问题本身与序列的特性
* 使用两个下标i、j对序列进行扫描（可以同向扫描，也可以反向扫描）
* 以较低的复杂度（一般是O(n)的复杂度）解决问题
**/


/**
* 用two pointers思想解决序列合并问题
**/
int merge(int A[], int B[], int C[], int n, int m) {
    int i = 0, j = 0, index = 0; //i指向A[0]，j指向B[0]
    while (i < n && j < m) {
        if (A[i] <= B[j])
            C[index++] = A[i++]; //如果A[i]<=B[j]，将A[i]加入序列C
        else
            C[index++] = B[j++]; //如果A[i]>B[j]，将B[j]加入序列C
    }
    while (i < n)
        C[index++] = A[i++]; //将序列A的剩余元素加入序列C
    while (j < m)
        C[index++] = B[j++]; //将序列B的剩余元素加入序列C
    return index; //返回序列C的长度
}
