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

    int profit = 0, buy_d = 0, delta = 0;
    for(int i = 1; i < pricesSize; ++i)
    {
        if((delta = prices[i] - prices[buy_d]) > 0)
        {
            profit += delta;
            buy_d = i;
        }
        else
        {
            buy_d = i;
        }
    }

    return profit;
}

