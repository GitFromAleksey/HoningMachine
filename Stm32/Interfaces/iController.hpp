#ifndef INTERFACES_ICONTROLLER_HPP_
#define INTERFACES_ICONTROLLER_HPP_

class iController
{
public:
	
	virtual void MachinePowerOn() = 0;
	virtual void MachinePowerOff() = 0;
	virtual void VerticalFeedMotorOn() = 0;
	virtual void VerticalFeedMotorOff() = 0;
	virtual void ToolLiftUp() = 0;
	virtual void ToolLiftDown() = 0;
	virtual void ToolLiftStop() = 0;
	virtual void ToolRotateRun() = 0;
	virtual void ToolRotateStop() = 0;
	virtual void ToolStop() = 0;

};

#endif /* INTERFACES_ICONTROLLER_HPP_ */
