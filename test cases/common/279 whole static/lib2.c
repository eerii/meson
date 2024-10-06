int lib1(void);
int liba(void);

int lib2(void) { return lib1() + liba(); }
