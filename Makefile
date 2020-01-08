TARGETS=qsort_c

# Mac OS
# CC=gcc
# CC_OPTS=-Ofast -Wall -fPIC -fomit-frame-pointer
# LD=ld
# LD_OPTS=-macosx_version_min 10.15.0 -lSystem -no_pie

#-Ofast causes a segfault
CC=gcc
CC_OPTS=-g -gdwarf -O0 -Wall -fPIC -Wfatal-errors
LD=gcc
LD_OPTS=-g -gdwarf -lc -flto

all: $(TARGETS)

.SUFFIXES:
.PRECIOUS: %.o

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

#%_asm.o: %.asm
#	nasm -f macho64 $< -o $@
#
#qsort_asm: qsort_main.o partition_inner_asm.o partition_outer_asm.o
#	$(LD) $(LD_OPTS) -o $@ $^

qsort_c: qsort.o
	$(LD) $(LD_OPTS) -o $@ $^

clean:
	rm -rf *.o $(TARGETS)
