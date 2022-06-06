/* SPDX-License-Identifier: LGPL-2.1-or-later */
/*
 * Copyright (C) 2022 Paul Cercueil <paul@crapouillou.net>
 */

#ifndef __LIGHTREC_MEM_H__
#define __LIGHTREC_MEM_H__

#ifdef __wiiu__

#define WUP_RWX_MEM_BASE 0x00802000
#define WUP_RWX_MEM_END 0x01000000
#define CODE_BUFFER_SIZE (WUP_RWX_MEM_END - WUP_RWX_MEM_BASE)

#else

#define CODE_BUFFER_SIZE (8 * 1024 * 1024)

#endif

extern void *code_buffer;

int lightrec_init_mmap(void);
void lightrec_free_mmap(void);

#endif /* __LIGHTREC_MEM_H__ */
