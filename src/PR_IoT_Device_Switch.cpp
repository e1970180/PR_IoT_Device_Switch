#include "PR_IoT_Device_Switch.h"

    #include <arduino.h>    

	void 	PR_IoT_Switch::announce() {
		postMsg("switch", "HELLO"); 
	}
	
	void 	PR_IoT_Switch::setupHW(uint8_t pin, bool onValue, bool enablePull) {
		
		btn->setup(pin, onValue, enablePull);
	}   
	
	void	PR_IoT_Switch::setupHWIntervals(uint16_t clickInterval, uint16_t dblClickInterval, uint16_t longPressInterval) {
		
		btn->setupIntervals(clickInterval, dblClickInterval, longPressInterval);
	}	
			
	void	PR_IoT_Switch::update() {
		if ( btn->isOnRise() )			postMsg ("switch", "onrise" );	
		if ( btn->isOnClick() )			postMsg ("switch", "onclick" );
		if ( btn->isOnDblClick() )		postMsg ("switch", "ondblclick" );
		if ( btn->isOnFall() )			postMsg ("switch", "onfall" );
		if ( btn->isOnLongPressed() )	postMsg ("switch", "onlongpressed" );

	
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
	
