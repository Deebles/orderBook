#include <iostream>
#include "Order.h"
#include "orderBook.h"
#include <string>
#include <chrono>
#include <vector>

int main()
{
	std::string orderType;
	std::string ticker;
	std::string counterparty;
	std::string side;
	int level;
	int origAmt;
	std::string randFlag;
	std::cout << "Generate random order? y or n:\n";

	const std::vector<std::string> orderTypeList = { "market", "limit" };
	const std::vector<std::string> tickerList = { "XAU/USD", "XAG/USD" };
	const std::vector<std::string> cptyList = { "JPM", "ML", "BAML", "GS", "NOM", "DB" };
	const std::vector<std::string> sideList = { "buy", "sell" };
	std::chrono::high_resolution_clock::time_point timePoint = std::chrono::high_resolution_clock::now();

	OrderBook orderBook("XAU/USD", 10);

	std::cin >> randFlag;
	if (randFlag == "n") {
		std::cout << "Who are you?\n";
		std::cin >> counterparty;
		std::cout << "ticker: \n";
		std::cin >> ticker;
		std::cout << "Level: \n";
		std::cin >> level;
		std::cout << "Side: \n";
		std::cin >> side;
		std::cout << "Amount: \n";
		std::cin >> origAmt;
	}
	else if (randFlag == "y") {
		int numberOfOrders;
		std::cout << "How many orders to you want to generate?" << std::endl;
		std::cin >> numberOfOrders;
		int ID=0;
		bool firstSell = true;
		bool firstBuy = true;
		while (ID < numberOfOrders) {
			//orderType = orderTypeList[std::rand() % (orderTypeList.end() - orderTypeList.begin())];
			orderType = "limit";
			ticker = tickerList[std::rand() % (tickerList.end() - tickerList.begin())];
			counterparty = cptyList[std::rand() % (cptyList.end() - cptyList.begin())];
			side = sideList[std::rand() % (sideList.end() - sideList.begin())];
			origAmt = std::rand() % 10000;
			level=0;
			if (side == "sell")
				//int randNum = rand() % (max - min + 1) + min;
				level = std::rand() % ( orderBook.getMinOffer() - 0 + 1) + orderBook.getMinOffer();
			if (side == "buy")
				level = std::rand() % (100 - orderBook.getMaxBid() + 1 ) + orderBook.getMaxBid();

			time_stamp arriveTime = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
			Order order(orderType, ticker, counterparty, level, arriveTime, side, origAmt);
			//order.printOrder();
			if (order.getOrderType() == "limit") {
				orderBook.addLimitOrder(order);
			}
			else orderBook.addMarketOrder(order);

			ID++;
		}
	}
	orderBook.printOrderBook();

	return 0;
 }