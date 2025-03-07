// Copyright 2023 Massdrop, Inc.
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define ADC_BUFFER_DEPTH 4
#define ADC_SAMPLING_RATE ADC_SMPR_SMP_601P5
#define ADC_RESOLUTION ADC_CFGR_RES_12BITS

#define I2C_DRIVER I2CD2
#define I2C1_SCL_PIN A9
#define I2C1_SDA_PIN A10

#define EXTERNAL_EEPROM_I2C_BASE_ADDRESS 0b10101000
#define EXTERNAL_EEPROM_WP_PIN B5
#define EEPROM_I2C_24LC256

#define IS31FL3733_I2C_ADDRESS_1 IS31FL3733_I2C_ADDRESS_GND_VCC
#define IS31FL3733_I2C_ADDRESS_2 IS31FL3733_I2C_ADDRESS_VCC_VCC
#define IS31FL3733_PWM_FREQUENCY IS31FL3733_PWM_FREQUENCY_26K7_HZ

#define RGB_MATRIX_CYCLE_ZONES_ENABLE
#define RGB_MATRIX_CAPS_LOCK_INDEX 30

// Mainly for the left ctrl that now also serves as kc_grv
// And left/right shift that now also serves as paranthesis
#define HOLD_ON_OTHER_KEY_PRESS
#define TAPPING_TERM 129

// For select_word to work with mac. Or else Windows/Linux
// are assumed by default
#define SELECT_WORD_OS_MAC
