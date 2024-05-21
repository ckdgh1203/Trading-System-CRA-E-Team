#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/StockerBrocker.cpp"

using namespace std;
using namespace testing;

class MockDriver : public StockerBrocker {
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sell, (string stockCode, int count, int price), (override));
	MOCK_METHOD(int, getMarketPrice, (string stockCode, int minute), (override));
};

TEST(TestCaseName, TestName) {
	EXPECT_THAT(1, Eq(1));
}