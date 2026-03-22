int divide(int dividend, int divisor) {

    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    long a = dividend;
    long b = divisor;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    long result = 0;  

    while (a >= b) {
        long temp = b;
        long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        result += multiple;
    }

    if ((dividend < 0) ^ (divisor < 0))
        result = -result;

    return (int)result;
}