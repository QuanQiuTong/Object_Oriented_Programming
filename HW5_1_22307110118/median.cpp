// Function templates should be in header files,
// thus this file is empty. 

/*

// source file for the 'median' function
#include <algorithm>    // to get the declaration of 'sort'
#include <stdexcept>    // to get the declaration of 'domain_error'
#include <vector>       // to get the declaration of 'vector'

using std::domain_error;  
using std::sort;
using std::vector;

// compute the median of a 'vector<double>'
// note that calling this function copies the entire argument 'vector'
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size/2;

	return size % 2 == 0 ? (vec[mid] + vec[mid-1]) / 2 : vec[mid];
}

*/

// For test.
#if 0
#include "median.h"
#include <cstdio>
int main(){
	int a[9]={1,9,2,8,3,7,4,6,5};
	std::vector v={1,9,2,8,3,7,4,6,5};
	printf("%d %d",median(a,a+9),median(v.begin(),v.end()));
}
#endif