#include <iostream>
#include <vector>
#include <gmpxx.h>
using namespace std;

// Function to return gcd of a and b using GMP
mpz_class gcd(const mpz_class& a, const mpz_class& b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}


void modInverse(mpz_class a, mpz_class m) {
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), a.get_mpz_t(), m.get_mpz_t());

    if (result != 1)
        cout << "N" << endl; // Inverse doesn't exist
    else {
        mpz_invert(result.get_mpz_t(), a.get_mpz_t(), m.get_mpz_t());
        cout << "Y " << result << endl; // Modular multiplicative inverse exists
    }
}

mpz_class generateRRSM_and_phi(const mpz_class& m) {
    vector<mpz_class> rrsm; // To store the Reduced Residue System Modulo m
    mpz_class phi = 0; // To store the value of Euler's Totient Function

    for (mpz_class i = 1; i < m; i++) {
        if (gcd(i, m) == 1) {
            rrsm.push_back(i);
            phi++;
        }
    }

    for (const auto& num : rrsm) {
        cout << num << " ";
    }

    return phi;
}


mpz_class GCD(mpz_class m, mpz_class n)
{
	if (m == 0)
		return n;
	return GCD(n % m, m);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <integer>";
        return 1; // Return an error code
    }

    mpz_class m(argv[1]);

    if (m <= 0) {
        cerr << "Input value must be a positive integer.";
        return 1; // Return an error code
    }

    mpz_class phi_m = generateRRSM_and_phi(m);
    cout <<phi_m;

    return 0;
}
