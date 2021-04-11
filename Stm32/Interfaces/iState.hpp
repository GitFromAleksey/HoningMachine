#ifndef INTERFACES_STATE_HPP_
#define INTERFACES_STATE_HPP_

#include <stdint.h>

typedef enum
{
  eStateFastReturnToOperation  = 1,	// ускоренный возврат в рабочий ход
  eStateFeedEnabled            = 2,	// подача включена
  eStateFeedIsDisabled         = 3,	// подача выключена
  eStateGeneralStop            = 4,	// общий стоп
  eStateHandHeld               = 5,	// ручной
  eStatePositionZero           = 6,	// позиция ноль
  eStateRangeSetting           = 7,	// установка диапазона
  eStateSemenMovement          = 8,	// семенящий
  eStateSlowSpeed              = 9,	// медленная скорость
  eStateWorking                = 10,	// работа
  eStatePushing                = 11	// толчковый
} t_state_identifier;

class iState
{
public:
  virtual ~iState(){}
  virtual void run(void *params) = 0;
  t_state_identifier getStateIdentifier()const { return m_StateIdentifier; }
protected:

  t_state_identifier m_StateIdentifier;
};

#endif /* INTERFACES_STATE_HPP_ */
