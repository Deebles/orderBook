#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "Order.h"
#include "orderBook.h"
#include "Counterparty.h"

int main()
{

	/*list of stuff I want to do
	1. Create an exchange/OrderBook
	2. Main can create counterparties
	3. Orderbook to accept counterparties on this exchange
	4. Counterparties can see Orderbook and
	5. Counterparties can place orders on exchange
	6. Orderbook can accpet orders
	7. Orderbook can fill orders*/

	std::string counterparty;
	const std::vector<std::string> tickerList = { "XAU/USD", "XAG/USD" };
	const std::vector<std::string> cptyList = { "TD", "JPM", "ML", "BAML", "GS", "NOM", "DB" };

	//1. Create an exchange
	OrderBook Gold("XAU/USD", 10);

	//2. Create some counterparties & add them as members to the orderbook
	Counterparty TD("TD");
	Counterparty JPML("JPML");
	
	Gold.addCounterparty(TD);
	Gold.addCounterparty(JPML);

	//int maxBid = Gold.getMaxBid();
	
	
	//TD.placeOrder();

	
	//orderBook.addCounterparty("BAML");
	//orderBook.printOrderBook();

	return 0;
 }