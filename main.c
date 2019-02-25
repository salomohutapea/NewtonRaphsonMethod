#include<stdio.h>
#include<math.h>
float f(float x)
{
    return(pow(1.5, x) - 5);
}
float df (float x)
{
    return(pow(1.5, x) * (log(1.5)));
}
int main() {

    int itr = 1;
    float h, x0, x1, e;
    printf("\nEnter x0 and allowed RAE: \n");
    scanf("%f %f", &x0, &e);

    float rae;
    do {
        h = f(x0) / df(x0);
        x1 = x0 - h;
        rae = fabs((x1 - x0) / x1);
        printf("\nIteration no-%d    x = %f\n", itr, x1);
        printf("RAE in iteration no-%d is %f\n", itr, rae);
        x0 = x1;
        itr++;
    } while (rae > e);

    printf("\nAfter %d iterations, root = %8.6f\n", itr-1, x0);
    return 0;
}