TARGET			= us_xfr_sv
CC					= gcc
CFLAGS			= -I ../include -I ../../../common/include

VPATH				= ../include:\
							../src:\
							../../../common/include:\
							../../../common/src
OBJS 				= $(TARGET).o error_functions.o get_num.o
$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	-rm $(TARGET) *.o
