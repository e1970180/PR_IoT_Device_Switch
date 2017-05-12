#include "PR_IoT_Device_Switch.h"

    #include <arduino.h>    

	void 	PR_IoT_Switch::announce() {
		postMsg("switch", "HELLO"); 
	}
	
	void 	PR_IoT_Switch::setupHW(uint8_t pin, bool onValue, bool enablePull) {
		
		btn->setup(pin, onValue, enablePull);
	}   
	
	void	PR_IoT_Switch::loopHW() {
		btn->loop();
	}	
			
			
	void	PR_IoT_Switch::update() {
	
		if ( btn->isOnClick() )		postMsg ("switch", "onclick" );
		if ( btn->isOnDblClick() )	postMsg ("switch", "ondblclick" );
		if ( btn->isFell() )		postMsg ("switch", "onfell" );
		if ( btn->isRose() )		postMsg ("switch", "onrose" );
	
	}
	
	void	PR_IoT_Switch::inMsgCallback() {

		PR_DBGTLN("Swithc: Msg got")
		PR_DBGVLN(inMsg.payload)
		
		if (inMsg.payload == "ASK")	{
			String s;
			if ( btn->isPressed() ) s = "YES"; else s = "NO";
			postMsg ("pressed", s );
			
			if ( btn->isLongPressed() ) s = "YES"; else s = "NO";
			postMsg ("longpressed", s);
		}
	}
	
