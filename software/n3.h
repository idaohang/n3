/**
 * Definitions of key constants used by the N3 firmware.
 */

#ifndef N3_H
#define N3_H

#define N3_VERSION_STR "0.1"

// -----------------------------------------------------------------------------
// Software params
// -----------------------------------------------------------------------------

// How frequently should the UI be refreshed in the worst case? (msec)
#define N3_UI_UPDATE_PERIOD 1100

// How long should the button be pressed to count as a long press (msec)
#define N3_BTN_LONG_PRESS_DURATION 500ul

// How long should the splash be shown for each window? (msec)
#define N3_SPLASH_DURATION 2000ul

// For windows with several pages to show, how long should each page be shown?
#define N3_PAGE_DURATION 3000ul

// What is the minimum threshold for a HDOP value to be considered "excellent"?
#define N3_GPS_EXCELLENT_HDOP 2.0

// -----------------------------------------------------------------------------
// Pins and device definitions
// -----------------------------------------------------------------------------

// Serial port used to communicate with the GPS receiver
#define N3_GPS_BAUDRATE       57600
#define n3_gps_serial         Serial2
#define N3_GPS_SERIAL_DMA_SRC DMA_REQ_SRC_USART2_RX

// LCD Display
#define N3_LCD_RS_PIN     15
#define N3_LCD_RW_PIN     16
#define N3_LCD_ENABLE_PIN 17
#define N3_LCD_D4_PIN     18
#define N3_LCD_D5_PIN     19
#define N3_LCD_D6_PIN     20
#define N3_LCD_D7_PIN     21

#define N3_LCD_COLS 8
#define N3_LCD_ROWS 2

// System voltage
#define N3_UC_VOLTAGE 3.3

// Battery voltage input
#define N3_BAT_V_PIN 3
#define N3_BAT_V_DIV_R1 2200.0
#define N3_BAT_V_DIV_R2 3300.0

// In practice the system will "happily" run down to about 1.5v but since the
// battery voltage curve gets steep at about 2v (1v each) this seems like a good
// time to say "empty" for safety purposes.
#define N3_BAT_MIN_V 2.0

// A fresh set of batteries should be around 3.6 but they quickly drop from this
// before entering a more linear discharge period so it makes sense to keep this
// slightly lower than you'd expect.
#define N3_BAT_MAX_V 2.85

// Button
#define N3_BTN_PIN 10

#endif
