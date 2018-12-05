#include "serialread.h"
#include "global.h"
#include <QDebug>

SerialRead::SerialRead()
{

}


void SerialRead::run( )
{
    int fd;
    char rcv_buf[800];
    int len;

    QString str;
    fd  = getUartFd();

    while (1) {
        msleep(10);

        len = UartRecvData(fd ,rcv_buf, 100 );
        if( len > 0 ) {
            rcv_buf[len] = '\0';
            str =  QString::fromLocal8Bit( rcv_buf );
            emit ReadResult(str);
        }else{
            qDebug() << "read data failed!!!";
        }
    }

}


int SerialRead::UartRecvData(int fd, char *rcv_buf, int len)

{
    int fs_sel;
    fd_set fs_read;


    struct timeval time;

    FD_ZERO(&fs_read);
    FD_SET(fd, &fs_read);

    time.tv_sec = 10;
    time.tv_usec = 0;

    //使用select实现串口的多路通信
    fs_sel = select(fd + 1, &fs_read, NULL, NULL, &time);
    if(fs_sel)
    {
        len = read(fd, rcv_buf, len);
        qDebug() << "Rec the data:" << rcv_buf;
        return len;

    }
    else
    {
        qDebug() << "No data!";
        return 0;
    }


}

void SerialRead::setUartFd(int fd)
{
    uartFd = fd;
}

int SerialRead::getUartFd()
{
    return uartFd;
}


