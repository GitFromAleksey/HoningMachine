#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"
#include "array.hpp"
#include "DigitalInput.hpp"

class cKeyBoard : public iProcess
{
  public:
    cKeyBoard();
    ~cKeyBoard();

    virtual void run();

    void AddKey(cDigitalInput *key);
  
  private:
    cArray<cDigitalInput> m_KeysArray;

};


#endif /* KEYBOARD_HPP_ */
