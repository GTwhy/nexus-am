#ifndef __ARCH_H__
#define __ARCH_H__

#include <riscv64.h>

struct _Context {
  union {
    struct _AddressSpace *as;
    uint64_t gpr[32];
  };
  uint64_t mcause;
  uint64_t mstatus;
  uint64_t mepc;
};

#define GPR1 gpr[17] // a7
#define GPR2 gpr[10] // a0
#define GPR3 gpr[11] // a1
#define GPR4 gpr[12] // a2
#define GPRx gpr[10] // a0

#define MAP(c, f) c(f)

#define COUNTERS(f) \
  f(cycle) f(time) f(instr)

#define CNT_IDX(cnt) PERFCNT_##cnt
#define CNT_ENUM_ITEM(cnt) CNT_IDX(cnt),
enum {
  MAP(COUNTERS, CNT_ENUM_ITEM)
  NR_PERFCNT,
};

typedef struct {
  R64 cnts[NR_PERFCNT];
} PerfCntSet;

void __am_perfcnt_read(PerfCntSet *t);
void __am_perfcnt_sub(PerfCntSet *res, PerfCntSet *t1, PerfCntSet *t0);
void __am_perfcnt_add(PerfCntSet *res, PerfCntSet *t1, PerfCntSet *t0);
void __am_perfcnt_show(PerfCntSet *t);
void __am_perfcnt_excel(PerfCntSet *t);

#endif
