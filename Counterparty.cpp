#include <chrono>
#include <iostream>
#include "Counterparty.h"

Counterparty::Counterparty(std::string name):m_name(name) {}

void Counterparty::placeOrder(int orderLevel, OrderBook book) {

		std::string side;
		int origAmt;
		int level=orderLevel;
		std::string orderType;
		std::string ticker;
		std::string name;

		const std::vector<std::string> orderTypeList = { "market", "limit" };
		const std::vector<std::string> sideList = { "buy", "sell" };
		std::chrono::high_resolution_clock::time_point timePoint = std::chrono::high_resolution_clock::now();

		side = sideList[std::rand() % (sideList.end() - sideList.begin())];
		origAmt = std::rand() % 10000;

		//level = 0;
		//if (side == "sell")
		//	level = std::rand() /*% (orderBook.getMinOffer() + 1) + orderBook.getMinOffer()*/;
		//if (side == "buy")
		//	level = std::rand() /*% (100 - OrderBook::getMaxBid() + 1) + OrderBook::getMaxBid()*/;

		time_stamp arriveTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
		Order order(orderType, ticker, name, level, arriveTime, side, origAmt);
//		orderBook->addLimitOrder(order);
		
		//orderNum++;

	}

//}

std::string Counterparty::getName() {
	return m_name;
}
