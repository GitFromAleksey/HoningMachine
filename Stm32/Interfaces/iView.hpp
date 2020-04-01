#ifndef INTERFACES_IVIEW_HPP_
#define INTERFACES_IVIEW_HPP_

#include <stdint.h>

class iView
{
public:

	virtual void SendCurrentPosition(uint32_t position) = 0;

};

#endif /* INTERFACES_IVIEW_HPP_ */
