#pragma once

namespace training
{
	template<typename InputIt, typename UnaryPredicate>
	InputIt find_if(InputIt begin, InputIt end, UnaryPredicate pred)
	{
		for(InputIt it=begin;it<end;it++)
		{
			if(pred(*it))
			{
				return it;
			}
		}
		return end;
	}
}

