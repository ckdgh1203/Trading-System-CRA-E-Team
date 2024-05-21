#include "StockerBrocker.h"
#include "KiwerDriver.cpp"
#include "NemoDriver.cpp"

class App {
public:
	App(StockerBrocker* stockerBroker) : m_stockerBroker(stockerBroker) {
	}

	void selectStockBrocker(string str)
	{
		if (str == "KI")
		{
			KiwerDriver kd;
			m_stockerBroker = &kd;
			cout << "KI 증권사를 선택하셨습니다." << endl;
		}
		else if (str == "NE")
		{
			NemoDriver nd;
			m_stockerBroker = &nd;
			cout << "NE 증권사를 선택하셨습니다." << endl;
		}
		else
		{
			throw exception("증권사는 'KI' 또는 'NE' 중 선택해야 합니다.");
		}
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