#pragma once
#include <vector>
#include <string>
#include "Order.h"
#include "orderBook.h"

class Orderbook;

class Counterparty
{
private:
	std::string m_name;
	std::vector<std::string> m_transactionLog;
	void placeOrder(int orderLevel, OrderBook book);

public:
	Counterparty(std::string cptName);
	std::string getName();
};

