#include "Order.h"
#include <iostream>

LimitOrder::LimitOrder(
	std::string orderType,
	std::string ticker,
	std::string cpty,
	time_t arriveTime,
	std::string side,
	int notional,
	int level):
	m_level(level){}

void LimitOrder::printOrder()
{
	std::cout << m_orderType << "\t" << m_ticker << "\t" << m_cpty << "\t";
	std::cout << m_arriveTime << "\t" << m_side << "\t" << m_notional << std::endl;
}