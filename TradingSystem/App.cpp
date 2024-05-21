#include "StockerBrocker.h"

class App {
public:
	App(StockerBrocker* stockerBroker) : m_stockerBroker(stockerBroker) {
	}

	void selectStockBrocker(string str)
	{

	}

	void login(string ID, string password) {

	}

	void buy(string stockCode, int count, int price) {

	}
	
	void sell(string stockCode, int count, int price) {

	}

	int getPrice(string stockCode, int minute) {
		return 0;
	}

	void buyNiceTiming(string stockCode, int price) {
		int previousPrice[3] = { 0, };

		for (int iter = 0; iter < 3; iter++) {
			previousPrice[iter] = m_stockerBroker->getMarketPrice(stockCode, 1);
		}

		for (int iter = 0; iter < 2; iter++) {
			if (previousPrice[iter] < previousPrice[iter + 1]) continue;
		}

		int currentPrice = m_stockerBroker->getMarketPrice(stockCode, 1);
		int stockCount = (price / m_stockerBroker->getMarketPrice(stockCode, 1));
		m_stockerBroker->buy(stockCode, stockCount, currentPrice);
	}

	void sellNiceTiming(string stockCode, int count) {

	}

private:
	StockerBrocker* m_stockerBroker;
};