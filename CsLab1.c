#include <stdio.h>
int main() 
{
    setvbuf(stdout, NULL, _IONBF, 0);

    printf("==========================================\n");
    printf("==               TASK 1:                ==\n");
    printf("==========================================\n");
    int startTemperature; 
    int endTemperature;
    
    printf("Enter the starting temperature:");
    scanf("%i", &startTemperature);

    printf("Enter the ending temperature:");
    scanf("%i", &endTemperature);

    float increment = (endTemperature - startTemperature) / 9;
    printf("\nFahrenheit Celsius\n");
    printf("--------------------\n");

    int fTemperature;
    float cTemperature;
    
    fTemperature = startTemperature;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 2 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 3 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 4 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 5 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 6 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 7 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 8 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);
    
    fTemperature = startTemperature + 9 * increment;
    cTemperature = (fTemperature - 32) * 5.0 / 9.0;
    printf("%i    %.1f\n", fTemperature, cTemperature);

    printf("==========================================\n");
    printf("==               TASK 2:                ==\n");
    printf("==========================================\n");

    int real1;
    int real2;
    int imag1;
    int imag2;
    int sumReal;
    int sumImag;
    int diffReal;
    int diffImag;
    int prodReal;
    int prodImag;

    printf("Enter the real part of the first complex number: ");
    scanf("%i", &real1);
    printf("Enter the imaginary part of the first complex number: ");
    scanf("%i", &imag1);

    printf("Enter the real part of the second complex number: ");
    scanf("%i", &real2);
    printf("Enter the imaginary part of the second complex number: ");
    scanf("%i", &imag2);

    sumReal = real1 + real2;
    sumImag = imag1 + imag2;

    diffReal = real1 - real2;
    diffImag = imag1 - imag2;

    prodReal = real1 * real2 - imag1 * imag2;
    prodImag = real1 * imag2 + imag1 * real2;

    printf("\nSum: %.i + %.ii\n", sumReal, sumImag);
    printf("Difference: %i + %.ii\n", diffReal, diffImag);
    printf("Product: %.i + %.ii\n", prodReal, prodImag);

    return 0;
}
