target=us_xfr_sv

CUR_DIR=$(shell pwd)
all_header=/home/xiuhaozhong/linux_learning/Linux/linux_system/common/tlpi_hdr.h
common=/home/xiuhaozhong/linux_learning/Linux/linux_system/common/

SRC=$(CUR_DIR)/src

INCLUDE=$(CUR_DIR)/include

gen_dir=build


VPATH=$(common)

$(target): $(gen_dir)$(target).o $(gen_dir)get_num.o $(gen_dir)error_functions.o
	gcc -o $(target) $(target).o get_num.o error_functions.o -lrt

$(gen_dir)get_num.o: $(common)get_num.c
	gcc -c $(common)get_num.h $(common)get_num.c

$(gen_dir)error_functions.o: $(common)error_functions.c
	gcc -c $(all_header) $(common)error_functions.h $(common)error_functions.c

$(gen_dir)$(target).o: $(target).c
	gcc -c $(target).c -I$(common) $(all_header)

clean:
	rm $(gen_dir)$(target)

clean all:
	rm $(gen_dir*)
