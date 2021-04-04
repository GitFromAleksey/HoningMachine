#ifndef INTERFACES_STATE_HPP_
#define INTERFACES_STATE_HPP_

#include <stdint.h>

typedef enum
{
  StateFastReturnToOperation  = 1,	// ускоренный возврат в рабочий ход
  StateFeedEnabled            = 2,	// подача включена
  StateFeedIsDisabled         = 3,	// подача выключена
  StateGeneralStop            = 4,	// общий стоп
  StateHandHeld               = 5,	// ручной
  StatePositionZero           = 6,	// позиция ноль
  StateRangeSetting           = 7,	// установка диапазона
  StateSemenMovement          = 8,	// семенящий
  StateSlowSpeed              = 9,	// медленная скорость
  StateWorking                = 10,	// работа
  StatePushing                = 11	// толчковый
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
