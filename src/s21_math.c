#include "s21_math.h"

#include <stdio.h>

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_ceil(double x) {
  long double result = (long double)(int)x;
  if (x - (int)x > 0) {
    result += 1;
  }
  return result;
}

long double s21_floor(double x) {
  long double x_floor = 0;
  if ((x != x) || (x == s21_INF) || (x == -s21_INF)) {
    x_floor = x;
  } else {
    x_floor = (long long int)x;
    if (s21_fabs(x) > 0 && x != x_floor) {
      if (x < 0) {
        x_floor -= 1;
      }
    }
  }
  return x_floor;
}

double min_pi_x(double x) {
  x = s21_fmod(x, 2 * s21_PI);
  return (x);
}

long double s21_sin(double x) {
  x = min_pi_x(x);
  long double term = x;
  long double result = x;
  for (int i = 1; s21_fabs(term) > s21_EPS; i++) {
    term = term * (-1) * x * x / (2 * i * (2 * i + 1));
    result += term;
  }
  return result;
}

long double s21_cos(double x) {
  x = min_pi_x(x);
  long double term = 1;
  long double result = 1;
  for (int i = 1; s21_fabs(term) > s21_EPS; i++) {
    term = term * (-1) * x * x / (2 * i * (2 * i - 1));
    result += term;
  }
  return result;
}

long double s21_tan(double x) { return (s21_sin(x) / s21_cos(x)); }

long double s21_fmod(double x, double y) {
  long double result;
  if ((s21_fabs(x) == s21_INF) || (y == 0.0) || (x != x) || (y != y)) {
    result = s21_NAN;
  } else {
    if (s21_fabs(y) == s21_INF) {
      result = x;
    } else {
      long long int mod = x / y;
      result = (long double)x - mod * (long double)y;
    }
  }
  return result;
}

long double s21_exp(double x) {
  long double add_val = 1;
  long double series = 1;
  long double i = 1;
  int flag = 0;

  if (x < 0) {
    x *= -1;
    flag = 1;
  }
  while (s21_fabs(add_val) > s21_EPS) {
    add_val *= x / i;
    i += 1;
    series += add_val;
    if (series > s21_MAX_DOUBLE) {
      series = s21_INF;
      break;
    }
  }
  if (flag == 1) {
    if (series > s21_MAX_DOUBLE) {
      series = 0;
    } else {
      series = 1. / series;
    }
  }
  if (series > s21_MAX_DOUBLE) {
    return s21_INF;
  }
  return series;
}

long double s21_log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;
  if (x == s21_INF) {
    result = s21_INF;
  } else if (x == 0) {
    result = -s21_INF;
  } else if (x < 0) {
    result = s21_NAN;
  } else if (x == 1) {
    result = 0;
  } else {
    for (; x >= s21_EXP; x /= s21_EXP, ex_pow++) continue;
    int i;
    for (i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return (result + ex_pow);
}

long double s21_sqrt(double x) { return s21_pow(x, 0.5); }
long double s21_pow(double base, double exp) {
  return s21_exp(exp * s21_log(base));
}

long double s21_acos(double x) { return s21_PI / 2 - s21_asin(x); }

long double s21_asin(double x) { return s21_atan(x / s21_sqrt(1 - (x * x))); }

long double s21_atan(double x) {
  int n = 0, p = 0, s = 0;
  x < 0.l ? x = -x, n = 1.l : 0;
  x > 1.l ? x = (1.l / x), p = 1 : 0;
  while (x > s21_PI / 12.l) {
    s++;
    x = ((x * s21_sqrt(3)) - 1.l) * (1.l / (x + s21_sqrt(3)));
  }
  x = x * ((0.55913709l / (1.4087812l + x * x)) + 0.60310579l -
           0.05160454l * (x * x));
  while (s > 0) {
    x += (s21_PI / 6);
    s--;
  }
  x = p ? (s21_PI / 2) - x : x;
  x = n ? -x : x;
  return x;
}