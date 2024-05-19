#pragma once
#include <vector>
#include <string>

#include "order.h"
#include "orderBook.h"

class OrderBook;

class Counterparty
{
private:
	std::string m_name;
	std::vector<std::string> m_transactionLog;
	void placeOrder(int orderLevel, OrderBook* book);

public:
	Counterparty(const std::string& cptName);
	std::string getName();
};

