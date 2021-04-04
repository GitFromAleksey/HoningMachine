#ifndef INTERFACES_IVIEW_HPP_
#define INTERFACES_IVIEW_HPP_

#include <stdint.h>

class iView
{
public:

	virtual void SendCurrentPosition(uint32_t data)   = 0;
	virtual void SendCurrent(uint32_t data)           = 0;
	virtual void SendUpperToolTipState(uint32_t data) = 0;
	virtual void SendLowerToolTipState(uint32_t data) = 0;
  virtual void SendStateOfWork(uint32_t data)       = 0;
};

#endif /* INTERFACES_IVIEW_HPP_ */
