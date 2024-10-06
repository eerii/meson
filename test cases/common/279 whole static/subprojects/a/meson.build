project('a', 'c')

liba = library('a', 'liba.c')
liba_dep = declare_dependency(link_with: liba)
meson.override_dependency('a', liba_dep)
