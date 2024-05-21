#include "StockerBrocker.cpp"
#include "KiwerDriver.cpp"
#include "NemoDriver.cpp"

class App {
public:
	void selectStockBrocker(string selectedBrocker)
	{
		if (selectedBrocker == "KI")
		{
			KiwerDriver kd;
			stockerbrocker = &kd;
			cout << "KI 증권사를 선택하셨습니다." << endl;
		}else if (selectedBrocker == "NE")
		{
			NemoDriver nd;
			stockerbrocker = &nd;
			cout << "NE 증권사를 선택하셨습니다." << endl;
		}
		else
		{
			throw exception("증권사는 'KI' 또는 'NE' 중 선택해야 합니다.");
		}
	}

protected:
	StockerBrocker* stockerbrocker;
};