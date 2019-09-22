#ifndef __K_SB_RANDOM_UTIL__
#define __K_SB_RANDOM_UTIL__

#include <xNet/sb_define.h>
#include <boost/random.hpp>
#include <ctime>

namespace rand_helper {

	static int g_rand_idx = 0;
	static int gen_probability_number(int32 min, int32 max)
	{
		boost::random::mt19937 rng{ static_cast<uint32>(::time(0)+(++g_rand_idx)) };
		boost::random::uniform_int_distribution<> range(min, max);
		boost::variate_generator<boost::random::mt19937, boost::random::uniform_int_distribution<>> RANDOM(rng, range);

		return RANDOM();

		/*boost::random::mt19937 rng;
		boost::random::uniform_int_distribution<> range(min, max);
		return range(rng);*/
	}

}
#endif