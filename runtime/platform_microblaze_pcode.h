/* -*- mode: C -*-
 *
 * Copyright (c) 2007, 2008, 2011 The University of Utah
 * All rights reserved.
 *
 * This file is part of `csmith', a random generator of C programs.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef PLATFORM_MICROBLAZE_PCODE_H
#define PLATFORM_MICROBLAZE_PCODE_H

/*****************************************************************************/

//#include <stdint.h>

static void platform_main_begin(void);
static void platform_main_begin(void)
{
	/* Nothing to do. */
}

static void platform_main_end(uint32_t crc, int flag);
static void platform_main_end(uint32_t crc, int flag)
{
    register uint32_t r12 __asm__("r12") = 0x80000000;
    register uint32_t r3 __asm__("r3");
    register uint32_t r5 __asm__("r5") = crc;
    __asm__ __volatile__ ("brki r14, 0x8" : "=r"(r3)
        : "r"(r12), "r"(r5)
        : "memory", "r4");
}

#define printf(...)
#define fprintf(...)

/*****************************************************************************/

#endif /* PLATFORM_MICROBLAZE_PCODE_H */

/*
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 4
 * End:
 */

/* End of file. */
