#include <iostream>
#include "Order.h"
#include "orderBook.h"
#include<string>
#include <chrono>
int main()
{
	std::string ticker;
	std::string counterparty;
	std::string side;
	int level;
	int origAmt;
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
	std::chrono::system_clock::time_point timePoint = std::chrono::system_clock::now();
	
	time_t arriveTime = std::chrono::system_clock::to_time_t(timePoint);

	Order testOrder(ticker, counterparty, level, arriveTime, side, origAmt);
	
	testOrder.printOrder();

	OrderBook orderBook("LMCADS03", 10);

	orderBook.addOrder( &testOrder);

	orderBook.printOrderBook();

	return 0;
 }