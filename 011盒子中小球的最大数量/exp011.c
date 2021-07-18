// 你在一家生产小球的玩具厂工作，有 n 个小球，编号从 lowLimit 开始，到 highLimit 结束（包括 lowLimit 和 highLimit ，即 n == highLimit - lowLimit + 1）。
// 另有无限数量的盒子，编号从 1 到 infinity 。
// 你的工作是将每个小球放入盒子中，其中盒子的编号应当等于小球编号上每位数字的和。
// 例如，编号 321 的小球应当放入编号 3 + 2 + 1 = 6 的盒子，而编号 10 的小球应当放入编号 1 + 0 = 1 的盒子。

// 给你两个整数 lowLimit 和 highLimit ，返回放有最多小球的盒子中的小球数量。如果有多个盒子都满足放有最多小球，只需返回其中任一盒子的小球数量

#include<stdio.h>
#include<math.h>
int countBalls(int lowLimit,int higLimit){
    int temp;
    int sum;
    int hash[46]={0};//范围是100000，所以最大就是99999，也就是45个数
    for(int i=lowLimit;i<=higLimit;i++){
        temp = i;
        sum = 0;
        while (temp)
        {
            sum+=temp%10;
            temp /= 10;//改变temp的值控制循环，例如15%10=5，15/10=1，1！=0还执行1%10=1，所以sum=6
        }
        hash[sum]++;//对应数组计数加1
    }
    int max=hash[0];
    for(int j = 1;j < 46;j++){
        max = fmax(max,hash[j]);//fmax()返回较大的
    }
    return max;
}

int main(void){
    int lowLimit,higLimit; 
    scanf("lowLimit = %d, highLimit = %d",&lowLimit,&higLimit);
    int max = countBalls(lowLimit,higLimit);
    printf("%d",max);
    return 0;
}