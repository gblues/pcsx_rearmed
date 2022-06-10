/* From wut:
 * https://github.com/devkitPro/wut/blob/1527966c0bba9a6e69c4178c3966b011b809a861/include/wut.h
 */

#pragma once

/*
 * wut 1.0.0-beta
 *
 * https://github.com/devkitPro/wut
 */

#include "wut_structsize.h"
#include "wut_types.h"
#include "wut_rplwrap.h"

#ifdef __GNUC__

#define WUT_DEPRECATED(reason) __attribute__((deprecated(reason)))

#else // not __GNUC__

#define WUT_DEPRECATED(reason)

#endif //__GNUC__
