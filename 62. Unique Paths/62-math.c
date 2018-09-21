int choose(double n, double m) {
  double res = 1;
  for(double i = n; i > n - m; i--) {
    res *= i;
    res /= (i - n + m);
  }
  return round(res);
}

int uniquePaths(int m, int n) {
  return choose((double) (n + m - 2), (double) (n - 1));
}