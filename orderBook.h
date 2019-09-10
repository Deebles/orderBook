#pragma once
#include "Order.h"
#include <list>
#include <string>

class OrderBook{
private:
	const std::string m_ticker;
	const int m_tickSize;
	std::list<Order*> bidStack;
	std::list<Order*> offerStack;

public:
	OrderBook(std::string ticker = "LMAHDS03", int tickSize = 5);
	void addOrder(Order * Order);
	// void assignOrderID(); Should I assign this when the order is instantiated?
	//void fillOrder();
	void printOrderBook();
};

