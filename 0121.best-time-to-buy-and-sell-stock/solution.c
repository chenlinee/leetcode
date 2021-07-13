#include "solution.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int maxProfit(int* prices, int pricesSize){
    if(prices == NULL || pricesSize < 2)
    {
        return 0;
    }

    int profit = 0, min = 0, delta = 0;
    for(int i = 1; i < pricesSize; ++i)
    {
        if((delta = prices[i] - prices[min]) > 0)
        {
            profit = profit > delta ? profit : delta;
        }
        else
        {
            min = i;
        }
    }

    return profit;
}

