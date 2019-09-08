#include "Order.h"
#include <iostream>
#include <ctime>

Order::Order(
	std::string ticker,
	std::string cpty,
	int level,
	time_t arriveTime,
	std::string side,
	int notional):
	m_ticker(ticker), 
	m_cpty(cpty), 
	m_level(level), 
	m_arriveTime(arriveTime), 
	m_side(side), 
	m_notional(notional){}

void Order::fillOrder(int fillAmount) {
	m_notional = m_notional - fillAmount;
}

void Order::printOrder() const 
	{
	std::cout << m_level << "\t" << m_notional << "\t" << m_cpty << "\t" << m_id << std::endl;
	}

std::string Order::getSide()
{
	return m_side;
}

int Order::getLevel() {
	return m_level;
}

int Order::getNotional() {
	return m_notional;
}

time_t Order::getArriveTime() {
	return m_arriveTime;
}