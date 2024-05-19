#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include "order.h"
#include "orderbook.h"
#include "counterparty.h"

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

	std::string xau = tickerList[0];

	//1. Create an order book. There is one order book per contract.
	auto ob = std::make_shared<OrderBook> ();

	//2. Create some counterparties & add them as members to the orderbook
	Counterparty TD("TD");
	Counterparty JPML("JPML");
	
	ob->addCounterparty(TD);
	ob->addCounterparty(JPML);

	auto GoldBook = OrderBook();
	
	GoldBook.addCounterparty(TD);

	auto anOrder = Order(TD, "limit", "XAU/USD", 1800, "Buy", 100);

	GoldBook.addLimitOrder(anOrder);

	return 0;
 }