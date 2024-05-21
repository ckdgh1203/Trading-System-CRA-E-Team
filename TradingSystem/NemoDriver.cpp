#include <string>
#include "StockerBrocker.cpp"
#include "NemoAPI.cpp"

using namespace std;

class NemoDriver : public StockerBrocker {
public:
	void login(string ID, string password) {
		nemo.certification(ID, password);
	}

	void buy(string stockCode, int count, int price) {
		nemo.purchasingStock(stockCode, count, price);
	}

	void sell(string stockCode, int count, int price) {
		nemo.sellingStock(stockCode, count, price);
	}

	int getMarketPrice(string stockCode, int minute) {
		return nemo.getMarketPrice(stockCode, minute);
	}

private:
	NemoAPI nemo;
};