#include <string>
using namespace std;

class StockerBrocker {
public:
	virtual void login(string ID, string password) = 0;
	virtual void buy(string stockCode, int count, int price) = 0;
	virtual void sell(string stockCode, int count, int price) = 0;
	virtual int getMarketPrice(string stockCode, int minute) = 0;
};
