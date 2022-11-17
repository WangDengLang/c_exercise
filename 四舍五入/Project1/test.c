#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
/*描述
将浮点数转换为整数类型，要求四舍五入。
输入描述：
随机输入的浮点数
输出描述：
四舍五入之后的整数*/

int main() {
    float d = 0;
    scanf("%f", &d);
    printf("%.1f", d);
    return 0;
}//转换规则内的精度参数可以直接帮我们自动四舍五入,只需要在% f中间加上.0就可以了，这样表示精确到小数点后0位