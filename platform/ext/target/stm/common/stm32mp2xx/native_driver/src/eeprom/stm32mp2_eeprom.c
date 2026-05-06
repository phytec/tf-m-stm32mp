/*
 * Copyright (c) 2023, STMicroelectronics - All Rights Reserved
 * Author(s): Ludovic Barre, <ludovic.barre@foss.st.com> for STMicroelectronics.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <string.h>
#include <debug.h>
#include <lib/mmio.h>
#include <lib/mmiopoll.h>
#include <lib/utils_def.h>
#include <lib/timeout.h>

#include <device.h>
#include <i2c.h>
#include <regulator.h>
#include <linear_range.h>

bool read_eeprom_i2c8(uint8_t eeprom_addr, uint8_t data_addr, uint8_t *data, uint8_t data_size)
{
	const struct device *i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c8));

    if (!device_is_ready(i2c_dev))
    {
        WMSG("I2C8 controler not ready\n");
        return false;
    }

    if (i2c_burst_read(i2c_dev, eeprom_addr, data_addr, data ,data_size) != 0 )
	{
		WMSG ("Cannot read the eeprom\n");
		return false;
	}

	return true;
}
