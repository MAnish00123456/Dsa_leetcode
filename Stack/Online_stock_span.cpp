// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:

// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.

// Input
// ["StockSpanner", "next", "next", "next", "next", "next", "next", "next"]
// [[], [100], [80], [60], [70], [60], [75], [85]]
// Output
// [null, 1, 1, 1, 2, 1, 4, 6]
 
#include<iostream>
#include<vector>
#include<stack>

class StockSpanner {
    int i = 0;
    int span = 0;
    // Stores all prices received so far so that
    // indices in the stack can be mapped back to prices.
    std::vector<int>StockPrice;
    // Stores indices of previous stock prices.
    // Prices corresponding to these indices are maintained
    // in strictly decreasing order from bottom to top.
    std::stack<int>st;
    public:
    StockSpanner(){
        }

        int next(int price){
            // Add today's price to the price history.
            StockPrice.push_back(price);
            // Remove all previous prices that are smaller than or
            // equal to today's price.
            //
            // Such prices can never be the nearest greater element
            // for today's price or any future larger price.
            while(!st.empty() && StockPrice[st.top()] <= price){
                st.pop();
            }
            // If no previous greater price exists, span covers all days so far.
            // Otherwise, span is the distance from the current day to the
            // nearest previous day with a strictly greater price.
            span = st.empty() ? i + 1 : i - st.top();
            
            // Store current day's index while preserving the monotonic stack.
            st.push(i++);
            return span; 
        }
};

int main(){
StockSpanner stockSpanner;
std::cout<<"Enter stock prices to calculate span :"<<"\n"<<std::endl;
int price;
while(true){
    std::cout<<"Enter today's stock price (write 0 to exit loop):"<<"\n";
    std::cin>>price;
    if(price == 0)break;
    std::cout<<"Span count :  "<<stockSpanner.next(price)<<std::endl;
}
return 0;
}