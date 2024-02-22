#include <iostream>
#include <gmpxx.h>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

mpz_class GreatestCommonDivisor(mpz_class m, mpz_class n)
{
    if (m == 0)
        return n;
    return GreatestCommonDivisor(n % m, m);
}

mpz_class gcd(mpz_class a, mpz_class b) {
    mpz_class temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void FunctionSolve(const mpz_class& a, const mpz_class& x, const mpz_class& n, mpz_class& result) {
    mpz_class exp;
    exp = x % n;

    result = mpz_class(1);
    mpz_powm_ui(result.get_mpz_t(), a.get_mpz_t(), exp.get_ui(), n.get_mpz_t());
    std::cout << result;
}

// Function to perform the modular exponentiation
mpz_class ModularExponentiation(mpz_class base, mpz_class exponent, const mpz_class& modulus) {
    mpz_class result;
    mpz_powm(result.get_mpz_t(), base.get_mpz_t(), exponent.get_mpz_t(), modulus.get_mpz_t());
    return result;
}

// Pollard's rho algorithm for finding a divisor
mpz_class PollardsRho(mpz_class n) {
    if (n % 2 == 0) return 2;
    mpz_class x = rand() % n + 1, y = x;
    mpz_class c = rand() % n + 1;
    mpz_class d = 1;  

    while (d == 1) {
        x = (ModularExponentiation(x, 2, n) + c + n) % n;
        y = (ModularExponentiation(y, 2, n) + c + n) % n;
        y = (ModularExponentiation(y, 2, n) + c + n) % n;
        d = gcd(abs(x - y), n);
        if (d == n) return PollardsRho(n);
    }
    return d;
}

// Function to perform the prime factorization using Pollard's rho algorithm
void Factorize(mpz_class n, vector<mpz_class>& factors) {
    if (n == 1) return;
    if (mpz_probab_prime_p(n.get_mpz_t(), 25) > 0) {
        factors.push_back(n);
        return;
    }
    mpz_class divisor = PollardsRho(n);
    Factorize(divisor, factors);
    Factorize(n / divisor, factors);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <integer>";
        return 1;  // Return an error code
    }

    string inputStr(argv[1]);
    mpz_class input(inputStr);

    if (input <= 1) {
        cout << "No prime factors for numbers less than or equal to 1.";
        return 1;
    }

    srand(time(0)); // Seed for the random number generator used in rho

    vector<mpz_class> factors;
    Factorize(input, factors);

    for(int i=0; i<factors.size()-1; i++) cout << factors[i] << " ";
    cout << factors[factors.size()-1];
    return 0;
}
