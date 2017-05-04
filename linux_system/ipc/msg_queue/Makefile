source=pmsg_receive

$(source):$(source).o error_functions.o get_num.o
	gcc -o $(source) $(source).o error_functions.o get_num.o -lrt 

error_functions.o:../error_functions.h ../error_functions.c ../ename.c.inc
	gcc -c ../error_functions.c

get_num.o:../get_num.h ../get_num.c
	gcc -c ../get_num.c

$(source).o:../tlpi_hdr.h $(source).c
	gcc -c $(source).c

clean:
	rm *.o $(source)

