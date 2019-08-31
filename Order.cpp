#include "Order.h"
#include <iostream>
#include <ctime>

//using namespace std;

Order::Order(std::string ticker,
	std::string cpty,
	int level,
	time_t arriveTime,
	std::string side,
	int notional
	):
	m_ticker(ticker), m_cpty(cpty), m_level(level), m_arriveTime(arriveTime), 
	m_side(side), m_notional(notional){}

void Order::fillOrder(int fillAmount) {
	m_notional = m_notional - fillAmount;
}



void Order::printOrder() const 
	{
	std::cout << "Ticker: " << m_ticker << std::endl;
	std::cout << "OrderID: " << m_id << std::endl;
	std::cout << "Arrival Time: " << m_arriveTime << std::endl;
	}