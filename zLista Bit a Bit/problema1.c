# include "problema1.h"

unsigned long long fast_pow_2 (int n) {
    unsigned long long pot = 1;
 
    pot = pot << n;

    return pot;
}