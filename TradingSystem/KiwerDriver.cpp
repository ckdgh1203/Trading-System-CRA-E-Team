#include <string>
#include "StockerBrocker.h"
#include "KiwerAPI.cpp"

using namespace std;

class KiwerDriver : public StockerBrocker {
public:
	void login(string ID, string password) {
		kiwer.login(ID, password);
	}

	void buy(string stockCode, int count, int price) {
		kiwer.buy(stockCode, count, price);
	}

	void sell(string stockCode, int count, int price) {
		kiwer.sell(stockCode, count, price);
	}

	int getMarketPrice(string stockCode, int minute) {
		return kiwer.currentPrice(stockCode);
	}

private:
	KiwerAPI kiwer;
};