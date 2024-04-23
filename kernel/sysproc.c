#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"
#include "strace.h"

#define SHUTDOWN 0x5555
#define REBOOT 0x7777


uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  STRACE_ARGS("%d", n, "", "");
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  STRACE();
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  STRACE();
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  STRACE_ARGS("%d", p, "", "");
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;
  argint(0, &n);
  STRACE_ARGS("%d", n, "", "");
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;;
  argint(0, &n);
  STRACE_ARGS("Time: %d", n, "", "");
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;
  argint(0, &pid);
  STRACE_ARGS("%d", pid, "", "");
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  STRACE();
  return xticks;
}

uint64
sys_shutdown(void)
{
  volatile uint32 *test_dev = (uint32 *) VIRT_TEST;
  STRACE();
  return *test_dev = SHUTDOWN;
}

uint64
sys_reboot(void)
{
  volatile uint32 *test_dev = (uint32 *) VIRT_TEST;
  STRACE();
  return *test_dev = REBOOT;
}

uint64
sys_clock(void)
{
  volatile uint64 *time = (uint64 *) CLOCK;
  STRACE();
  return *time;
}

uint64
sys_strace(void)
{
  STRACE();
  return myproc()->strace = 1;
}

uint64
sys_wait2(void)
{
  uint64 status;
  uint64 count;
  argaddr(0, &status);
  argaddr(1, &count);
  return wait2(status, count);
}
