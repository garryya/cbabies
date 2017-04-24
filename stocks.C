#include <iostream>
#include <string>
#include <map>
#include <vector>

using Stocks = std::vector<int>;
using StockPair = std::pair<int, int>;

static StockPair usp(-1,-1);

int profit(const Stocks& stocks, const StockPair& sp)
{
  return stocks[sp.second] - stocks[sp.first];
}

StockPair FindBestProfit(const Stocks& stocks)
{
    StockPair bsp = usp;
    if( !stocks.size() )
      return bsp;
    auto iMin = -1;
    for(auto i=0U; i < stocks.size(); i++)
    {
      if(iMin == -1 || stocks[i] < stocks[iMin])
        iMin = i;
      StockPair sp(iMin, i);
      if(i>0 && (bsp != usp || profit(stocks, sp) > profit(stocks, bsp)))
      {
        bsp = sp;
      }
    }
    
    return bsp;
}



int main(int argc, const char ** argv)
{
    Stocks stocks = {10, 7, 5, 8, 11, 9};
    
    auto bp = FindBestProfit(stocks);
    
    if(bp != usp)
      std::cout << "best buy-sell: " << bp.first << " ---> " << bp.second << std::endl;
    else
      std::cout << "best buy-sell: undefined" << std::endl;
    
    return 0;
}
