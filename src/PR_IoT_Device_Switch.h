#ifndef PR_IoT_Device_Switch_h
#define PR_IoT_Device_Switch_h

    #include <arduino.h>
    #include <PR_IoT.h>

	#include "PR_Button.h"
	
class PR_IoT_Switch : public PR_IoT_DeviceClass {
        public:
            PR_IoT_Switch(String name) : PR_IoT_DeviceClass(name) { btn = new PR_ButtonClass; } //
            ~PR_IoT_Switch()					{ delete btn; btn = NULL;		}
            void 	announce();
            void 	update();
            virtual void 	inMsgCallback(); 
            virtual void 	setupHW(uint8_t pin, bool onValue, bool enablePull);
			
			virtual void	loopHW()			{ btn->loop();					}	

			void		setupHWIntervals(uint16_t clickInterval, uint16_t dblClickInterval, uint16_t longPressInterval);
			
			bool		isPressed()				{ return btn->isPressed(); 		}  
			bool		isLongPressed()			{ return btn->isLongPressed(); 	}
			bool		isOnClick()				{ return btn->isOnClick(); 		}
			bool		isOnDblClick()			{ return btn->isOnDblClick(); 	}
			bool 		isOnFall()				{ return btn->isOnFall(); 		}
			bool 		isOnRise()				{ return btn->isOnRise(); 		}
			bool 		isOnLongPressed()		{ return btn->isOnLongPressed(); }
        protected:
			PR_ButtonClass	*btn;
    };
	
#endif