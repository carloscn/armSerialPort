#ifndef GLOBAL_H
#define GLOBAL_H

#include <linux/fs.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define                     CONFIG_BAUDRATE_1200_INDEX             0
#define                     CONFIG_BAUDRATE_2400_INDEX             1
#define                     CONFIG_BAUDRATE_4800_INDEX             2
#define                     CONFIG_BAUDRATE_9600_INDEX             3
#define                     CONFIG_BAUDRATE_19200_INDEX            4
#define                     CONFIG_BAUDRATE_38400_INDEX            5
#define                     CONFIG_BAUDRATE_57600_INDEX            6
#define                     CONFIG_BAUDRATE_115200_INDEX           7

#define                     CONFIG_STOPBIT_ONE_INDEX               0
#define                     CONFIG_STOPBIT_ONEANDHALF_INDEX        1
#define                     CONFIG_STOPBIT_TWO_INDEX               2

#define                     CONFIG_PARITY_NONE_INDEX               0
#define                     CONFIG_PARITY_EVEN_INDEX               1
#define                     CONFIG_PARITY_ODD_INDEX                2
#define                     CONFIG_PARITY_SPACE_INDEX              3
#define                     CONFIG_PARITY_MARK_INDEX               4

#define                     CONFIG_FLOWCTRL_NONE_INDEX             0
#define                     CONFIG_FLOWCTRL_HARD_INDEX             1
#define                     CONFIG_FLOWCTRL_SOFT_INDEX             2

#define                     CONFIG_DATABITS_5_INDEX                 0
#define                     CONFIG_DATABITS_6_INDEX                 1
#define                     CONFIG_DATABITS_7_INDEX                 2
#define                     CONFIG_DATABITS_8_INDEX                 3



#endif // GLOBAL_H
