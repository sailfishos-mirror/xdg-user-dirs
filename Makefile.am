NULL =

SUBDIRS=po

INCLUDES =					\
	-I$(top_srcdir)				\
	-I$(top_builddir)			\
	-DXDGCONFDIR=\"$(sysconfdir)/xdg\"		\
	-DLOCALEDIR=\"$(datadir)/locale\" 	\
	$(NULL)

EXTRA_DIST= config.rpath translate.c autogen.sh \
	user-dirs.conf user-dirs.defaults

xdgdir=$(sysconfdir)/xdg
xdg_DATA=user-dirs.conf user-dirs.defaults

libraries =

bin_PROGRAMS =					\
	xdg-user-dirs-update			\
	xdg-user-dir				\
	$(NULL)

xdg_user_dirs_update_SOURCES = xdg-user-dirs-update.c
xdg_user_dirs_update_LDADD = $(libraries)

xdg_user_dir_SOURCES = xdg-user-dir

noinst_PROGRAMS= \
	xdg-user-dir-lookup

xdg_user_dir_lookup_SOURCES = \
	xdg-user-dir-lookup.c
