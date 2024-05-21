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
		int prices[CHECK_TIMES];
		for (int i = 0; i < CHECK_TIMES; i++) {
			prices[i] = m_stockerBroker->getMarketPrice(stockCode, CHECK_INTERVAL_IN_MS);
		}

		if (isDecrease(prices)) {
			m_stockerBroker->sell(stockCode, count, m_stockerBroker->getMarketPrice(stockCode, CHECK_INTERVAL_IN_MS));
		}
	}

	bool isDecrease(const int *prices)
	{
		for (int i = 0; i < CHECK_TIMES - 1; i++) {
			if (prices[i] >= prices[i + 1])
				continue;
			return false;
		}
		return true;
	}

private:
	StockerBrocker* m_stockerBroker;
	const static int CHECK_TIMES = 3;
	const static int CHECK_INTERVAL_IN_MS = 1;
};