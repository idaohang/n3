#include <wirish/wirish.h>
#include <LiquidCrystal/LiquidCrystal.h>

#include "n3_ui_about.h"

#include "n3.h"
#include "n3_ui.h"
#include "n3_globals.h"

#define NUM_PAGES 3

void
N3_UI_About_Window::focus(void)
{
	n3_lcd.clear();
	page_num = 0;
	last_change = 0ul;
}


void
N3_UI_About_Window::update(void)
{
	// Advance the pages
	if (millis() - last_change > N3_PAGE_DURATION) {
		page_num += 1;
		page_num %= NUM_PAGES;
		last_change = millis();
		
		switch (page_num) {
			default:
			case 0:
				//            |-----|
				n3_lcd.print("N3 " N3_VERSION_STR); n3_lcd.setCursor(0,1);
				n3_lcd.print("(C) JDH");
				break;
			
			case 1:
				//            |-----|
				n3_lcd.print("  For  "); n3_lcd.setCursor(0,1);
				n3_lcd.print("R H'cte");
				break;
			
			case 2:
				//            |-----|
				n3_lcd.print("A Great"); n3_lcd.setCursor(0,1);
				n3_lcd.print("  Dad  ");
				break;
		}
	}
}


// TODO: Add Icon
uint8 XXX_NULL_ICON[8] = {1};

uint8 *
N3_UI_About_Window::get_splash_icon(int char_num)
{
	return XXX_NULL_ICON;
}

static const char *SPLASH_TOP = "About";
static const char *SPLASH_BTM = " N3  ";

const char *
N3_UI_About_Window::get_splash_text(int line_no)
{
	switch (line_no) {
		default:
		case 0: return SPLASH_TOP; break;
		case 1: return SPLASH_BTM; break;
	}
}

