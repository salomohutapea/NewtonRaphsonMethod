#include <stdio.h>
#include <math.h>

double f(double x)
{
    return(pow(1.5, x) - 5);
}

double df (double x)
{
    return(pow(1.5, x) * (log(1.5)));
}
main() {

    int itr = 1;
    double a = 10, b, e = 0.01, rae;

    do {

        b = a - f(a) / df(a);
        rae = fabs((b - a) / b);
        printf("\nIteration no-%d    x = %f    f(x) = %f\n", itr, b, f(b));
        printf("RAE in iteration no-%d is %f\n", itr, rae);
        a = b;
        itr++;
    } while (rae > e);

    printf("\nAfter %d iterations, root = %f\n", itr-1, b);

    return 0;
}