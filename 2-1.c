#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

void header_file() {
    printf("Range of Unsigned char: 0 to %u\n", UCHAR_MAX);
    printf("Range of Signed char: %d to %d\n", CHAR_MIN, CHAR_MAX);

    printf("################################################\n");
    printf("Range of Unsigned short: 0 to %u\n", USHRT_MAX);
    printf("Range of Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);

    printf("################################################\n");
    printf("Range of Unsigned int: 0 to %u\n", UINT_MAX);
    printf("Range of Signed int: %d to %d\n", INT_MIN, INT_MAX);

    printf("################################################\n");
    printf("Range of Unsigned long: 0 to %lu\n", ULONG_MAX);
    printf("Range of Signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);

    printf("################################################\n");
    printf("Range of Signed float: %e to %e\n", FLT_MIN, FLT_MAX);
}

void computation(int n, char s[]) {
    int sign_min = -pow(2, n - 1);
    int sign_max = pow(2, n - 1) - 1;
    unsigned int unsign_max = pow(2, n) - 1;
    printf("Range of Unsigned %s: 0 to %u\n", s, unsign_max);
    printf("Range of Signed %s: %d to %d\n", s, sign_min, sign_max);
}
/*
void computation_float(){
    int exponentBits = FLT_MAX_EXP - FLT_MIN_EXP + 1;  // Number of bits for the exponent
    int mantissaBits = FLT_MANT_DIG - 1;  // Number of bits for the mantissa (excluding the implicit 1)

    float minValue = -powf(2, mantissaBits) * (1 - powf(2, -mantissaBits));
    float maxValue = powf(2, mantissaBits) * (1 - powf(2, -mantissaBits)) * powf(2, exponentBits - 1);

    printf("Range of Signed float using equation:\n");
    printf("Minimum value: %.7e\n", minValue);
    printf("Maximum value: %.7e\n", maxValue);
}
*/
int main() {
    int c = sizeof(char) * 8, s = sizeof(short) * 8, i = sizeof(int) * 8, l = sizeof(long) * 8;
    char ch[] = "character";
    char sh[] = "short";
    char in[] = "int";
    char ln[] = "long";

    printf("By Using Header\n");
    header_file();

    printf("\n\n");

    printf("By direct computation\n");
    computation(c, ch);
    printf("################################################\n");
    computation(s, sh);
    printf("################################################\n");
    computation(i, in);
    printf("################################################\n");
    computation(l, ln);

    return 0;
}

