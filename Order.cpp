#include "Order.h"
#include <iostream>
#include <iomanip>
#include <chrono>
//#include <ctime>

Order::Order(
	std::string orderType,
	std::string ticker,
	std::string cpty,
	int level,
	time_stamp arriveTime,
	std::string side,
	int notional):
	m_orderType(orderType),
	m_ticker(ticker), 
	m_cpty(cpty),
	m_level(level),
	m_arriveTime(arriveTime), 
	m_side(side), 
	m_notional(notional){}

void Order::fillOrder(int fillAmount) {
	m_notional = m_notional - fillAmount;
}

void Order::printOrder() 
	{
	//std::time_t printableArrivalTime = std::chrono::system_clock::to_time_t(m_arriveTime);
	std::cout << m_level << " | " << m_orderType << " | " << m_ticker << " | " << m_cpty << " | ";
	std::cout /*<< m_arriveTime << " | " */ << m_side << " | " << m_notional << std::endl;
	}

std::string Order::getSide()
{
	return m_side;
}

int Order::getNotional() {
	return m_notional;
}

void Order::setNotional(int notional) {
	m_notional = notional;
}

int Order::getLevel() {
	return m_level;
}

std::string Order::getOrderType() {
	return m_orderType;
}

time_stamp Order::getArriveTime() {
	return m_arriveTime;
}

