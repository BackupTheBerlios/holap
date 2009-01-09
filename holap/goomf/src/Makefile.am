ui_PROGRAMS = goomf_fltk

uidir = $(libdir)/dssi/goomf

plugindir = $(libdir)/dssi

plugin_LTLIBRARIES = goomf.la


horgand_fltk_SOURCES = main_ui.cpp \
	main_ui.h \
	goomf_ui.cxx \
	goomf.h 



goomf_fltk_LDADD =  -lfltk -lfltk_images -lpthread

goomf_fltk_CXXFLAGS = "-I/usr/include/freetype2 -D_THREAD_SAFE -D_REENTRANT"

goomf_fltk_CFLAGS = "-D_THREAD_SAFE -D_REENTRANT"

goomf_la_SOURCES = goomf.c \
        synth.c \
	syntvarios.c \
	synthfileio.c \
        goomf.h 

goomf_la_LIBADD = -lm -lpthread

goomf_la_LDFLAGS = -module -avoid-version 

install-data-hook:
	rm $(plugindir)/goomf.la
	rm $(plugindir)/goomf.a
	
        