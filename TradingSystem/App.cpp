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

	}

private:
	StockerBrocker* m_stockerBroker;
};