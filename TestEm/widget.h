#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "global.h"
#include <QProcess>
#include <QString>
#include <QDebug>
#include <QThread>

#include "serialread.h"


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


// function
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
// value
public :

public slots:

    void SLOT_ShellReadWord( void );
    void SLOT_ShellFnishProcess( void );




private slots:
    void on_pushButton_scan_clicked();

    void on_pushButton_open_clicked();

    void on_pushButton_close_clicked();

    void on_pushButton_send_clicked();

    void on_pushButton_clear_clicked();

    void SLOT_HandleUartRcvStr( QString );
private:
    Ui::Widget *ui;
    void ScanUartList( void );
    bool CheckUartAvailble( int comnum );
    bool SerialPortSetPara( int id , int baudrate, int flowCtrl, int databits, int stopbits, int parity );
    bool UartSendStr( QString str );
    // value
private:
    QProcess *runShellProcess;
    QString qstr_g_shellOutput;
    bool bool_g_currentCmd;
    int int_g_serialPortFd;
    SerialRead *serialReadThread;
};




#endif // WIDGET_H
