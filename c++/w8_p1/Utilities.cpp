//Rushi Patel
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include <memory> 
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {

	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		
		bool pair{ false }; 

		for (size_t x{ 0ul }; x < desc.size(); x++) 
		{
			for (size_t y{ 0ul }; y < price.size() && !pair; y++) 
			{
				if (desc[x].code == price[y].code) 
				{
					pair = true;
					
					Product* T{ new Product(desc[x].desc,
							price[y].price) };
					try  
					{
						T->validate();   
					}
					catch (const std::string & msg) 
					{
						Product::Trace = false;    
						delete T;   						
						Product::Trace = true;   						
						throw; 
					}
					
					priceList += T;   
					delete T;   
				}
			}			
			pair = false;   
		}

		return priceList;   
	}
}