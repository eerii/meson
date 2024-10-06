project('testmeson', 'c',
  version : '0.1',
  default_options : [
    'warning_level=3',
    'default_library=static',
  ],
  meson_version: '>=1.6.0')

x11 = dependency('x11') # System library
liba = dependency('a') # Subproject

lib1 = static_library('1', 'lib1.c', dependencies : [liba, x11])
dep1 = declare_dependency(link_with : lib1)

lib2 = static_library('2', 'lib2.c', dependencies : dep1)
dep2 = declare_dependency(link_with : lib2)

lib3 = static_library('3', 'lib3.c', dependencies : dep2.as_link_whole(recursive: true))
dep3 = declare_dependency(link_with : lib3)

lib3x = static_library('3x', objects : lib3.extract_all_objects(recursive: true))

exe = executable('testmeson', 'main.c', link_with : lib3x)

pkgconfig = import('pkgconfig')
pkgconfig.generate(lib3)
