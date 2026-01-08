/*
 * This file is part of OpenTTD.
 * OpenTTD is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
 * OpenTTD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with OpenTTD. If not, see <https://www.gnu.org/licenses/old-licenses/gpl-2.0>.
 */

/** @file zoom_type.h Types related to zooming in and out. */

#ifndef ZOOM_TYPE_H
#define ZOOM_TYPE_H

#include "core/enum_type.hpp"

static const uint EXTRA_ZOOM_LEVELS = 2;
static const uint ZOOM_SCALE_BITS = 8;
static const uint ZOOM_SCALE_INV_BITS = 24 - ZOOM_SCALE_BITS;

static const uint ZOOM_SCALES[] = {
	1 * 256, // in4x
	//304,
	362,
	//431,
	2 * 256, // in2x
	//609,
	724,
	//861,
	4 * 256, // normal
	//1217,
	1448,
	//1722,
	8 * 256, // out2x
	//2435,
	2896,
	//3444,
	16 * 256, // out4x
	//4871,
	5793,
	//6889,
	32 * 256, // out8x
	//4871*2,
	5793*2,
	//6889*2,
	64 * 256, // out16x
	//4871*4,
	5793*4,
	//6889*4,
	128 * 256, // out32x
};

static const uint ZOOM_SCALES_INV[] = {
	0x1000000 / (1 * 256), // in4x
	//0x1000000 / 304,
	0x1000000 / 362,
	//0x1000000 / 431,
	0x1000000 / (2 * 256), // in2x
	//0x1000000 / 609,
	0x1000000 / 724,
	//0x1000000 / 861,
	0x1000000 / (4 * 256), // normal
	//0x1000000 / 1217,
	0x1000000 / 1448,
	//0x1000000 / 1722,
	0x1000000 / (8 * 256), // out2x
	//0x1000000 / 2435,
	0x1000000 / 2896,
	//0x1000000 / 3444,
	0x1000000 / (16 * 256), // out4x
	//0x1000000 / 4871,
	0x1000000 / 5793,
	//0x1000000 / 6889,
	0x1000000 / (32 * 256), // out8x
	//0x1000000 / (4871*2),
	0x1000000 / (5793*2),
	//0x1000000 / (6889*2),
	0x1000000 / (64 * 256), // out16x
	//0x1000000 / (4871*4),
	0x1000000 / (5793*4),
	//0x1000000 / (6889*4),
	0x1000000 / (128 * 256), // out32x
};

/**
 * All zoom levels we know.
 *
 * The underlying type is signed so subtract-and-Clamp works without need for casting.
 */
enum class ZoomLevel : int8_t {
	/* Our possible zoom-levels */

	// exponential zoom levels in quarter steps
	//  aka 1, 1.189, 1.41, 1.68

	Begin = 0, ///< Begin for iteration.
	Min = Begin, ///< Minimum zoom level.

	In4x = Begin, ///< Zoomed 16 times in.
	/*//In16x1,
	In16x2,
	//In16x3,
	In8x,
	//In8x1,
	In8x2,
	//In8x3,

	In4x,*/
	//In4x1,
	In4x2,
	//In4x3,

	In2x, ///< Zoomed 2 times in.
	//In2x1,
	In2x2,
	//In2x3,

	Normal, ///< The normal zoom level.
	//Normal1,
	Normal2,
	//Normal3,

	Out2x, ///< Zoomed 2 times out.
	//Out2x1,
	Out2x2,
	//Out2x3,

	Out4x, ///< Zoomed 4 times out.
	//Out4x1,
	Out4x2,
	//Out4x3,

	Out8x, ///< Zoomed 8 times out.

	Max = Out8x, ///< Maximum zoom level.
	End, ///< End for iteration.

	/* Here we define in which zoom viewports are */
	Viewport = Normal, ///< Default zoom level for viewports.
	News = Normal, ///< Default zoom level for the news messages.
	Industry = Out2x, ///< Default zoom level for the industry view.
	Town = Normal, ///< Default zoom level for the town view.
	Aircraft = Normal, ///< Default zoom level for the aircraft view.
	Ship = Normal, ///< Default zoom level for the ship view.
	Train = Normal, ///< Default zoom level for the train view.
	RoadVehicle = Normal, ///< Default zoom level for the road vehicle view.
	WorldScreenshot = Normal, ///< Default zoom level for the world screen shot.

	Detail = Out2x, ///< All zoom levels below or equal to this will result in details on the screen, like road-work, ...
	TextEffect = Out2x, ///< All zoom levels above this will not show text effects.
};
DECLARE_INCREMENT_DECREMENT_OPERATORS(ZoomLevel)
DECLARE_ENUM_AS_SEQUENTIAL(ZoomLevel)

using ZoomLevels = EnumBitSet<ZoomLevel, uint8_t>;

static const uint ZOOM_BASE_SHIFT = to_underlying(ZoomLevel::Normal) / EXTRA_ZOOM_LEVELS;
static const uint ZOOM_BASE = 1U << ZOOM_BASE_SHIFT; // was 4

extern int _gui_scale;
extern int _gui_scale_cfg;

extern ZoomLevel _gui_zoom;
extern ZoomLevel _font_zoom;

static const int MIN_INTERFACE_SCALE = 100;
static const int MAX_INTERFACE_SCALE = 500;

#endif /* ZOOM_TYPE_H */
