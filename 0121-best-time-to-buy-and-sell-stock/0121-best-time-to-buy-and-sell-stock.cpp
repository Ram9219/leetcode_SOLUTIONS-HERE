class Solution {
public:
    int maxProfit(vector<int>& prices) {
    //    vector<int>best;
    //     int maxSum=INT_MIN;
    //     best[0]=INT_MAX;
    //     for(int i=0;i<prices.size()-1;i++){
    //         best[i]=min(best[i-1],prices[i-1]);
    //     }
    //     for(int i=0;i<prices.size()-1;i++){
    //         int current=prices[i]-best[i];
    //         maxSum=max(maxSum,current);
    //     }
    //     return maxSum;
    int sum=0;
    int minprice=INT_MAX;
    for(int price : prices){
        minprice=min(minprice,price);
        sum=max(sum,price-minprice);
    }
    return sum;
    }
};