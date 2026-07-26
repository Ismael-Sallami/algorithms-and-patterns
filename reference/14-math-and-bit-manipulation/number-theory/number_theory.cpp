// Pattern: Number theory
// Author:  Ismael Sallami Moreno
// Source:  written for this repository. Not extracted from earlier work,
//          unlike everything under patterns/ - there is no prior commit
//          history to link to for this file.
// Verify:  g++ -std=c++20 -O1 -Wall -o /tmp/check number_theory.cpp && /tmp/check
//          The file asserts its own behaviour, so a silent run is a pass.

#include <algorithm>
#include <cassert>
#include <vector>

using namespace std;

// Sieve of Eratosthenes. Every composite is crossed off by its smallest prime factor, so
// the total work is the harmonic sum over primes - O(n log log n), close enough to linear
// to be the right answer for any bounded range.
//
// Two details matter: the outer loop stops at sqrt(n), because a composite below n must
// have a factor below sqrt(n); and the inner loop starts at p*p, because smaller multiples
// of p were already crossed off by smaller primes.
vector<bool> prime_sieve(size_t limit) {
  vector<bool> is_prime(limit + 1, true);
  if (limit >= 1) { is_prime[0] = false; is_prime[1] = false; }
  for (size_t p = 2; p * p <= limit; ++p) {
    if (!is_prime[p]) continue;
    for (size_t multiple = p * p; multiple <= limit; multiple += p) is_prime[multiple] = false;
  }
  return is_prime;
}

// Smallest prime factor for every number up to the limit. One sieve pass gives
// factorisation in O(log n) per query afterwards, which beats trial division whenever many
// numbers have to be factorised.
vector<int> smallest_factor_sieve(size_t limit) {
  vector<int> smallest(limit + 1, 0);
  for (size_t i = 2; i <= limit; ++i) {
    if (smallest[i] != 0) continue;
    for (size_t multiple = i; multiple <= limit; multiple += i)
      if (smallest[multiple] == 0) smallest[multiple] = static_cast<int>(i);
  }
  return smallest;
}

vector<int> factorise(int value, const vector<int>& smallest) {
  vector<int> factors;
  while (value > 1) {
    factors.push_back(smallest[value]);
    value /= smallest[value];
  }
  return factors;
}

// Euclid's algorithm. Each step replaces the larger operand by the remainder, which at
// least halves it every two steps, so the cost is O(log min(a, b)).
long long gcd_of(long long a, long long b) {
  while (b != 0) {
    const long long remainder = a % b;
    a = b;
    b = remainder;
  }
  return a < 0 ? -a : a;
}

// Extended Euclid also returns x and y with a*x + b*y = gcd(a, b). Those coefficients are
// what give modular inverses, and so the whole of modular division.
struct Bezout {
  long long gcd;
  long long x;
  long long y;
};

Bezout extended_gcd(long long a, long long b) {
  if (b == 0) return {a, 1, 0};
  const Bezout deeper = extended_gcd(b, a % b);
  return {deeper.gcd, deeper.y, deeper.x - (a / b) * deeper.y};
}

// Modular exponentiation by squaring: O(log exponent) multiplications rather than
// `exponent` of them. Reducing at every step keeps the intermediates from overflowing.
long long mod_pow(long long base, long long exponent, long long modulus) {
  long long result = 1;
  base %= modulus;
  if (base < 0) base += modulus;
  while (exponent > 0) {
    if (exponent & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exponent >>= 1;
  }
  return result;
}

// Modular inverse. It exists only when the value and the modulus are coprime, which is why
// this returns -1 rather than a wrong answer for the cases that have none.
long long mod_inverse(long long value, long long modulus) {
  const Bezout bezout = extended_gcd(value % modulus, modulus);
  if (bezout.gcd != 1) return -1;
  return ((bezout.x % modulus) + modulus) % modulus;
}

// Chinese remainder theorem for two coprime moduli: the unique x below m1*m2 with
// x = r1 (mod m1) and x = r2 (mod m2).
long long crt_pair(long long r1, long long m1, long long r2, long long m2) {
  const long long inverse = mod_inverse(m1, m2);
  if (inverse == -1) return -1;  // moduli not coprime
  const long long difference = ((r2 - r1) % m2 + m2) % m2;
  return r1 + m1 * ((difference * inverse) % m2);
}

int main() {
  const vector<bool> primes = prime_sieve(50);
  assert(!primes[0] && !primes[1]);
  assert(primes[2] && primes[3] && primes[47]);
  assert(!primes[4] && !primes[9] && !primes[49]);
  int prime_count = 0;
  for (size_t i = 0; i <= 50; ++i)
    if (primes[i]) ++prime_count;
  assert(prime_count == 15);  // primes below 50

  const vector<int> smallest = smallest_factor_sieve(100);
  assert(factorise(60, smallest) == vector<int>({2, 2, 3, 5}));
  assert(factorise(97, smallest) == vector<int>({97}));
  assert(factorise(1, smallest).empty());

  assert(gcd_of(48, 18) == 6);
  assert(gcd_of(17, 5) == 1);
  assert(gcd_of(0, 5) == 5);
  assert(gcd_of(-48, 18) == 6);

  // Bezout: the identity must actually hold.
  const Bezout bezout = extended_gcd(240, 46);
  assert(bezout.gcd == 2);
  assert(240 * bezout.x + 46 * bezout.y == 2);

  assert(mod_pow(2, 10, 1000) == 24);  // 1024 mod 1000
  assert(mod_pow(3, 0, 7) == 1);
  assert(mod_pow(2, 100, 1000000007) == 976371285);
  // Fermat's little theorem: a^(p-1) = 1 mod p for prime p not dividing a.
  assert(mod_pow(3, 1000000006, 1000000007) == 1);

  assert(mod_inverse(3, 11) == 4);  // 3 * 4 = 12 = 1 mod 11
  assert(mod_inverse(4, 8) == -1);  // not coprime: no inverse exists

  // x = 2 mod 3 and x = 3 mod 5 gives 8, the unique solution below 15.
  const long long x = crt_pair(2, 3, 3, 5);
  assert(x == 8 && x % 3 == 2 && x % 5 == 3);
  assert(crt_pair(1, 4, 2, 6) == -1);  // 4 and 6 share a factor
  return 0;
}
