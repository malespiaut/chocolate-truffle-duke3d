// converted from asm to c by Jonof

#include "fixedPoint_math.h"
#include "platform.h"
#include <stdio.h>
#include <string.h>

void
clearbuf(void* d, int32_t c, int32_t a)
{
  // tanguyf: this completely violates strict-aliasing.
  // int32_t *p = (int32_t*)d;
  // while ((c--) > 0) *(p++) = a;

  union
  {
    struct
    {
      uint8_t a, b, c, d;
    };
    int32_t value;
  } src;

  src.value = a;

  uint8_t* dst = (uint8_t*)d;

  for (int32_t i = 0; i < c; ++i)
  {
    dst[i * 4 + 0] = src.a;
    dst[i * 4 + 1] = src.b;
    dst[i * 4 + 2] = src.c;
    dst[i * 4 + 3] = src.d;
  }
}

void
clearbufbyte(void* D, int32_t c, int32_t a)
{ // Cringe City
  uint8_t* p = (uint8_t*)D;
  int32_t m[4] = {0xffl, 0xff00l, 0xff0000l, 0xff000000l};
  int32_t n[4] = {0, 8, 16, 24};
  int32_t z = 0;
  while ((c--) > 0)
  {
    *(p++) = (uint8_t)((a & m[z]) >> n[z]);
    z = (z + 1) & 3;
  }
}

void
copybuf(void* s, void* d, int32_t c)
{
  // tanguyf: this completely violates strict-aliasing.
  // int32_t *p = (int32_t*)s, *q = (int32_t*)d;
  // while ((c--) > 0) *(q++) = *(p++);
  memcpy(d, s, c * sizeof(int32_t));
}

void
copybufbyte(void* S, void* D, int32_t c)
{
  uint8_t *p = (uint8_t*)S, *q = (uint8_t*)D;
  while ((c--) > 0)
    *(q++) = *(p++);
}

void
copybufreverse(void* S, void* D, int32_t c)
{
  uint8_t *p = (uint8_t*)S, *q = (uint8_t*)D;
  while ((c--) > 0)
    *(q++) = *(p--);
}

void
qinterpolatedown16(int32_t* bufptr, int32_t num, int32_t val, int32_t add)
{ // gee, I wonder who could have provided this...
  int32_t i, *lptr = bufptr;
  for (i = 0; i < num; i++)
  {
    lptr[i] = (val >> 16);
    val += add;
  }
}

void
qinterpolatedown16short(int32_t* bufptr, int32_t num, int32_t val, int32_t add)
{ // ...maybe the same person who provided this too?
  int32_t i;
  short* sptr = (short*)bufptr;
  for (i = 0; i < num; i++)
  {
    sptr[i] = (short)(val >> 16);
    val += add;
  }
}
