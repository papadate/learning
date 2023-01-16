#include <stdio.h>

int num1, num2, result;

int add(int *a, int *b)
{
    return (*a + *b);
}
int minus(int *a, int *b)
{
    return (*a - *b);
}
int mult(int *a, int *b)
{
    return (*a * *b);
}
int dvd(int *a, int *b)
{
    if (*b == 0)
    {
        printf("@语义错误@ 除数不能为 0\n\n");
        return -1;
    }
    return (*a / *b);
}


void choiceMod(int *choice)
{
    switch (*choice)
    {
        case 1 :
            result = add(&num1, &num2);
            break;
        
        case 2 :
            result = minus(&num1, &num2);
            break;

        case 3 :
            result = mult(&num1, &num2);
            break;
        
        default :
            result = dvd(&num1, &num2);
            break;
    }
    return;
}

int main()
{
    printf("!>简易计算器<!\n");
    int choice = 1; // default use the program
    
    int *p1, *p2;
    p1 = &num1;
    p2 = &num2;

    while (choice)
    {
        choice = 0;
        printf("请选择如下计算功能 : \n");
        printf("输入 数字 1 -> a + b\n");
        printf("输入 数字 2 -> a - b\n");
        printf("输入 数字 3 -> a * b\n");
        printf("输入 数字 4 -> a / b\n");
        printf("输入 数字 5 -> 退出程序\n");
        scanf("%d", &choice);
        // mistake input checking
        if (choice <= 0 || choice > 5)
        {
            printf("~~~~~~请输入正确的功能键~~~~~~\n");
            choice = 1;
            continue;
        }
        if (choice == 5)
        {
            choice = 0;
            break;
        }
        else
        {
            printf("输入 第一个数字 : ");
            scanf("%d", &num1);
            printf("输入 第二个数字 : ");
            scanf("%d", &num2);
            choiceMod(&choice);
            printf("答案是 : %d\n\n", result);
        }
    }
    printf("再见！\n");
    return;
}