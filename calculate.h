#ifndef CALCULATE_H
#define CALCULATE_H
#include<cmath>
#include <iostream>

// 角度转弧度用于计算
double angleToArc(double angle)
{
	double pi = asin(0.5) * 6;
	return angle *pi / 180;
}

// 弧度转角度
double arcToAngle(double arc) {
	double pi = asin(0.5) * 6;
	return arc * 180 / pi;
}

double * SolveEquation(double matrix[4][5]){

    double base_D = (matrix[1][1]*matrix[2][2]*matrix[3][3]) +
           ( matrix[2][1]*matrix[3][2]*matrix[1][3]) +
            (matrix[3][1]*matrix[1][2]*matrix[2][3]);//计算行列式
         base_D = base_D-((matrix[1][3]*matrix[2][2]*matrix[3][1])
                 + (matrix[1][1]*matrix[2][3]*matrix[3][2])
                 + (matrix[1][2]*matrix[2][1]*matrix[3][3]));

         double x, y,z;
     if(base_D != 0){
         double  x_D = (matrix[1][4]*matrix[2][2]*matrix[3][3])
                 + (matrix[2][4]*matrix[3][2]*matrix[1][3])
                 + (matrix[3][4]*matrix[1][2]*matrix[2][3]);
             x_D = x_D-((matrix[1][3]*matrix[2][2]*matrix[3][4])
                     + (matrix[1][4]*matrix[2][3]*matrix[3][2]) +
                     (matrix[1][2]*matrix[2][4]*matrix[3][3]));
         double  y_D = (matrix[1][1]*matrix[2][4]*matrix[3][3])
                 + (matrix[2][1]*matrix[3][4]*matrix[1][3])
                 + (matrix[3][1]*matrix[1][4]*matrix[2][3]);
             y_D = y_D-((matrix[1][3]*matrix[2][4]*matrix[3][1] )
                     +( matrix[1][1]*matrix[2][3]*matrix[3][4])
                     +( matrix[1][4]*matrix[2][1]*matrix[3][3]));
         double  z_D = (matrix[1][1]*matrix[2][2]*matrix[3][4])
                 + (matrix[2][1]*matrix[3][2]*matrix[1][4])
                 + (matrix[3][1]*matrix[1][2]*matrix[2][4]);
             z_D = z_D-((matrix[1][4]*matrix[2][2]*matrix[3][1])
                     + (matrix[1][1]*matrix[2][4]*matrix[3][2])
                     +( matrix[1][2]*matrix[2][1]*matrix[3][4]));

          x =  x_D/base_D;
          y =  y_D/base_D;
          z =  z_D/base_D;

     }
     else {
         x = 0;
         y = 0;
         z = 0;
     }
    double* res = new double[3];
    res[0] = x;
    res[1] = y;
    res[3] = z;
    std::cout << "x: " << x << "    y: " << y << "  z: " << z << std::endl;
    return res;
}

// 保留小数点后 n 位
double ReserveNdigits(double value, int n){
    return round(value * pow(10 ,n) / pow(10, n));
}

double Validation(){
    double a11 = 4.972*pow(10,-6);
     double a12 = 1.23*pow(10,-5);
     double a21 = 1.23 * pow(10, -5);
     double a22 = 5.298*pow(10,-5);
     /*double x1 = 233.05;*/
     double x1 = 137.33;
     /*double x2 = 30.88;*/
     double x2 = 42.9339;
     /*double N = 4.54;*/
     double N = 18.8614;
     double a1p = 6.39*pow(10,-6) * N - 1.33*pow(10,-3);
     double a2p = 3.8*pow(10,-5) * N - 4.68*pow(10,-3);
     double result_1 = a11 * x1 + a12 * x2 + a1p;
     double result_2 = a21 * x1 + a22 * x2 + a2p;
     printf("%f\n%f\n", result_1, result_2);
     double u1 = 1.52 * pow(10, -6);
     double u2 = 5.01 * pow(10, -6);
     double u3 = 5.61 * pow(10, -8);
     double une = -4.56 * pow(10, -5);
     double f = 3.065;
     double Vnp = 230.64;
     double Qnp = -13.79;
     double Mnp = -374.59;
     double Vns = 1.297*N;
     double Qns = 1.44*N;
     double Mns = 0.42*N;
     double Vc = 141.25;
     double result_3 = x1 * u1+x2*(u2+f*u1)+u1*(Mnp+Mns)+u2*(Qnp+Qns)+u3*(Vnp+Vns+Vc)+une;
     printf("%f\n", result_3);
     double result_ltt = 2.47 * pow(10, -5) + 1.398 * pow(10, -6) * N;
     printf("%f\n", result_ltt);
     return 0;
}

#endif // CALCULATE_H
