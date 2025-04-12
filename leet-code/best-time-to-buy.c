// 121. Best Time to Buy and Sell Stock

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

 

Constraints:

    1 <= prices.length <= 105
    0 <= prices[i] <= 104

Case 1
    [7,1,5,3,6,4]

Case 2 
    [7,6,4,3,1]

*/

#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* prices, int pricesSize) {
    
    if(pricesSize <= 1){
        return 0;
    }

    int maxProfitValue = 0;
    int low = prices[0];

    for(int i=1; i<pricesSize; i++){

        // atualiza o menor valor minimo até o momento
        low = fmin(low, prices[i]);

        int profit = prices[i] - low;

        // atualiza o profit maximo
        maxProfitValue = fmax(maxProfitValue, profit);     

    }
    
    return maxProfitValue;
}

int maxProfit(int* prices, int pricesSize);

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = 6;
    int result1 = maxProfit(prices1, size1);
    printf("Case 1: %d\n", result1);

    int prices2[] = {7, 6, 4, 3, 1};
    int size2 = 5;
    int result2 = maxProfit(prices2, size2);
    printf("Case 2: %d\n", result2);

    return 0;
}