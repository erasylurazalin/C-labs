#include <stdio.h>
int main()
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("==========================================\n");
    printf("==               TASK 1:                ==\n");
    printf("==========================================\n");

    int num;
    int steps;
    int temp;
    int sum;
    printf("Enter the starting number:");
    scanf("%d", &num);

    printf("Enter number of iterations:");
    scanf("%d", &steps);
    printf("%d", num);
    for (int i = 0; i < steps; i++)
    {
        temp = num;
        sum = 0;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        num += sum;
        printf(" -> %d", num);
    }
    printf("\n==========================================\n");
    printf("==               TASK 2:                ==\n");
    printf("==========================================\n");

    double x;
    int infinity = 100;
    double summ = 0;
    double sqrtPi = 1.77245385;
    double twoKplusOne = 1;
    double sign = -1;

    printf("Enter x:");
    scanf("%lf", &x);

    for (int k = 0; k < infinity; k++)
    {
        sign *= -1;
        twoKplusOne = 1 + 2 * k;

        double powerX = 1;
        for (int i = 0; i < twoKplusOne; i++)
        {
            powerX *= x;
        }
        double factorial = 1;
        for (int i = 1; i <= k; i++)
        {
            factorial *= i;
        }
        summ += (sign * powerX) / (factorial * twoKplusOne);

    }
    double result = (2 / sqrtPi) * summ;

    printf("erf(%.1lf) = %.5f\n", x, result);




    printf("\n==========================================\n");
    printf("==               TASK 3:                ==\n");
    printf("==========================================\n");

    int rows;
    printf("Enter the number of rows:");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= i; j++)
        {

            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}