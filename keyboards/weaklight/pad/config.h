
#pragma once

#define MATRIX_ROWS 5
#define MATRIX_COLS 5

#define TAPPING_TERM 200


#define MOUSEKEY_INTERVAL 20
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

//todo fxsh 不知道是啥
#define BACKLIGHT_PIN B7
#define BACKLIGHT_LEVELS 1

/* ws2812 RGB LED */
#define WS2812_DI_PIN B15

#define RGBLED_NUM 1    // Number of LEDs

// The number of LEDs connected
#define RGB_MATRIX_LED_COUNT 1

/* RGB key status */
#define RGBLIGHT_LAYERS

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE



#define WS2812_PWM_DRIVER PWMD1
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_DMA_STREAM STM32_DMA1_STREAM6
#define WS2812_DMA_CHANNEL 6
#define WS2812_PWM_COMPLEMENTARY_OUTPUT

/* spi config for ST7735 */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          A5   //SCL
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         A7   //SDA
#define SPI_MOSI_PAL_MODE                    5

/* LCD Configuration */
#define LCD_RST_PIN D2   //RES
#define LCD_DC_PIN B5      //RS
#define LCD_CS_PIN A4       