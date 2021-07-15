// 202104-2
// Neighbor(i, j,r) ={Axy | 0 ≤ x, y < n and |x − i| ≤ r and |y − j| ≤ r}
// 【输入格式】
// 从标准输入读入数据。
// 输入共 n + 1 行。
// 输入的第一行包含四个用空格分隔的正整数 n、L、r 和 t
// 第二到第 n + 1 行输入矩阵 A。第 i + 2（0 ≤ i < n）行包含用空格分隔的 n 个整数，
// 依次为 Ai0, Ai1, · · · , Ai(n−1)。
// 【输出格式】
// 输出到标准输出。
// 输出一个整数，表示输入灰度图像中处于较暗区域的像素总数。

#include <stdio.h>
int main(void){
    int n, L, r, t;
    int matrix[600][600];
    int res = 0;
    int temp;
    scanf("%d%d%d%d",&n,&L,&r,&t);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&temp);
            matrix[i][j] = temp;
        }
    }
 
 
    //data process
    int sum = 0, num = 0, lastsum = 0, lastnum = 0;
    for(int i = 0; i < n; i++)
    {
        sum = num = 0;
        int bound_x = i + r > n - 1? n - 1 : i + r;
        int bound_y = 0 + r > n - 1? n - 1 : 0 + r;
        int start_x = i - r > 0 ? i - r : 0;
        for(int k = start_x; k <= bound_x; k++)
            for(int m = 0; m <= bound_y; m++)
            {
                num++;
                sum += matrix[k][m];
            }
        double avg = (double)sum / num;
        lastnum = num; 
        lastsum = sum;
        if(avg <= t)  res++;
        for(int j = 1; j < n; j++)
        {
            sum = lastsum;
            if(j - r <= 0)
            {
                num = lastnum + bound_x - start_x + 1;
                for(int m = start_x; m <= bound_x; m++)
                    sum += matrix[m][j+r];
                avg = (double)sum / num;
            }
            else if(j + r > n - 1)
            {
                num = lastnum - (bound_x - start_x + 1);
                for(int m = start_x; m <= bound_x; m++)
                    sum -= matrix[m][j - r - 1];
                avg = (double)sum / num;
            }
            else
            {
                num = lastnum;
                for(int m = start_x; m <= bound_x; m++)
                    sum += matrix[m][j+r] - matrix[m][j - r - 1];
                avg = (double)sum / num;
            }
            if(avg <= t)  res++;
            lastnum = num; 
            lastsum = sum;
        }
    }
    printf("%d",res);
    return 0;
}