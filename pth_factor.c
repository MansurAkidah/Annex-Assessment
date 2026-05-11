#include <stdio.h>

long pthFactor(long n, long p) {
    
    long count = 0, position = 0;
    long perfect_divisible[n];

    for (long i = 1; i <= n; i++){
        if (n % i == 0){
            perfect_divisible[count] = i;
            if (count == p - 1) {
                position = count;
                break;
            }
            count++;
        }
    }

    return perfect_divisible[position ];
}

int main() {
    test_pthFactor();
    return 0;
}

static void test_pthFactor() {
    // Test case 1: n=12, p=3 -> expected: 3 (factors: 1,2,3,4,6,12)
    long result1 = pthFactor(12, 3);
    printf("Test 1: pthFactor(12, 3) = %ld\n", result1);
    
    // Test case 2: n=10, p=4 -> expected: 10 (factors: 1,2,5,10)
    long result2 = pthFactor(10, 4);
    printf("Test 2: pthFactor(10, 4) = %ld\n", result2);
    
    // Test case 3: n=100, p=5 -> expected: 10 (factors: 1,2,4,5,10,20,25,50,100)
    long result3 = pthFactor(100, 5);
    printf("Test 3: pthFactor(100, 5) = %ld\n", result3);
}
