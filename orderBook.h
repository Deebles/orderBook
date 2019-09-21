#pragma once
#include "Order.h"
#include <list>
#include <string>

class OrderBook{
private:
	const std::string m_ticker;
	const int m_tickSize;
	std::list<Order> bidStack;
	std::list<Order> offerStack;

public:
	OrderBook(std::string ticker = "XAU/USD", int tickSize = 5);
	void addOrder(Order order);
	//void fillOrder();
	void printOrderBook();
};

