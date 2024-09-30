project('testmeson', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'default_library=static',
  ],
  meson_version: '>=1.6.0')

# The dependency for glib is a subproject
# (It can't be a system dependency because of https://github.com/mesonbuild/meson/pull/9218)

# Before we were extracting the objects recursively and it works, but it is not very scallable
# deps = static_library('deps', 'lib1.c', dependencies : [dependency('glib-2.0')])
# lib1 = static_library('1', objects : deps.extract_all_objects(), install : true)
# dep1 = declare_dependency(link_with : lib1)

x11 = dependency('x11') # System library
glib = dependency('glib-2.0') # Subproject
lib1 = static_library('1', 'lib1.c', dependencies : [glib, x11])
dep1 = declare_dependency(link_with : lib1)

lib2 = static_library('2', 'lib2.c', dependencies : dep1)
dep2 = declare_dependency(link_with : lib2)

lib3 = static_library('3', 'lib3.c', dependencies : dep2.as_link_whole(), install : true)
dep3 = declare_dependency(link_with : lib3)

exe = executable('testmeson', 'main.c', link_with : lib3)

pkgconfig = import('pkgconfig')
pkgconfig.generate(lib3)
