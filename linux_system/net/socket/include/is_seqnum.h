#include <netinet/in.h>
#include <sys/socket.h>
#include <signal.h>

#include "read_line.h"
#include "tlpii_hdr.h"

#define PORT_NUM "50000"		/* Port number for server */

#define INT_LEN 30					/* Size of string able to hold 
															 largest integer (includeing terminating '\n')*/




