/*
* mapmlib.c
* mapm interface to Lua
* lhf@tecgraf.puc-rio.br
* 17 Feb 2002 16:27:18
* This code is hereby placed in the public domain.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "lua.h"
#include "m_apm.h"

#define m_apm_inv	m_apm_reciprocal
#define m_apm_abs	m_apm_absolute_value
#define m_apm_neg	m_apm_negate
#define m_apm_sub	m_apm_subtract
#define m_apm_mul	m_apm_multiply
#define m_apm_div	m_apm_divide

static int BIGNUMBER;
static int DIGITS;

static M_APM Bget(lua_State *L, int i)
{
 if (lua_tag(L,i)==BIGNUMBER)
  return lua_touserdata(L,i);
 else
 {
  const char* s=lua_tostring(L,i);
  M_APM x=m_apm_init();
  m_apm_set_string(x,s?s:"0");
  return x;
 }
}

static int Bdigits(lua_State *L)
{
 if (lua_gettop(L)==0)
 {
  lua_pushnumber(L,DIGITS);
  return 1;
 }
 else
 {
  DIGITS=lua_tonumber(L,1);
  return 0;
 }
}

static int Bstring(lua_State *L)
{
 M_APM a=Bget(L,1);
 char s[1000];
#if 0
 m_apm_to_string(s,-1,a);
#else
 m_apm_to_fixpt_string(s,-1,a);
#endif
 lua_pushstring(L,s);
 return 1;
}

static int Bnumber(lua_State *L)
{
 M_APM a=Bget(L,1);
 lua_pushusertag(L,a,BIGNUMBER);
 return 1;
}

static int Bround(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_round(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Binv(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_inv(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bsqrt(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_sqrt(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bcbrt(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_cbrt(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Blog(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_log(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Blog10(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_log10(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bexp(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_exp(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bsin(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_sin(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bcos(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_cos(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bsincos(lua_State *L)
{
 M_APM c=m_apm_init();
 M_APM a=Bget(L,1);
 M_APM s=m_apm_init();
 m_apm_sin_cos(s,c,DIGITS,a);
 lua_pushusertag(L,s,BIGNUMBER);
 lua_pushusertag(L,c,BIGNUMBER);
 return 2;
}

static int Btan(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_tan(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Basin(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_asin(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bacos(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_acos(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Batan(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_atan(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bsinh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_sinh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bcosh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_cosh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Btanh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_tanh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Basinh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_asinh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bacosh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_acosh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Batanh(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_atanh(c,DIGITS,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Babs(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_abs(c,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bneg(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_neg(c,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bfactorial(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_factorial(c,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bfloor(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_floor(c,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bceil(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM c=m_apm_init();
 m_apm_ceil(c,a);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Badd(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM b=Bget(L,2);
 M_APM c=m_apm_init();
 m_apm_add(c,a,b);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bsub(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM b=Bget(L,2);
 M_APM c=m_apm_init();
 m_apm_sub(c,a,b);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bmul(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM b=Bget(L,2);
 M_APM c=m_apm_init();
 m_apm_mul(c,a,b);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bdiv(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM b=Bget(L,2);
 M_APM c=m_apm_init();
 m_apm_div(c,DIGITS,a,b);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bpow(lua_State *L)
{
 M_APM a=Bget(L,1);
 M_APM b=Bget(L,2);
 M_APM c=m_apm_init();
 m_apm_pow(c,DIGITS,a,b);
 lua_pushusertag(L,c,BIGNUMBER);
 return 1;
}

static int Bgc(lua_State *L)
{
 M_APM a=Bget(L,1);
 m_apm_free(a);
 return 0;
}

int lua_mapmlibopen(lua_State *L)
{
 BIGNUMBER=lua_newtag(L);
 lua_pushcfunction(L,Bgc); lua_settagmethod(L,BIGNUMBER,"gc");
 lua_register(L,"Bdigits",Bdigits);
 lua_register(L,"Bstring",Bstring);
 lua_register(L,"Bnumber",Bnumber);
 lua_register(L,"Bround",Bround);
 lua_register(L,"Binv",Binv);
 lua_register(L,"Bsqrt",Bsqrt);
 lua_register(L,"Bcbrt",Bcbrt);
 lua_register(L,"Blog",Blog);
 lua_register(L,"Blog10",Blog10);
 lua_register(L,"Bexp",Bexp);
 lua_register(L,"Bsincos",Bsincos);
 lua_register(L,"Bsin",Bsin);
 lua_register(L,"Bcos",Bcos);
 lua_register(L,"Btan",Btan);
 lua_register(L,"Basin",Basin);
 lua_register(L,"Bacos",Bacos);
 lua_register(L,"Batan",Batan);
 lua_register(L,"Bsinh",Bsinh);
 lua_register(L,"Bcosh",Bcosh);
 lua_register(L,"Btanh",Btanh);
 lua_register(L,"Basinh",Basinh);
 lua_register(L,"Bacosh",Bacosh);
 lua_register(L,"Batanh",Batanh);
 lua_register(L,"Babs",Babs);
 lua_register(L,"Bneg",Bneg);
 lua_register(L,"Bfactorial",Bfactorial);
 lua_register(L,"Bfloor",Bfloor);
 lua_register(L,"Bceil",Bceil);
 lua_register(L,"Badd",Badd);
 lua_register(L,"Bsub",Bsub);
 lua_register(L,"Bmul",Bmul);
 lua_register(L,"Bdiv",Bdiv);
 lua_register(L,"Bpow",Bpow);
 return 0;
}
