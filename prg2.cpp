// #include <iostream>
// #include <gmpxx.h>

// using namespace std;

// void modInverse(mpz_class a, mpz_class m) {
//     mpz_class result;
//     mpz_gcd(result.get_mpz_t(), a.get_mpz_t(), m.get_mpz_t());

//     if (result != 1)
//         cout << "N" << endl; // Inverse doesn't exist
//     else {
//         mpz_invert(result.get_mpz_t(), a.get_mpz_t(), m.get_mpz_t());
//         cout << "Y " << result << endl; // Modular multiplicative inverse exists
//     }
// }

// // Function to perform the extended Euclidean algorithm
// tuple<mpz_class, mpz_class, mpz_class> extendedEuclidean(const mpz_class& a, const mpz_class& b) {
//     if (b == 0) {
//         return make_tuple(a, 1, 0);
//     }

//     mpz_class gcd, x1, y1;
//     tie(gcd, x1, y1) = extendedEuclidean(b, a % b);

//     mpz_class x = y1;
//     mpz_class y = x1 - (a / b) * y1;

//     return make_tuple(gcd, x, y);
// }

// // Function to return gcd of a and b using GMP
// mpz_class gcd(const mpz_class& a, const mpz_class& b) {
//     if (a == 0)
//         return b;
//     return gcd(b % a, a);
// }

// int main(int argc, char* argv[]) {
//     if (argc != 3) {
//         cerr << "Usage: " << argv[0] << " <integer1> <integer2>";
//         return 1;  // Return an error code
//     }

//     mpz_class a(argv[1]);
//     mpz_class b(argv[2]);

//     mpz_class gcd, x, y;
//     tie(gcd, x, y) = extendedEuclidean(a, b);
//     cout <<x << " " << y;

//     return 0;
// }


#include <iostream>
#include <gmpxx.h>

using namespace std;

void modInverse(mpz_class num, mpz_class mod) {
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), num.get_mpz_t(), mod.get_mpz_t());

    if (result != 1)
        cout << "N" << endl; // Inverse doesn't exist
    else {
        mpz_invert(result.get_mpz_t(), num.get_mpz_t(), mod.get_mpz_t());
        cout << "Y " << result << endl; // Modular multiplicative inverse exists
    }
}

// Function to perform the extended Euclidean algorithm
tuple<mpz_class, mpz_class, mpz_class> extendedEuclidean(const mpz_class& a, const mpz_class& b) {
    if (b == 0) {
        return make_tuple(a, 1, 0);
    }

    mpz_class gcd, x1, y1;
    tie(gcd, x1, y1) = extendedEuclidean(b, a % b);

    mpz_class x = y1;
    mpz_class y = x1 - (a / b) * y1;

    return make_tuple(gcd, x, y);
}

// Function to return gcd of a and b using GMP
mpz_class findGCD(const mpz_class& a, const mpz_class& b) {
    if (a == 0)
        return b;
    return findGCD(b % a, a);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <integer1> <integer2>";
        return 1;  // Return an error code
    }

    mpz_class num1(argv[1]);
    mpz_class num2(argv[2]);

    mpz_class gcd, x, y;
    tie(gcd, x, y) = extendedEuclidean(num1, num2);
    cout << x << " " << y;

    return 0;
}
