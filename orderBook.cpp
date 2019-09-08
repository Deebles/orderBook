#include "orderBook.h"
#include "Order.h"
#include <iostream>

OrderBook::OrderBook(
	std::string ticker,
	int tickSize):
	m_ticker(ticker),
	m_tickSize(tickSize){}

void OrderBook::addOrder(Order * order) {

	if (order -> getSide() == "buy") {
		bidStack.push_back(order);
		if (bidStack.size() > 1) {
			bidStack.sort();
		}		
	}
	else if (order -> getSide() == "sell") {
		offerStack.push_back(order);
		if (offerStack.size() > 1) {
			offerStack.sort();
		}		
	}
}

void OrderBook::printOrderBook() {
	std::cout << "|level|\t|notional|\t|cpty|\t|ID|" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (auto const i : bidStack) {
		i -> printOrder();
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (auto const & i: offerStack) {
		std::cout << i -> getLevel() << std::endl;
	}
}




