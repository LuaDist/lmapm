# makefile for mapm binding for Lua

# change this to reflect your installation
LUA=/tmp/lua-4.0
LUALIB= $(LUA)/lib
LUAINC= $(LUA)/include

MAPM=/tmp/mapm_4.3
MAPM=.

CC= gcc
CFLAGS= $(INCS) $(DEFS) $(WARN) -O2 -g
WARN= -ansi -pedantic -Wall #-Wmissing-prototypes

INCS= -I$(MAPM) -I$(LUAINC) -I.
LIBS= -L$(MAPM) -lmapm -L$(LUALIB) -llua -llualib -lm

OBJS= mapmlib.o main.o

T=a.out

all:	$T

$T:	$(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $T $(OBJS) core

test:	$T
	$T test.lua

map:
	@@ld -o /dev/null -e main -M $(OBJS) $(LIBS) -lc | sed '/Memory/q' | sort | grep mapm

# distribution

D=mapm
A=$D.tar.gz
TOTAR=Makefile,README,main.c,mapmlib.c,test.lua,test2.lua,tm.lua

tar:	clean
	tar zcvf $A -C .. $D/{$(TOTAR)}

distr:	tar
	mv $A ftp
