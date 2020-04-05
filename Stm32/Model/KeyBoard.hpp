#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <stdint.h>
#include <stddef.h>
#include "../Interfaces/iProcess.hpp"
#include "../Interfaces/iController.hpp"

class cKeyBoard : public iProcess
{
	public:
		cKeyBoard();
		~cKeyBoard();
	
		virtual void run();
	
	private:
		
	
};


#endif /* KEYBOARD_HPP_ */
