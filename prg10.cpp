#include <iostream>
#include <vector>
#include <gmpxx.h>

bool is_primitive_root(const mpz_class& base, const mpz_class& modulus) {
    mpz_class euler_phi = modulus - 1;
    std::vector<bool> visited(euler_phi.get_ui() + 1, false);

    mpz_class power = 1;
    for (mpz_class i = 0; i < euler_phi; ++i) {
        power = (power * base) % modulus;
        if (visited[power.get_ui()])
            return false;
        visited[power.get_ui()] = true;
    }
    return true;
}

// Function to perform modular exponentiation
mpz_class modPow(mpz_class base, mpz_class exponent, const mpz_class& modulus) {
    mpz_class result;
    mpz_powm(result.get_mpz_t(), base.get_mpz_t(), exponent.get_mpz_t(), modulus.get_mpz_t());
    return result;
}

void find_primitive_roots(const mpz_class& modulus) {
    mpz_class euler_phi = modulus - 1;
    std::vector<mpz_class> primitive_roots;

    for (mpz_class candidate = 2; candidate < modulus; ++candidate) {
        if (is_primitive_root(candidate, modulus)) {
            primitive_roots.push_back(candidate);
        }
    }

    std::cout << primitive_roots.size() << " ";
    for (int i = 0; i < primitive_roots.size() - 1; i++) std::cout << primitive_roots[i] << " ";
    std::cout << primitive_roots[primitive_roots.size() - 1];
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <modulus>";
        return 1;
    }

    mpz_class modulus(argv[1]);

    find_primitive_roots(modulus);

    return 0;
}
