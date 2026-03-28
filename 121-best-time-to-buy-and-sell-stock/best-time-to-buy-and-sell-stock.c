int maxProfit(int* prices, int pricesSize) {
    int maxprofit = 0;
    int minprofit = prices[0];
    for (int i = 1; i < pricesSize; i++) {
        if (minprofit > prices[i]) {
            minprofit = prices[i];
        } else if (prices[i] - minprofit > maxprofit) {
            maxprofit = prices[i] - minprofit;
        }
    }
    return maxprofit;
}