#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {

		List<Product> priceList;
		// TODO: Add your e_val here to build a list of products
		//         using raw pointers
		bool P_FOUND{ false };
		for (size_t L{ 0ul }; L < desc.size(); L++) 
		{
			for (size_t N{ 0ul }; N < price.size() && !P_FOUND; N++) 
			{
				if (desc[L].e_val == price[N].e_val) 
				{
					P_FOUND = true;
					
					Product* T{ new Product(desc[L].desc,
							
						price[N].price) };
					try
					{
						T->validate();
					}
					catch (const std::string & msg) {
						Product::Trace = false;
						delete T;
						Product::Trace = true;
						throw;
					}
					priceList += T;
					delete T;
				}
			}
			P_FOUND = false;
		}
		return priceList;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your e_val here to build a list of products
		// 		using smart pointers
		bool P_FOUND{ false };
		for (size_t L{ 0ul }; L < desc.size(); L++) 
		{
			for (size_t N{ 0ul }; N < price.size() && !P_FOUND; N++) 
			{
				if (desc[L].e_val == price[N].e_val) 
				{
					P_FOUND = true;
					std::unique_ptr<Product>
					 T(new Product(desc[L].desc,
						 price[N].price));
					T->validate(); 
					priceList += T;
				}
			}
			P_FOUND = false;
		}
		return priceList;
	}
}
