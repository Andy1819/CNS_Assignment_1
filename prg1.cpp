#include <iostream>
#include <vector>
#include <gmpxx.h>

using namespace std;

void computePower(const mpz_class& base, const mpz_class& exponent, const mpz_class& modulus, mpz_class& result) {
    mpz_class exp;
    exp = exponent % modulus;

    result = mpz_class(1);
    mpz_powm_ui(result.get_mpz_t(), base.get_mpz_t(), exp.get_ui(), modulus.get_mpz_t());
    std::cout << result;
}

mpz_class calculateGCD(mpz_class a, mpz_class b) {
    while (b != 0) {
        mpz_class temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void factorizeNumber(mpz_class number, vector<mpz_class>& factors) {
    if (number == 1) return;
    if (mpz_probab_prime_p(number.get_mpz_t(), 25) > 0) {
        factors.push_back(number);
        return;
    }
    mpz_class divisor = 1;
    factorizeNumber(divisor, factors);
    factorizeNumber(number / divisor, factors);
}

mpz_class findCommonDivisor(const vector<mpz_class>& array) {
    if (array.empty()) {
        // Handle empty array case
        return 0;
    }

    mpz_class result = array[0];

    for (size_t i = 1; i < array.size(); ++i) {
        result = calculateGCD(result, array[i]);
    }

    return result;
}

void printFactors(mpz_class number) {
    for (mpz_class i = 1; i <= number; ++i) {
        if(i==number) cout << i;
        else if (number % i == 0) cout << i << " ";
    }
}

int main(int argc, char* argv[]) {
    // Check if at least two arguments (besides the program name) are provided
    if (argc < 3) {
        cerr << "Usage: " << argv[0] << " num_count num1 num2 num3 ...";
        return 1;  // Return an error code
    }

    int numCount = atoi(argv[1]);  // Convert the first argument to an integer
    if (argc != numCount + 2) {
        cerr << "Incorrect number of arguments.";
        return 1;
    }

    vector<mpz_class> numbers;
    for (int i = 2; i < argc; ++i) {  // Start from index 2 to skip the first argument
        mpz_class num(argv[i]);
        numbers.push_back(num);
    }

    mpz_class commonDivisor = findCommonDivisor(numbers);
    printFactors(commonDivisor);

    return 0;
}
