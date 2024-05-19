#include "order.h"
#include <iostream>
#include <iomanip>
#include <chrono>
//#include <ctime>

Order::Order(
	const std::string& cpty,
	const std::string& orderType,
	const std::string& ticker,
	int level,
	const std::string& side,
	int notional):
	m_cpty(cpty),
	m_orderType(orderType),
	m_ticker(ticker), 
	m_level(level),
	m_side(side), 
	m_notional(notional)
{
}

void Order::fillOrder(int fillAmount) {
	m_notional = m_notional - fillAmount;
}

void Order::printOrder() 
	{
	//std::time_t printableArrivalTime = std::chrono::system_clock::to_time_t(m_arriveTime);
	std::cout << m_level << " | " << m_orderType << " | " << m_ticker << " | " << m_cpty.getName() << " | ";
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

void Order::setArrivalTime() {
	time_stamp m_arrivalTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
}

