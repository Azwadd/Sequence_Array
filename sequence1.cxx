#include <iostream>
#include <cassert>
#include "sequence1.h"
using namespace std;

namespace weimin_csc212
{
	//   void insert(const value_type& entry)
	//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence
	//     before the current item. If there was no current item, then the new entry 
	//     has been inserted at the front of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.
	void sequence1::insert(const value_type& entry)
	{
		assert(size() < CAPACITY);
			if (!is_item()) { c = 0; } 
			for (size_type i = u; i > c; i--)
			{
				data[i] = data[i-1];
			} 
			data[c] = entry;				
			++u;
	}

	//   void attach(const value_type& entry)
	//     Precondition: size( ) < CAPACITY.
	//     Postcondition: A new copy of entry has been inserted in the sequence after
	//     the current item. If there was no current item, then the new entry has 
	//     been attached to the end of the sequence. In either case, the newly
	//     inserted item is now the current item of the sequence.
	void sequence1::attach(const value_type& entry)
	{
		assert(size() < CAPACITY);
			if (!is_item())
			{
				c = u;
				data[c] = entry;
			}
			else
			{
				for (size_type i = u; i > c + 1; i--)
				{
					data[i] = data[i - 1];
				}
				data[++c] = entry;

			}
			++u;
	}

	//   void remove_current( )
	//     Precondition: is_item returns true.
	//     Postcondition: The current item has been removed from the sequence, and the
	//     item after this (if there is one) is now the new current item.
	void sequence1::remove_current() 
	{
		for (size_type i = c; i < u; i++)
		{
			data[i] = data[i + 1];
		}
		--u;
	}
}