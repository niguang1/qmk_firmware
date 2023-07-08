#include QMK_KEYBOARD_H

#include "qp.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-------------------------------------------------.
 * | KC_MPLY |                             | KC_MSTP |
 * ,-------------------------------------------------.
 * |    /    |  KC_7   |  KC_8   |  KC_9   |         |
 * |---------------------------------------- KC_PLUS |
 * |    *    |  KC_4   |  KC_5   |  KC_6   |         |
 * |-------------------------------------------------|
 * |    -    |  KC_1   |  KC_2   |  KC_3   |         |
 * |---------------------------------------- KC_ENT  |
 * | FN/DEL  |        KC_0       |  KC_DOT |         |
 * `-------------------------------------------------'
 */
[0] = LAYOUT(
  KC_MPLY,                                  KC_MSTP,
  KC_SLSH,  KC_7,       KC_8,      KC_9,    
  KC_ASTR,  KC_4,       KC_5,      KC_6,    KC_PLUS,
  KC_MINS,  KC_1,       KC_2,      KC_3,    
  LT(1, KC_DEL),       KC_0,      KC_DOT,    KC_ENT
),

/* LAYER 1
 * ,-------------------------------------------------.
 * | QK_BOOT |                             | KC_MSTP |
 * ,-------------------------------------------------.
 * |    /    |  KC_7   |  KC_8   |  KC_9   |         |
 * |---------------------------------------- KC_PLUS |
 * |    *    | KC_BTN1 |    ↑    | KC_BTN2 |         |
 * |-------------------------------------------------|
 * |    -    |    ←    |    ↓    |    →    |         |
 * |---------------------------------------- KC_ENT  |
 * | FN/DEL |        KC_0       |  KC_DOT |         |
 * `-------------------------------------------------'
 */
[1] = LAYOUT(
  KC_MPLY,                                KC_MSTP,
  KC_SLSH,  KC_7,     KC_8,     KC_9,     
  KC_ASTR,  KC_BTN1,  KC_MS_U,  KC_BTN2,  KC_PLUS,
  KC_MINS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  
  LT(1, KC_DEL),    KC_0,       KC_DOT,   KC_ENTER
)

};

painter_device_t lcd;

void keyboard_post_init_user(void) {
    lcd = qp_st7735_make_spi_device(80, 160, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 8, 0);
    qp_init(lcd, QP_ROTATION_180);
    // qp_set_viewport_offsets (lcd, 25, 0);

    // lcd = qp_st7735_make_spi_device(160, 80, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 16, 0);
    // qp_init(lcd, QP_ROTATION_0);
    // qp_rect(lcd, 0, 0, 20, 20, 0, 255, 255, true);
    // qp_rect(lcd, 60, 0, 80, 20, 0, 255, 255, true);
    // qp_rect(lcd, 140, 0, 160, 20, 0, 255, 255, true);

    // qp_rect(lcd, 0, 40, 20, 60, 0, 255, 255, true);
    // qp_rect(lcd, 60, 40, 80, 60, 0, 255, 255, true);
    // qp_rect(lcd, 140, 40, 160, 60, 0, 255, 255, true);

    // if (qp_lvgl_attach(lcd)) {
    //     lv_example_arc_2();
    // }
}

//层切换处理
// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _RAISE:
//         rgblight_setrgb (0x00,  0x00, 0xFF);
//         break;
//     case _LOWER:
//         rgblight_setrgb (0xFF,  0x00, 0x00);
//         break;
//     case _PLOVER:
//         rgblight_setrgb (0x00,  0xFF, 0x00);
//         break;
//     case _ADJUST:
//         rgblight_setrgb (0x7A,  0x00, 0xFF);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_setrgb (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }




#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_logo();
    return false;
}
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }else if(index == 1)
    {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    
    return true;
}


void matrix_init_user(void) {  }

#ifdef RGB_MATRIX_ENABLE
// led_config_t g_led_config = { {
//     { 1, NO_LED, NO_LED, NO_LED, 0     },
// 	{ 2, 3,  4,  5,  NO_LED },
// 	{ 10, 9,  8,  7,  6  },
// 	{ 11, 12,  13,  14,  NO_LED },
// 	{ 18, 17,  NO_LED, 16,  15  }
// }, {
//     {0  ,  0}, {75 ,  0}, {149,  0}, {224,  0},
//     {0  , 21}, {75 , 21}, {149, 21}, {224, 21},
//     {0  , 43}, {75 , 43}, {149, 43}, {224, 43},
//     {0  , 64}, {75 , 64}, {149, 64}, {224, 64},
// }, {
//     4, 4,
//     4, 4, 4, 4,
//     4, 4, 4, 4, 4,
//     4, 4, 4, 4,
//     4, 4, 4, 4,
// } };
led_config_t g_led_config = { {
    { 1, NO_LED, NO_LED, NO_LED, NO_LED     },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED  },
	{ NO_LED, NO_LED,  NO_LED,  NO_LED,  NO_LED },
	{ NO_LED, NO_LED,  NO_LED, NO_LED,  NO_LED  }
}, {
    {0  ,  0}
}, {
    1
} };
#endif