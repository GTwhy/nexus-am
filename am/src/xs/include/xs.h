#ifndef __XIANGSHAN_H__
#define __XIANGSHAN_H__

#include <am.h>
#include <xsextra.h>
#include <klib.h>

#include ISA_H // "x86.h", "mips32.h", ...

#if defined(__ARCH_RISCV64_NOOP) || defined(__ARCH_RISCV32_NOOP) || defined(__ARCH_RISCV64_XS)
#define INTR_GEN_ADDR          (0x40070000UL)
#define INTR_RANDOM            (0x40070008UL)
#define INTR_RANDOM_MASK       (0x40070010UL)
#define PLIC_BASE_ADDR         (0x3c000000UL)
#elif defined(__ARCH_RISCV64_XS_SOUTHLAKE) || defined(__ARCH_RISCV64_XS_SOUTHLAKE_FLASH)
#define INTR_GEN_ADDR          (0x1f40070000UL)
#define INTR_RANDOM            (0x1f40070008UL)
#define INTR_RANDOM_MASK       (0x1f40070010UL)
#define PLIC_BASE_ADDR         (0x1f0c000000UL)
#endif

extern int __am_ncpu;

#endif
