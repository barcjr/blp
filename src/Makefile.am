# generated 2006/3/4 20:07:11 MST by bda@localhost.(none)
# using glademm V2.6.0
#
# newer (non customized) versions of this file go to Makefile.am_new
bin_PROGRAMS = blp

blp_SOURCES = \
	blp.cc\
	windowBLP_glade.cc \
	windowBLP.cc \
	contact.cc \
	dam.cc \
	progLog.cc \
	dialogAlert_glade.cc \
	dialogAlert.cc

noinst_HEADERS = \
	windowBLP_glade.hh \
	windowBLP.hh  \
	blp.h \
	dialogAlert_glade.hh \
	dialogAlert.hh

AM_CXXFLAGS = @GTKMM_CFLAGS@ 

blp_LDADD = @LIBS@ @GTKMM_LIBS@ -lmysqlclient -lz -L/usr/lib/mysql -lhamlib -lparapin

blp_LDFLAGS = -ggdb
