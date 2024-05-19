#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <random>

#include "counterparty.h"

using time_stamp = std::chrono::time_point<std::chrono::system_clock,
	std::chrono::microseconds>;

class Order {

private:
	std::string m_orderType;
	std::string m_ticker;
	Counterparty m_cpty;
	std::string m_id;
	int m_level;
	time_stamp m_arrivalTime;
	std::string m_side;
	int m_notional;

public:
	Order(const std::string& cpty = "TD",
		const std::string& orderType = "market",
		const std::string& ticker = "XAU/USD",
		int level = 0,
		const std::string& side = "BUY",
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
	void setArrivalTime();

	//overload greater than operator to allow orderbook to sort stack by level

	bool operator <(const Order& orderObj) const
	{
		return m_level < orderObj.m_level;
	}
};
