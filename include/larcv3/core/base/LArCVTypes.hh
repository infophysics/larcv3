/**
 * \file LArCVTypes.h
 * \ingroup core_Base
 * \brief basic typedefs and enums (larcv3::Point2D, larcv3::msg, etc.)
 * @author Kazu - Nevis 2015
 */

#pragma once

#include <string>
#include <utility>
#include <vector>
#include <limits>
#include <climits>
#include <vector>
#include <limits>
#include <climits>

/** @addtogroup core_Base
 * @{
 */
/**
 * @namespace larcv3 C++ namespace for developping LArTPC 
 * software interface to computer vision software (LArCV3)
 */
namespace larcv3 
{	
	/// kINVALID_<TYPE> with various c++ types set to the
	///	largest value for the corresponding type.
	const long long     kINVALID_LONGLONG  = std::numeric_limits<long long>::max();
	const size_t        kINVALID_SIZE      = std::numeric_limits<size_t>::max();
	const int           kINVALID_INT       = std::numeric_limits<int>::max();
	const unsigned int	kINVALID_UINT      = std::numeric_limits<unsigned int>::max();
	const short         kINVALID_SHORT     = std::numeric_limits<short>::max();
	const float         kINVALID_FLOAT     = std::numeric_limits<float>::max();
	const double        kINVALID_DOUBLE    = std::numeric_limits<double>::max();
	const long          kINVALID_LONG      = std::numeric_limits<long>::max();
	const unsigned short	 kINVALID_USHORT    = 
		std::numeric_limits<unsigned short>::max();
	const unsigned long long kINVALID_ULONGLONG = 
		std::numeric_limits<unsigned long long>::max();

	/// Namespace for larcv3 message related types
	namespace msg {

		/// Message level
		enum Level_t 
		{ 
			kDEBUG, 
			kINFO, 
			kNORMAL, 
			kWARNING, 
			kERROR, 
			kCRITICAL, 
			kMSG_TYPE_MAX 
		};

		/// Formatted message prefix per message level
		const std::string kStringPrefix[kMSG_TYPE_MAX] =
		{
			"     \033[94m[DEBUG]\033[00m ",  	///< kDEBUG message prefix
			"      \033[92m[INFO]\033[00m ",  	///< kINFO message prefix
			"    \033[95m[NORMAL]\033[00m ",	///< kNORMAL message prefix
			"   \033[93m[WARNING]\033[00m ", 	///< kWARNING message prefix
			"     \033[91m[ERROR]\033[00m ", 	///< kERROR message prefix
			"  \033[5;1;33;41m[CRITICAL]\033[00m "	///< kCRITICAL message prefix
		};
		///< Prefix of message
  	}	
}
/** @} */ // end of doxygen group