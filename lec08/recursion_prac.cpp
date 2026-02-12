/*
 * 02/11/2026
 * Recursion Lecture
 * Practice Exercises
 */

//sums all integers from a to b
int sum(int a, int b) {
    if(a == b) {
        return a;
    } else {
        return a + sum(a + 1, b);
    }
}

//returns x^k
int power(int x, int k) {
    if (k == 0) {
        return 1;
    } else {
        return x * power(x, k - 1);
    }
}

//returns x * y
int multiply(int x, int y) {
    if (y == 1) {
        return x;
    } else {
        return x + multiply(x, y - 1);
    }
}

//num_coins
int num_coins(int cents) {
    if (cents < 5) {
        return cents; //add pennies
    } else if (cents < 10) {
        return 1 + num_coins(cents - 5); //add a nickel
    } else if (cents < 25) {
        return 1 + num_coins(cents - 10); //add a dime
    } else {
        return 1 + num_coins(cents - 25); //add a quarter
    }
}

int gcd(int m, int n) {
    return gcd_helper(m,n,n);
}

int gcd_helper(int guess, int m, int n) {
    if ((m%guess == 0) and (n%guess == 0)) return guess;
    else return gcd_helper(m,n,guess - 1);
}
