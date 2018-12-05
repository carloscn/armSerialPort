#ifndef SERIALREAD_H
#define SERIALREAD_H

#include <QThread>
#include <QString>

class SerialRead : public QThread
{
    Q_OBJECT

signals:
   void ReadResult( QString str );

public slots:

private:
    int uartFd;

protected:

    virtual void run();

public:

    SerialRead();
    void setUartFd( int fd );
    int getUartFd( void );
    int UartRecvData( int fd, char *rcv_buf, int len );

};

#endif // SERIALREAD_H
