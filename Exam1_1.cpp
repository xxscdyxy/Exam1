#include <stdio.h>
#include <math.h>

int main()
{
    //given data  
    float h = 0.15;
    //float h = 0.5;
    //float h = 1.0;
    int t_upper = 6;
    int t_lower = 0;
    float k2_2 = 0.0;
    float k1_4 = 0.0;
    float k2_4 = 0.0;
    float k3_4 = 0.0;
    float k4_4 = 0.0;
    int t_points = (t_upper - t_lower) / h;
    float t1[t_points];
    float ¦È1[t_points];//Explicit Euler
    float t2[t_points];
    float ¦È2[t_points];//Implicit Euler
    float t3[t_points];
    float ¦È3[t_points];//Second-Order Runge-Kutta
    float t4[t_points];
    float ¦È4[t_points];//Fourth-Order Runge-Kutta
    //set initial value
    t1[0] = 0.0;
    t2[0] = 0.0;
    t3[0] = 0.0;
    t4[0] = 0.0;
    ¦È1[0] = 1.0;
    ¦È2[0] = 1.0;
    ¦È3[0] = 1.0;
    ¦È4[0] = 1.0;
    int i = 0;
    //Explicit Euler
    for (i = 0; i <= t_points; i++)
    {
        ¦È1[i + 1] = ¦È1[i] - 0.5 * sqrt(327 / 5) * sin(0.5 * sqrt(327 / 5) * t1[i]) * h;
        t1[i + 1] = t1[i] + h;
        printf("%3.2f  ", t1[i]);
        printf("%3.2f  ", ¦È1[i]);
        printf("\n");
    }


    //Implicit Euler
    for (i = 0; i <= t_points; i++)
    {
        t2[i + 1] = t2[i] + h;
        ¦È2[i + 1] = ¦È2[i] - 0.5 * sqrt(327 / 5) * sin(0.5 * sqrt(327 / 5) * t2[i + 1]) * h;
        printf("%3.2f  ", t2[i]);
        printf("%3.2f  ", ¦È2[i]);
        printf("\n");
    }
    //Second-Order Runge-Kutta
    for (i = 0; i <= t_points; i++)
    {
        k2_2 = h * (-0.5) * sqrt(327 / 5) * sin((0.5) * sqrt(327 / 5) * (t3[i] + 0.5 * h));
        ¦È3[i + 1] = ¦È3[i] + k2_2;
        t3[i + 1] = t3[i] + h;
        printf("%3.2f  ", t3[i]);
        printf("%3.2f  ", ¦È3[i]);
        printf("\n");
    }
    //Fourth-Order Runge-Kutta
    for (i = 0; i <= t_points; i++)
    {
        k1_4 = h * (-0.5) * sqrt(327 / 5) * sin((0.5) * sqrt(327 / 5) * t4[i]);
        k2_4 = h * (-0.5) * sqrt(327 / 5) * sin((0.5) * sqrt(327 / 5) * (t4[i] + 0.5 * h));
        k3_4 = h * (-0.5) * sqrt(327 / 5) * sin((0.5) * sqrt(327 / 5) * (t4[i] + 0.5 * h));
        k4_4 = h * (-0.5) * sqrt(327 / 5) * sin((0.5) * sqrt(327 / 5) * (t4[i] + h));
        t4[i + 1] = t4[i] + h;
        ¦È4[i + 1] = ¦È4[i] + k1_4 / 6 + k2_4 / 3 + k3_4 / 3 + k4_4 / 6;
        printf("%3.2f  ", t4[i]);
        printf("%3.2f  ", ¦È4[i]);
        printf("\n");
    }





}