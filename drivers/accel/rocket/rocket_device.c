// SPDX-License-Identifier: GPL-2.0-only
/* Copyright 2024-2025 Tomeu Vizoso <tomeu@tomeuvizoso.net> */

#include <linux/array_size.h>
#include <linux/clk.h>
#include <linux/dev_printk.h>

#include "rocket_device.h"

int rocket_device_init(struct rocket_device *rdev)
{
	int err;

	/* Initialize core 0 (top) */
	err = rocket_core_init(&rdev->cores[0]);
	if (err)
		return err;

	return 0;
}

void rocket_device_fini(struct rocket_device *rdev)
{
	rocket_core_fini(&rdev->cores[0]);
}
