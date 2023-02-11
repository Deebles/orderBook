#include "orderBook.h"
#include <iostream>
#include <algorithm>

OrderBook::OrderBook(
	std::string ticker,
	int tickSize,
	int maxBid,
	int minOffer):
	m_ticker(ticker),
	m_tickSize(tickSize),
	m_maxBid(maxBid),
	m_minOffer(minOffer)
{}

void OrderBook::addCounterparty(Counterparty cpty) {

	m_counterpartyList.push_back(cpty);
}

void OrderBook::addLimitOrder(Order order) {	
	//Add order and sort the stacks by level and ordertime
	if (order.getSide() == "buy") {
		bidStack.push_back(order);
		if (bidStack.size() > 1) {
			bidStack.sort([](Order& order1, Order& order2) {
				if (order1.getLevel() == order2.getLevel())
					return order2.getArriveTime() > order1.getArriveTime();
				return order1.getLevel() > order2.getLevel();
				}
			);
		}
	}
	else if (order.getSide() == "sell") {
		offerStack.push_back(order);
		if (offerStack.size() > 1) {
			offerStack.sort([](Order& order1, Order& order2) {
				if (order1.getLevel() == order2.getLevel())
					return order2 < order1;
				return order1.getLevel() > order2.getLevel();
			});
		}
	}
}

void OrderBook::addMarketOrder(Order order) {
	if (order.getSide() == "buy") {
		for (auto i : offerStack) {
			if (i.getNotional() > order.getNotional()) {
				i.setNotional(i.getNotional() - order.getNotional());
					order.setNotional(0);
			}
			else {
				order.setNotional(order.getNotional() - i.getNotional());
				i.setNotional(0);
			}		
		}
	}
	if (order.getSide() == "sell") {
		for (auto i : bidStack) {
			if (i.getNotional() > order.getNotional()) {
				i.setNotional(i.getNotional() - order.getNotional());
				order.setNotional(0);
			}
			else {
				order.setNotional(order.getNotional() - i.getNotional());
				i.setNotional(0);
			}
		}
	}
}

void OrderBook::printOrderBook() {
	std::cout << "|level|\t|notional|\t|cpty|\t|ID|" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (auto i : offerStack) {
		i.printOrder();
		std::cout << "-----------------------------------------" << std::endl;
	}
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	for (auto i: bidStack) {
		i.printOrder();
		std::cout << "-----------------------------------------" << std::endl;
	}
}

void OrderBook::setMaxBid() {
	if (bidStack.size() > 0)
		m_maxBid = bidStack.back().getLevel();
	else m_maxBid = 1800; //Starting bid
}

void OrderBook::setMinOffer() {
	if (offerStack.size() > 0)
		m_minOffer = offerStack.front().getLevel();
	else m_minOffer = 1705; ///starting offer
}

int OrderBook::getMaxBid() {
	return m_maxBid;
}

int OrderBook::getMinOffer() {
	return m_minOffer;
}

std::list<Order> OrderBook::getBidStack(){
	return bidStack;
}

std::list<Order> OrderBook::getOfferStack() {
	return offerStack;
}
