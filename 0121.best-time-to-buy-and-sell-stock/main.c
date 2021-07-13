#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "solution.h"


int main(){

    // int maxProfit(int* prices, int pricesSize)
    // [7,1,5,3,6,4]
    int prices[] = {7,1,5,3,6,4};
    int pricesSize = sizeof(prices) / sizeof(prices[0]);

    int ret = maxProfit(prices, pricesSize);
    printf("ret = %d\n", ret);

    return 0;
}

