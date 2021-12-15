#include <stdio.h>

unsigned int int_pow(unsigned int num, unsigned int power);
unsigned int num_len(unsigned int num);

unsigned int alternate_digits(unsigned int src_num)
{
    unsigned int res_num = 0;
    unsigned int len = num_len(src_num);
    unsigned int i;
    for (i = len; i > len / 2; --i)
    {
        res_num *= 100;

        unsigned int high_dgt = src_num / int_pow(10, i - 1) % 10;
        unsigned int low_dgt = src_num / int_pow(10, len - i) % 10;

        res_num += (high_dgt * 10 + low_dgt);
    }

    if (len & 1) res_num /= 10;

    return res_num;
}

unsigned int int_pow(unsigned int num, unsigned int power)
{
    if (power == 0) return 1;
    unsigned int result = num;
    while (--power) result *= num;
    return result;
}

unsigned int num_len(unsigned int num)
{
    if (num == 0) return 0;
    unsigned int count = 1;
    while (num /= 10) ++count;
    return count;
}

int main()
{
    unsigned int src_num = 140;

    printf("%d and %u\n", src_num, alternate_digits(src_num));

    return 0;
}
