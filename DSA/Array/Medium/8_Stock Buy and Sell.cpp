int maxProfit(vector<int> &prices)
{
    int maxpro = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            maxpro = max(maxpro, prices[j] - prices[i]);
        }
    }

    return maxpro;
}

int maxProfit(vector<int> &prices)
{
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;
    int maxi = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}