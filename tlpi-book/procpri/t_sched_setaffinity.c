/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Supplementary program for Chapter 35 */

#define _GNU_SOURCE
#include <sched.h>
#include "tlpi_hdr.h"

int
main(int argc, char *argv[])
{
    pid_t pid;
    cpu_set_t set;
    int cpu;
    unsigned long mask;

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s pid mask\n", argv[0]);

    pid = getInt(argv[1], GN_NONNEG, "pid");
    mask = getLong(argv[2], GN_ANY_BASE, "octal-mask");

    CPU_ZERO(&set);

    for (cpu = 0; mask > 0; cpu++, mask >>= 1)
        if (mask & 1)
            CPU_SET(cpu, &set);

    if (sched_setaffinity(pid, sizeof(set), &set) == -1)
        errExit("sched_setaffinity");

    exit(EXIT_SUCCESS);
}