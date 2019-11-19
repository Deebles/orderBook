#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <random>

using time_stamp = std::chrono::time_point<std::chrono::system_clock,
	std::chrono::microseconds>;

class Order {

private:
	const std::string m_orderType;
	const std::string m_ticker;
	const std::string m_cpty;
	const std::string m_id;
	const int m_level;
	time_stamp m_arriveTime;
	const std::string m_side;
	int m_notional;

public:
	Order(std::string orderType = "market",
		std::string ticker = "XAU/USD",
		std::string cpty = "JPM",
		int level = 0,
		time_stamp arriveTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now()),
		std::string side = "BUY",
		int notional = 0
	);

	void printOrder();
	void fillOrder(int fillAmount);
	std::string getSide();
	int getNotional();
	void setNotional(int notional);
	int getLevel();
	time_stamp getArriveTime();
	std::string getOrderType();

	//overload greater than operator to allow orderbook to sort stack by level

	bool operator <(const Order& orderObj) const
	{
		return m_level < orderObj.m_level;
	}
};
