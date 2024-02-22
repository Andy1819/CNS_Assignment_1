#include <iostream>
#include <gmpxx.h>

void order(const mpz_class& base, const mpz_class& mod) {
    mpz_class ord = 1;
    mpz_class temp = base;
    while (temp != 1) {
        temp = (temp * base) % mod;
        ord += 1;
    }
    std::cout << ord;
}

void fSolve(const mpz_class& base, const mpz_class& exponent, const mpz_class& mod, mpz_class& result) {
    mpz_class exp;
    exp = exponent % mod;

    result = mpz_class(1);
    mpz_powm_ui(result.get_mpz_t(), base.get_mpz_t(), exp.get_ui(), mod.get_mpz_t());
    std::cout << result;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <base> <modulus>";
        return 1;
    }

    mpz_class base(argv[1]), mod(argv[2]);

    order(base, mod);

    return 0;
}
