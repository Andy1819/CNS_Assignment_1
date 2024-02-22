#include <iostream>
#include <gmpxx.h>

using namespace std;

// Function to find the gcd and also find the coefficients x and y in the equation ax + by = gcd(a, b)
mpz_class extendedEuclidAlgo(mpz_class a, mpz_class b, mpz_class& x, mpz_class& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        mpz_class x1, y1;
        mpz_class gcd = extendedEuclidAlgo(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd;
    }
}

mpz_class greatestCommonDivisor(mpz_class a, mpz_class b) {
    while (b != 0) {
        mpz_class temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void calculateOrder(const mpz_class& a, const mpz_class& m) {
    mpz_class ord = 1;
    mpz_class temp = a;
    while (temp != 1) {
        temp = (temp * a) % m;
        ord += 1;
    }
    std::cout << ord;
}

// Function to solve the congruence ax ≡ b (mod m)
void solveCongruence(mpz_class a, mpz_class b, mpz_class m) {
    mpz_class x, y;
    mpz_class gcd = extendedEuclidAlgo(a, m, x, y);

    if (b % gcd != 0) {
        cout << "N" << endl; // No solution exists
        return;
    }

    // Solution exists
    cout << "Y ";

    // The number of solutions is equal to the gcd of a and m
    cout << gcd << " ";

    // Finding one solution using the Extended Euclidean Algorithm
    mpz_class x0 = (x * (b / gcd)) % m;
    if (x0 < 0) x0 += m;

    // Printing all solutions
    for (mpz_class i = 0; i < gcd; i++) {
        mpz_class currentSolution = (x0 + i * (m / gcd)) % m;
        if(i==gcd-1) cout << currentSolution;
        else cout << currentSolution << " ";
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <a> <b> <m>" << endl;
        return 1; // Return an error code
    }

    mpz_class a(argv[1]), b(argv[2]), m(argv[3]);

    solveCongruence(a, b, m);

    return 0;
}
