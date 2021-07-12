// 从标准输入读入数据。
// 输入的第一行包含一个正整数n，保证n∈[2,2^5] 
// 接下来输入n行，其中第 i（1≤i≤n）行包含用空格分隔的两个整数 

// 输出到标准输出。
// 输出一个非负整数，他的值是每行的两个值的乘积

#include<stdio.h>
int main(void){
    int ans = 0;
    int n;
    scanf("%d",&n);
    while(n--){
        int w,score;
        scanf("%d%d",&w,&score);
        ans += w*score;
    }
    printf("%d\n",ans>0?ans:0);
}