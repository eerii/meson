project('testmeson', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
  ],
  meson_version: '>=1.6.0')

# The dependency for glib is a subproject
# (It can't be a system dependency because of https://github.com/mesonbuild/meson/pull/9218)
# The extracting objects idea comes from https://github.com/gavr123456789/Vala/blob/0d3db31ddaaf63039129b1d6991d1379a565000a/libraries/meson/static-library.md?plain=1#L32C1-L35C18
# But I'm not sure it can be scaled to our huge dependency codebase, we need to make it recursive

deps = static_library('deps', 'lib1.c', dependencies : [dependency('glib-2.0')])
lib1 = static_library('1', objects : deps.extract_all_objects(), install : true)
dep1 = declare_dependency(link_with : lib1)

# This doesn't work
# lib2 = static_library('1', 'lib2.c', dependencies : [dependency('glib-2.0').as_link_whole()])
# dep2 = declare_dependency(link_with : lib2)

lib2 = static_library('2', 'lib2.c', dependencies : dep1.as_link_whole()) # Without link_whole it doesn't work
dep2 = declare_dependency(link_with : lib2)

lib3 = static_library('3', 'lib3.c', dependencies : dep2.as_link_whole(), install : true)
dep3 = declare_dependency(link_with : lib3)

exe = executable('testmeson', 'main.c', link_with : lib3)

pkgconfig = import('pkgconfig')
pkgconfig.generate(lib3)
