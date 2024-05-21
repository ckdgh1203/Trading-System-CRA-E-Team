#include "StockerBrocker.h"
#include <iostream>

using namespace std;

class App {
public:
	App(StockerBrocker* stockerBroker) : m_stockerBroker(stockerBroker) {
	}

	void selectStockBrocker(string str)
	{

	}

	void login(string ID, string password) {
		if (ID != "root") throw std::exception("invalid ID");
		if (password != "1234") throw std::exception("invalid password");
		m_stockerBroker->login(ID, password);
	}

	void buy(string stockCode, int count, int price) {
		verifyPrice(price);
		verifyCount(count);

		m_stockerBroker->buy(stockCode, count, price);
	}
	
	void sell(string stockCode, int count, int price) {
		verifyPrice(price);
		verifyCount(count);
		m_stockerBroker->sell(stockCode, count, price);
	}

	int getPrice(string stockCode, int minute) {
		auto price = m_stockerBroker->getMarketPrice(stockCode, minute);
		cout << "Price of stock #" << stockCode << " at " << minute << " : " << price << endl;
	}

	void buyNiceTiming(string stockCode, int price) {

	}

	void sellNiceTiming(string stockCode, int count) {

	}

private:
	StockerBrocker* m_stockerBroker;

	void verifyCount(int count)
	{
		if (count == 0) throw std::exception("invalid count");
	}

	void verifyPrice(int price)
	{
		if (price == 0) throw std::exception("invalid price");
	}
};