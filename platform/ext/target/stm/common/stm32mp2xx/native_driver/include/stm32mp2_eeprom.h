/*
 * Copyright (c) 2026, PHYTEC Messtechnik GmbH
 * Author: Nicolas RAIMUNDO <n.raimundo@phytec.fr>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM32MP2_EEPROM_H
#define STM32MP2_EEPROM_H

#include <stdint.h>
#include <stdbool.h>
#include <i2c.h>

bool read_eeprom_i2c8(uint8_t eeprom_addr, uint8_t data_addr, uint8_t *data, size_t data_size);

#endif
