#include <stdio.h>

#define MAX_ITER 1000

int mandelbrot(double real, double imag) {
    double z_real = 0.0, z_imag = 0.0;
    int n = 0;
    while (n < MAX_ITER && z_real * z_real + z_imag * z_imag <= 4.0) {
        double temp_real = z_real * z_real - z_imag * z_imag + real;
        z_imag = 2.0 * z_real * z_imag + imag;
        z_real = temp_real;
        n++;
    }
    return n;
}

void setColor(int iter) {
    if (iter == MAX_ITER) {
        printf("\033[48;5;0m ");      
    } else if (iter > 750) {
        printf("\033[48;5;18m ");  
    } else if (iter > 500) {
        printf("\033[48;5;27m ");  
    } else if (iter > 250) {
        printf("\033[48;5;45m ");  
    } else {
        printf("\033[48;5;231m ");  
    }
}

void resetColor() {
    printf("\033[0m");
}

void drawMandelbrot(int width, int height, double min_real, double max_real, double min_imag, double max_imag) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {

            double real = min_real + (max_real - min_real) * x / width;
            double imag = min_imag + (max_imag - min_imag) * y / height;

            int iter = mandelbrot(real, imag);

            setColor(iter);
        }
        resetColor();
        printf("\n");     }
}

int main() {
    int width, height;
    double min_real, max_real, min_imag, max_imag;

    printf("Введите ширину и высоту окна (например, 120 40): ");
    scanf("%d %d", &width, &height);

    printf("Введите минимальную и максимальную реальную часть (например, -2.0 1.0): ");
    scanf("%lf %lf", &min_real, &max_real);

    printf("Введите минимальную и максимальную мнимую часть (например, -1.0 1.0): ");
    scanf("%lf %lf", &min_imag, &max_imag);

    drawMandelbrot(width, height, min_real, max_real, min_imag, max_imag);

    return 0;
}

