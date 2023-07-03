#ifndef TYPEDEFS
#define TYPEDEFS

#include <cstdlib>
#include <cstdio>
#include <cstdint>

typedef int32_t  sint32;
typedef int64_t  sint64;
typedef uint8_t  uint8;
typedef uint32_t uint32;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;

typedef int8_t  s8;
typedef int16_t s16;
typedef int32_t s32;

#define SetBit(Modifier, Value)   Modifier |= (0x1 << Value)
#define UnsetBit(Modifier, Value) Modifier &= ~(0x1 << Value)
#define CheckBit(Modifier, Value) Modifier & (0x1 << Value)

extern size_t CURR_MEM_SIZE;

void* operator new (size_t size);
void  operator delete (void* ptr) noexcept;

#endif
