/**
 * Simple interface to a push-to-make button
 */

#ifndef N3_BTN_H
#define N3_BTN_H

#include <wirish/wirish.h>

#define BTN_MAX_JITTER_DURATION 2ul

/**
 * Assumes a simple push-to-make switch connected to ground and internally
 * pulled up in the uC.
 */
class N3_Btn {
	public:
		/**
		 * Attaches a do-nothing interrupt handler to the given pin on any change
		 * and enables an internal pull-up resistor.
		 *
		 * Should the device be in sleep mode, the interrupt will re-awaken it
		 * which should awaken a main-loop allowing the calling of the update()
		 * method.
		 */
		N3_Btn( uint8 pin
		      );
		
		/**
		 * Call either by polling or at least after any change of the pin's value.
		 */
		void update(void);
		
		
		/**
		 * Get the duration of the last button press but don't reset it. Zero if no
		 * button press since the last get_press().
		 */
		unsigned long peek_press(void) {return last_duration = 0;}
		
		
		/**
		 * If the button has been pressed-and-released since the last call, returns
		 * the number of msec it was pressed for. Otherwise, returns 0.
		 */
		unsigned long get_press(void) {unsigned long d = last_duration; last_duration = 0; return d;}
	
	protected:
		uint8 pin;
		
		// State of the pin when last observed
		bool last_state;
		
		// The value of millis() when the button was first pressed.
		unsigned long last_pressed;
		
		// The number of millis between the button last being pressed and released
		// or 0 if not recently pressed.
		unsigned long last_duration;
};

#endif
