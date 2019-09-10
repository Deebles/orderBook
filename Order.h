#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <random>

class Order {

private:
	const std::string m_ticker;
	const std::string m_cpty;
	const int m_level;
	const std::string m_id;
	const time_t m_arriveTime;
	const std::string m_side;
	int m_notional;

public:
	Order(std::string ticker = "XAU/USD",
		std::string cpty = "JPM",
		int level = 0,
		time_t arriveTime = 0,
		std::string side = "BUY",
		int notional = 0
		);

	void printOrder() const;
	void fillOrder(int fillAmount);
	std::string getSide();
	int getLevel();
	int getNotional();
	time_t getArriveTime();
	void setID(std::string ID);
};

