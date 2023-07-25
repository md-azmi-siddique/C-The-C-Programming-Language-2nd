#include<stdio.h>

void celciusToFarenheit(float upperLimit, float lowerLimit, float step)
{
    float celsiusTempreature;
    printf("Celsius\t\tFahrenheit\n");
    printf(".......\t\t..........\n");
    for(celsiusTempreature = lowerLimit; celsiusTempreature <= upperLimit; celsiusTempreature += step)
    {
        printf("%.2f\t\t%.2f\n", celsiusTempreature, (1.8 * celsiusTempreature) + 32);
    }
}

void farenheitToCelcius(float upperLimit, float lowerLimit, float step)
{
    float farhenhitTempreature;
    printf("Fahrenheit\tCelsius\n");
    printf("...........\t.......\n");
    for(farhenhitTempreature = lowerLimit; farhenhitTempreature <= upperLimit; farhenhitTempreature += step)
    {
        printf("%.2f\t\t%.2f\n", farhenhitTempreature,  ((farhenhitTempreature - 32)*5 / 9));
    }
}




main()
{
    float upperLimit, lowerLimit, step;
    printf("Enter Upper Limit:");
    scanf("%f",&upperLimit);
    printf("Enter Lower Limit:");
    scanf("%f",&lowerLimit);
    printf("Enter Step:");
    scanf("%f",&step);
    celciusToFarenheit(upperLimit, lowerLimit, step);
    printf("\n");
    farenheitToCelcius(upperLimit, lowerLimit, step);

    return 0;
}
