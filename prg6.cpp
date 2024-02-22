#include <iostream>
#include <gmpxx.h>

using namespace std;

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(mpz_class number, mpz_class modulo) {
    mpz_class result;
    mpz_gcd(result.get_mpz_t(), number.get_mpz_t(), modulo.get_mpz_t());

    if (result != 1)
        cout << "N" << endl; // Inverse doesn't exist
    else {
        mpz_invert(result.get_mpz_t(), number.get_mpz_t(), modulo.get_mpz_t());
        cout << "Y " << result << endl; // Modular multiplicative inverse exists
    }
}

mpz_class GCD(mpz_class first, mpz_class second)
{
	if (first == 0)
		return second;
	return GCD(second % first, first);
}

// Driver Program
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <number> <modulo>" << endl;
        return 1; // Return an error code
    }

    mpz_class number(argv[1]), modulo(argv[2]);

    modInverse(number, modulo);

    return 0;
}
