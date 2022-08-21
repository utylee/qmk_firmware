# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# AutoShift feature
#AUTO_SHIFT_ENABLE = yes

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Virtual DIP switch configuration
#BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
#BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
#MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # USB Nkey Rollover
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
#BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
BLUETOOTH_ENABLE = no       # Enable Bluetooth
#BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
#RGB_MATRIX_ENABLE = yes
#RGB_MATRIX_DRIVER = WS2812

DYNAMIC_TAPPING_TERM_ENABLE = yes # tapping term dynamically change

LAYOUTS = planck_mit
LAYOUTS_HAS_RGB = yes
