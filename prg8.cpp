#include <bits/stdc++.h>
#include <gmpxx.h>
using namespace std;

mpz_class greatestCommonDivisor(mpz_class m, mpz_class n)
{
    if (m == 0)
        return n;
    return greatestCommonDivisor(n % m, m);
}

mpz_class modularInverse(mpz_class a, mpz_class m)
{
    mpz_class original_m = m, temp, quotient;
    mpz_class x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        quotient = a / m;
        temp = m;
        m = a % m;
        a = temp;
        temp = x0;
        x0 = x1 - quotient * x0;
        x1 = temp;
    }
    if (x1 < 0)
        x1 += original_m;

    return x1;
}

int main(int argc, char *argv[])
{
    int numEquations = stoi(argv[1]);
    vector<mpz_class> aValues(numEquations);
    vector<mpz_class> bValues(numEquations);
    vector<mpz_class> mValues(numEquations);

    for (int i = 0; i < numEquations; ++i)
    {
        aValues[i] = argv[3 * i + 2];
        bValues[i] = argv[3 * i + 3];
        mValues[i] = argv[3 * i + 4];
    }

    for (int i = 0; i < numEquations; ++i)
    {
        mpz_class gcd = greatestCommonDivisor(aValues[i], mValues[i]);
        aValues[i] = aValues[i] / gcd;
        bValues[i] = bValues[i] / gcd;
        mValues[i] = mValues[i] / gcd;

        mpz_class inverse = modularInverse(aValues[i], mValues[i]);
        bValues[i] = bValues[i] * inverse;
    }

    mpz_class product = 1;
    for (int i = 0; i < numEquations; i++)
        product = product * mValues[i];

    mpz_class result = 0;
    for (int i = 0; i < numEquations; i++)
    {
        mpz_class quotient = product / mValues[i];
        result += bValues[i] * modularInverse(quotient, mValues[i]) * quotient;
    }

    if (result != 0)
    {
        cout << "Y " << result % product;
    }
    else
    {
        cout << "N";
    }

    return 0;
}
