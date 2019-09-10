#include <iostream>
#include "Order.h"
#include "orderBook.h"
#include <string>
#include <chrono>
#include <vector>

int main()
{
	std::string ticker;
	std::string counterparty;
	std::string side;
	int level;
	int origAmt;
	std::string randFlag;
	std::cout << "Generate random order? y or n:\n";

	const std::vector<std::string> tickerList = { "XAU/USD", "XAG/USD" };
	const std::vector<std::string> cptyList = { "JPM", "ML", "BAML", "GS", "NOM", "DB" };
	const std::vector<std::string> sideList = { "buy", "sell" };

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
		ticker = tickerList[std::rand() % (tickerList.end() - tickerList.begin())];
		counterparty = cptyList[std::rand() % (cptyList.end() - cptyList.begin())];
		side = sideList[std::rand() % (sideList.end() - sideList.begin())];
		origAmt = std::rand();
		level = std::rand();

	}

	std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
	time_t arriveTime = std::chrono::system_clock::to_time_t(timePoint);

	Order testOrder(ticker, counterparty, level, arriveTime, side, origAmt);

	OrderBook orderBook("XAU/USD", 10);

	orderBook.addOrder( &testOrder);

	orderBook.printOrderBook();

	return 0;
 }