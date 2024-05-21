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

	}

	void sellNiceTiming(string stockCode, int count) {
		int prices[5];
		for (int i = 0; i < 5; i++) {
			prices[i] = m_stockerBroker->getMarketPrice(stockCode, 1);
		}

		bool isDecrease = true;
		for (int i = 0; i < 4; i++) {
			if (prices[i] >= prices[i + 1])
				continue;
			isDecrease = false;
			break;
		}

		if (isDecrease) {
			m_stockerBroker->sell(stockCode, count, m_stockerBroker->getMarketPrice(stockCode, 1));
		}
	}

private:
	StockerBrocker* m_stockerBroker;
};