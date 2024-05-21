#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "../TradingSystem/StockerBrocker.h"
#include "../TradingSystem/App.cpp"

using namespace std;
using namespace testing;

class MockDriver : public StockerBrocker {
public:
	MOCK_METHOD(void, login, (string ID, string password), (override));
	MOCK_METHOD(void, buy, (string stockCode, int count, int price), (override));
	MOCK_METHOD(void, sell, (string stockCode, int count, int price), (override));
	MOCK_METHOD(int, getMarketPrice, (string stockCode, int minute), (override));
};


TEST(TradingSystemTest, 증권사선택_증권사선택에따라_해당증권사인사말출력) {

}

TEST(TradingSystemTest, 앱로그인_정상로그인_root_1234_입력되면로그인성공) {
	NiceMock<MockDriver> mockdriver{};
	EXPECT_CALL(mockdriver, login(testing::_, testing::_))
		.Times(1);
	auto app = App(&mockdriver);

	app.login("root", "1234");
}

TEST(TradingSystemTest, 앱로그인_비정상로그인_root_4444_입력되면로그인실패) {
	NiceMock<MockDriver> mockdriver{};
	EXPECT_CALL(mockdriver, login(testing::_, testing::_))
		.Times(0);
	auto app = App(&mockdriver);
	EXPECT_THROW(app.login("root", "4444"), std::exception);
}

TEST(TradingSystemTest, 매수기능_종목코드005930_가격80000_수량100_매수성공) {
	NiceMock<MockDriver> mockdriver{};
	App app(&mockdriver);
	EXPECT_CALL(mockdriver, buy).Times(1);

	app.buy("005930", 100, 80000);
}

TEST(TradingSystemTest, 매수기능_종목코드005930_가격0_수량100_매수실패) {
	NiceMock<MockDriver> mockdriver{};
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, buy).Times(0);

	EXPECT_THROW(app.buy("005930", 100, 0), std::exception);
}

TEST(TradingSystemTest, 매수기능_종목코드005930_가격80000_수량0_매수실패) {
	NiceMock<MockDriver> mockdriver{};
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, buy).Times(0);

	EXPECT_THROW(app.buy("005930", 0, 80000), std::exception);
}

TEST(TradingSystemTest, 매도기능_종목코드005930_가격80000_수량100_매도성공) {
	NiceMock<MockDriver> mockdriver{};
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, sell).Times(1);

	app.sell("005930", 100, 80000);
}

TEST(TradingSystemTest, 매도기능_종목코드005930_가격0_수량100_매도실패) {
	NiceMock<MockDriver> mockdriver{};
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, sell).Times(0);

	EXPECT_THROW(app.sell("005930", 100, 0), std::exception);
}

TEST(TradingSystemTest, 매도기능_종목코드005930_가격80000_수량0_매도실패) {
	MockDriver mockdriver;
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, sell).Times(0);

	EXPECT_THROW(app.sell("005930", 0, 80000), std::exception);
}

TEST(TradingSystemTest, 현재가확인_종목코드005930_현재가78000_확인성공) {
	MockDriver mockdriver;
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, getMarketPrice("005930", 5))
		.WillOnce(Return(78000));

	EXPECT_EQ(app.getPrice("005930", 5), 78000);
}

TEST(TradingSystemTest, 현재가확인_종목코드000000_현재가_확인실패) {
	MockDriver mockdriver;
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, getMarketPrice("000000", 5))
		.WillOnce(Return(78000));

	EXPECT_THROW(app.getPrice("000000", 5), std::exception);
}

TEST(TradingSystemTest, 기능1_buyNiceTiming_가격상승추세_사용자걸어둔만큼_현재가_전량수량매수) {
	MockDriver mockDriver;
	App app(&mockDriver);

	EXPECT_CALL(mockDriver, getMarketPrice("005930", 1))
		.WillOnce(Return(80000))
		.WillOnce(Return(90000))
		.WillRepeatedly(Return(100000));
	EXPECT_CALL(mockDriver, buy)
		.Times(1);

	app.buyNiceTiming("005930", 100000);
}

TEST(TradingSystemTest, 기능1_buyNiceTiming_가격하락추세_매수안함) {
	MockDriver mockDriver;
	App app(&mockDriver);

	EXPECT_CALL(mockDriver, getMarketPrice("005930", 1))
		.WillOnce(Return(80000))
		.WillOnce(Return(70000))
		.WillRepeatedly(Return(60000));
	EXPECT_CALL(mockDriver, buy)
		.Times(0);

	app.buyNiceTiming("005930", 100000);
}

TEST(TradingSystemTest, 기능2_sellNiceTiming_가격하락추세_사용자걸어둔만큼_현재가_전량매도) {
	MockDriver mockdriver;
	App app(&mockdriver);
  
	EXPECT_CALL(mockdriver, getMarketPrice)
		.WillOnce(Return(300))
		.WillOnce(Return(250))
		.WillOnce(Return(200))
		.WillOnce(Return(100));
	EXPECT_CALL(mockdriver, sell).Times(1);
	app.sellNiceTiming("APPLE", 1000);
}

TEST(TradingSystemTest, 기능2_sellNiceTiming_가격상승추세_매도안함) {
	MockDriver mockdriver;
	App app(&mockdriver);

	EXPECT_CALL(mockdriver, getMarketPrice)
		.WillOnce(Return(300))
		.WillOnce(Return(250))
		.WillOnce(Return(400));
	EXPECT_CALL(mockdriver, sell).Times(0);
	app.sellNiceTiming("APPLE", 1000);
}