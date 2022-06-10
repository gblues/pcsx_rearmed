/* From wut:
 * https://github.com/devkitPro/wut/blob/1527966c0bba9a6e69c4178c3966b011b809a861/include/coreinit/systeminfo.h
 */

#pragma once
#include <wut.h>

/**
 * \defgroup coreinit_systeminfo System Info
 * \ingroup coreinit
 * @{
 */

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OSSystemInfo OSSystemInfo;

struct OSSystemInfo
{
   uint32_t busClockSpeed;
   uint32_t coreClockSpeed;
   int64_t baseTime;
   WUT_UNKNOWN_BYTES(0x10);
};
WUT_CHECK_OFFSET(OSSystemInfo, 0x0, busClockSpeed);
WUT_CHECK_OFFSET(OSSystemInfo, 0x4, coreClockSpeed);
WUT_CHECK_OFFSET(OSSystemInfo, 0x8, baseTime);
WUT_CHECK_SIZE(OSSystemInfo, 0x20);

OSSystemInfo *
OSGetSystemInfo();

BOOL
OSEnableHomeButtonMenu(BOOL enable);

BOOL
OSIsHomeButtonMenuEnabled();

uint64_t
OSGetOSID();

uint32_t
__OSGetProcessSDKVersion();

#ifdef __cplusplus
}
#endif

/** @} */
