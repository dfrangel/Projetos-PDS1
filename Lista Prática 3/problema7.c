# include <math.h>
int equacao (int a, int b, int c, double *end_x1, double *end_x2) {
    double delta, raiz1, raiz2;

    delta = (pow(b, 2)) - 4 * (a * c);

    if (delta < 0) {
        return 0;
    }
    
    raiz1 = (((-1) * b) + sqrt(delta)) / (2 * a);
    raiz2 = (((-1) * b) - sqrt(delta)) / (2 * a);

    if (delta == 0) {
        *end_x1 = raiz1;
        return 1;
    }
    else {
        *end_x1 = raiz1;
        *end_x2 = raiz2;
        return 2;
    }
}