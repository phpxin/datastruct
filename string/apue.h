//unix 
#include <unistd.h>
#include <stdlib.h>

//memory and io
#include <string.h>
#include <stdio.h>

//high level io
#include <sys/uio.h>
#include <sys/sendfile.h>
#include <sys/mman.h>

//system type
#include <sys/time.h>

//exception
#include <errno.h>
#include <setjmp.h>

//file system
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/ioctl.h>

//socket
#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//signal
#include<signal.h>

//multi users
#include <pthread.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/select.h>
#include <poll.h>
#include <sys/epoll.h>

//debug
#include <assert.h>
