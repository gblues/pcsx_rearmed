/* From wut:
 * https://github.com/devkitPro/wut/blob/1527966c0bba9a6e69c4178c3966b011b809a861/include/wut_types.h
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdalign.h>

typedef int32_t BOOL;

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#if __cplusplus >= 201402L
#define WUT_ENUM_BITMASK_TYPE(_type) \
   extern "C++" { static constexpr inline _type operator|(_type lhs, _type rhs) { \
      return static_cast<_type>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs)); \
   } }
#else
#define WUT_ENUM_BITMASK_TYPE(_type)
#endif
