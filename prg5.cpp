// #include <iostream>
// #include <gmpxx.h>

// void fSolve(const mpz_class& a, const mpz_class& x, const mpz_class& n, mpz_class& result) {
//     mpz_class exp;
//     exp = x % n;

//     result = mpz_class(1);
//     mpz_powm_ui(result.get_mpz_t(), a.get_mpz_t(), exp.get_ui(), n.get_mpz_t());
//     std::cout <<result;
// }


// void order(const mpz_class& a, const mpz_class& m) {
//     mpz_class ord = 1;
//     mpz_class temp = a;
//     while (temp != 1) {
//         temp = (temp * a) % m;
//         ord += 1;
//     }
//     std::cout << ord;
// }


// mpz_class ExtendedEuclidAlgo(mpz_class a, mpz_class b, mpz_class& x, mpz_class& y) {
//     if (b == 0) {
//         x = 1;
//         y = 0;
//         return a;
//     } else {
//         mpz_class x1, y1;
//         mpz_class gcd = ExtendedEuclidAlgo(b, a % b, x1, y1);
//         x = y1;
//         y = x1 - (a / b) * y1;
//         return gcd;
//     }
// }

// int main(int argc, char* argv[]) {
//     if (argc != 4) {
//         std::cerr << "Usage: " << argv[0] << " <b> <y> <m>";
//         return 1; // Return an error code
//     }

//     mpz_class b(argv[1]), y(argv[2]), m(argv[3]);
//     mpz_class result;

//     fSolve(b, y, m, result);

//     return 0;
// }


#include <iostream>
#include <gmpxx.h>

void modular_exponentiation(const mpz_class& base, const mpz_class& exponent, const mpz_class& modulus, mpz_class& result) {
    mpz_class exp;
    exp = exponent % modulus;

    result = mpz_class(1);
    mpz_powm_ui(result.get_mpz_t(), base.get_mpz_t(), exp.get_ui(), modulus.get_mpz_t());
    std::cout << result;
}

void calculate_order(const mpz_class& base, const mpz_class& modulus) {
    mpz_class ord = 1;
    mpz_class temp = base;
    while (temp != 1) {
        temp = (temp * base) % modulus;
        ord += 1;
    }
    std::cout << ord;
}

mpz_class extended_euclidean_algorithm(mpz_class a, mpz_class b, mpz_class& x, mpz_class& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        mpz_class x1, y1;
        mpz_class gcd = extended_euclidean_algorithm(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <base> <exponent> <modulus>";
        return 1; // Return an error code
    }

    mpz_class base(argv[1]), exponent(argv[2]), modulus(argv[3]);
    mpz_class result;

    modular_exponentiation(base, exponent, modulus, result);

    return 0;
}
