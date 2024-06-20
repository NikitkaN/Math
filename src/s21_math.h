#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define s21_PI 3.14159265358979323846264338327950288
#define s21_NAN 0.0 / 0.0
#define s21_N_NAN -0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_NINF -1.0 / 0.0
#define s21_EPS 1e-17
#define s21_LN10 2.30258509299
#define s21_EXP 2.71828182845904
#define s21_MAX_DOUBLE 1.7976931348623157e308

int s21_abs(int x);  //вычисляет абсолютное значение целого числа +
long double s21_acos(double x);  //вычисляет арккосинус
long double s21_asin(double x);  //вычисляет арксинус
long double s21_atan(double x);  //вычисляет арктангенс
long double s21_ceil(double x);  //возвращает ближайшее целое число, не меньшее
                                 //заданного значения +
long double s21_cos(double x);   //вычисляет косинус +
long double s21_exp(
    double x);  //возвращает значение e, возведенное в заданную степень
long double s21_fabs(
    double x);  //вычисляет абсолютное значение числа с плавающей точкой +
long double s21_floor(double x);  //возвращает ближайшее целое число, не
                                  //превышающее заданное значение +
long double s21_fmod(double x,
                     double y);  //остаток операции деления с плавающей точкой +
long double s21_log(double x);  //вычисляет натуральный логарифм
long double s21_pow(double base,
                    double exp);  //возводит число в заданную степень
long double s21_sin(double x);  //вычисляет синус +
long double s21_sqrt(double x);  //вычисляет квадратный корень
long double s21_tan(double x);  //вычисляет тангенс +

#endif  // SRC_S21_MATH_H_
