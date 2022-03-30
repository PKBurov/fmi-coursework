#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <algorithm>
#include <cassert>
#include <set>


constexpr size_t BitSetSize = 32U;
using namespace std;

void nextCombination(std::bitset<BitSetSize>& bits, const std::vector<size_t>& indices) {

	for (size_t i{}; i < indices.size(); ++i) {

		// Get the current index, and check, if it is valid
		const size_t pos = indices[i];
		if ( pos < BitSetSize) {

			// Flip bit at lowest positions
			bits[pos].flip();

			// If there is no transition of the just flipped bit, then stop
			// If there is a transition from high to low, then we need to flip the next bit
			if (bits.test(pos))
				break;
		}
	}
}

// Some driver code
int main() {
	// Use any kind of mechanism to indicate which index should be changed or not
	set<int> Unique;
	int n = 0;
	int input = 0;
	std::cin >> n;

	for (int i = 0; i < n; i++){
		std::cin >> input;

		std::string mask = std::bitset< 64 >(input).to_string();
		// Here, we will store the indices
		std::vector<size_t> index{};
		// Populated the indices vector from the string
		std::for_each(mask.crbegin(), mask.crend(), [&, i = 0U](const char c) mutable {if ('1' == c) index.push_back(i); ++i; });

		// The bitset, for which we want to calculate the combinations
		std::bitset<BitSetSize> bits(0);

		// Play around
		for (size_t combination{}; combination < (1 << (index.size())); ++combination) {

			// This is the do something
			long long u;
			u = (long long)(bits.to_ullong());
			Unique.insert(u);
			
			//cout<<bits.to_string() <<"\n";

			// calculate the next permutation
			nextCombination(bits, index);
		}
	}
	cout << Unique.size();

	
	return 0;
}