# Makefile for building DeText with Watcom C++

.ERASE

all: dos\detext.exe os2\detext.exe win32\detext.exe

CFLAGS=-osxr -zq -j

dos\detext.exe: dos\detext.obj
	wlink name $^@ file $< sys dos op q

dos\detext.obj: detext.cpp $(__MAKEFILES__)
	wpp $(CFLAGS) -bt=dos $[@ -fo=$^@

os2\detext.exe: os2\detext.obj
	wlink name $^@ file $< sys os2v2 op q

os2\detext.obj: detext.cpp $(__MAKEFILES__)
	wpp386 $(CFLAGS) -bt=os2 $[@ -fo=$^@

win32\detext.exe: win32\detext.obj
	wlink name $^@ file $< sys nt op q

win32\detext.obj: detext.cpp $(__MAKEFILES__)
	wpp386 $(CFLAGS) -bt=nt $[@ -fo=$^@
