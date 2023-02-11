#pragma once
#include "Order.h"
#include <vector>
#include <string>
#include<list>

#include "Counterparty.h"

class Counterparty;

class OrderBook{
private:
	const std::string m_ticker;
	const int m_tickSize;
	std::list<Order> bidStack;
	std::list<Order> offerStack;
	int m_maxBid;
	int m_minOffer;

	std::vector<Counterparty> m_counterpartyList;

public:
	OrderBook(std::string ticker = "XAU/USD", int tickSize = 5, int maxBid = 0, int minOffer = 100);
	void addCounterparty(Counterparty cpty);
	void addLimitOrder(Order order);
	void addMarketOrder(Order order);
	void printOrderBook();
	void setMaxBid();
	void setMinOffer();
	int getMaxBid();
	int getMinOffer();
	std::list<Order> getBidStack();
	std::list<Order> getOfferStack();
};


