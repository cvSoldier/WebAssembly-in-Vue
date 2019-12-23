int fibonacci(int n) {
  if (n <= 1) {
    return n;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int fibonacciTail(int n, int a1, int a2) {
  if (n <= 1) {
    return a2;
  } else {
    return fibonacciTail(n - 1, a2, a1 + a2);
  }
}
