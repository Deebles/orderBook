#pragma once
#include <string>
#include <chrono>

class Order {

public:
	enum Currency {
		USD_CAD,
		EUR_USD,
		USD_GBP,
		USD_JPY,
		USD_CHF
	};

	enum Cpty {
		JPM,
		HSBC,
		GS,
		BAML
	};

	enum OrderEvent {
		ACCEPT,
		FILL,
		PARTIAL_FILL
	};

private:

	const std::string m_ticker;
	const std::string m_cpty;
	const int m_level;
	const std::string m_id;
	const time_t m_arriveTime;
	const std::string m_side;
	int m_notional;

public:

	Order(std::string ticker = "LMAHDS03",
		std::string cpty = "JPM",
		int level = 0,
		time_t arriveTime = 0,
		std::string side = "BUY",
		int notional = 0
		);

	void printOrder() const;

	void fillOrder(int fillAmount);

};

