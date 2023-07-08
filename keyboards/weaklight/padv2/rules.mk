

MCU = STM32F103

BOOTLOADER = stm32duino

# Build Options
#   change yes to no to disable
#
COMMAND_ENABLE = no        # Commands for debug and configuration
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
UNICODE_ENABLE = yes         # Unicode

RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
RGB_MATRIX_DRIVER = WS2812
# WS2812_DRIVER = pwm

ENCODER_ENABLE = yes

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7735_spi
