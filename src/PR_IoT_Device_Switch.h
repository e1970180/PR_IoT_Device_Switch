#ifndef PR_IoT_Device_Switch_h
#define PR_IoT_Device_Switch_h

    #include <arduino.h>
    #include <PR_IoT.h>

	#include "PR_Button.h"
	
class PR_IoT_Switch : public PR_IoT_DeviceClass {
        public:
            PR_IoT_Switch(String name) : PR_IoT_DeviceClass(name) { btn = new PR_ButtonClass; } //
            
            void 	announce();
            void 	update();
            virtual void 	inMsgCallback(); 
            virtual void 	setupHW(uint8_t pin, bool onValue, bool enablePull);   
			virtual void	loopHW();	

			bool		isPressed()		{ return btn->isPressed(); 		}  
			bool		isLongPressed()	{ return btn->isLongPressed(); 	}
			bool		isOnClick()		{ return btn->isOnClick(); 		}
			bool		isOnDblClick()	{ return btn->isOnDblClick(); 	}
			bool 		isFell()		{ return btn->isFell(); 		}
			bool 		isRose()		{ return btn->isRose(); 		}			
        protected:
			PR_ButtonClass	*btn;
    };
	
#endif