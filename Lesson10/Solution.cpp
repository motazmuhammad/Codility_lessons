/*Algorithm: There is not much to describe this is a direct implementation of the algorithm mentioned in wikipedia here
https://en.wikipedia.org/wiki/Divisor_function

This problem is exactly asking for calculating sigma0 for a number n.

If the limits are a bit less a loop would be suitable. However, since the maximum number is too big. It is preferred to loop only till the sqrt of N

If something is unclear please contact me. I woul really appreciate any input. */

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
const int max_val = 2147438647;
const int max_check = sqrt(max_val);
void sieve(vector<bool>&is_prime,vector<int> &primes,int right_border = max_check)
{
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= right_border; i++)
	{
		if (is_prime[i])
		{
			primes.push_back(i);
			for (int j = i + i; j <= right_border; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
}
int cnt_reps(int n, int divisor)
{
	if (n%divisor != 0) return 0;
	int ret = 0;
	while (n%divisor == 0)
	{
		n /= divisor;
		ret++;
	}
	return ret;
}
long long sigma0(int n,vector<int> & primes)
{
	long long ret = 1;
	for (int i = 0; i < primes.size(); i++)
	{
		if (n%primes[i] == 0)
		{
			auto cnt = 0;
			cnt = cnt_reps(n, primes[i]);
			ret *= (cnt+1);
			for (int j = 0; j < cnt; j++) n /= primes[i];
		}
	}
	if (n != 1)
	{
		ret *= (2);
	}
	return ret;
}
int solution(int N)
{
	vector<bool> is_prime(max_check+1, true);
	vector<int> primes;
	primes.reserve(max_check);
	sieve(is_prime, primes);
	return sigma0(N, primes);


}
