#include "widget.h"
#include "ui_widget.h"
#include "global.h"
#include <QMessageBox>





Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    runShellProcess = new QProcess( this );
    connect( runShellProcess,SIGNAL(readyRead()),this,SLOT(SLOT_ShellReadWord()) );
    connect( runShellProcess,SIGNAL(finished(int)),this,SLOT( SLOT_ShellFnishProcess()) ) ;

    bool_g_currentCmd = false;

    ui->pushButton_close->setEnabled(false);
    ui->pushButton_open->setEnabled(true);
    ui->pushButton_scan->setEnabled(true);
    ui->pushButton_send->setEnabled(false);
    ui->comboBox_baudrate->setCurrentIndex( CONFIG_BAUDRATE_115200_INDEX );
    ui->comboBox_checkdigit->setCurrentIndex( CONFIG_PARITY_NONE_INDEX );
    ui->comboBox_databits->setCurrentIndex( CONFIG_DATABITS_8_INDEX );
    ui->comboBox_stopbits->setCurrentIndex( CONFIG_STOPBIT_ONE_INDEX );
    ui->comboBox_flowctrl->setCurrentIndex( CONFIG_FLOWCTRL_NONE_INDEX );

    ScanUartList();

    serialReadThread = new SerialRead();
    connect(serialReadThread,SIGNAL(ReadResult(QString)),this,SLOT( SLOT_HandleUartRcvStr(QString)) ) ;

}

Widget::~Widget()
{
    delete ui;
}


void Widget::ScanUartList( void )
{
    // need check the if the uart is availible.
    // Scan ttyUSB0
    ui->comboBox_serialPort->clear();
    for( int i = 0; i < 10; i++ ) {

        bool flag = CheckUartAvailble(i);
        if( flag == true ) {
            if( ui->comboBox_serialPort->currentText().compare("None") == true ) {
                ui->comboBox_serialPort->clear();
            }
            ui->comboBox_serialPort->addItem("ttyUSB"+QString::number(i));
        }else {
            break;
        }
    }

}
void Widget::SLOT_ShellReadWord( void )
{


}

void Widget::SLOT_ShellFnishProcess( void )
{

    runShellProcess->kill();
}

void Widget::on_pushButton_scan_clicked()
{
    ScanUartList();
}

bool Widget::CheckUartAvailble(int comnum)
{

    QString checkcmd = "ls /dev/ttyUSB";
    checkcmd += QString::number(comnum);
    runShellProcess->start(checkcmd) ;
    while( !runShellProcess->waitForFinished() );

    QString terminalOutput = runShellProcess->readAll();
    bool_g_currentCmd = false;
    if( terminalOutput.contains("/dev") ) {
        return true;
    }else{
        return false;
    }
}

void Widget::on_pushButton_open_clicked()
{
    QString str_uartName;
    int serialPortFd;
    char *chars_uartName;
    str_uartName = "/dev/";
    str_uartName += ui->comboBox_serialPort->currentText();

    QByteArray temp = str_uartName.toLatin1();
    chars_uartName = temp.data();

    serialPortFd = ::open( chars_uartName, O_RDWR | O_NOCTTY | O_NDELAY  );


    if( serialPortFd == 0 ) {
        QMessageBox::warning(this,"Error 483","The serial open failed! \n Please try to connect again.");
        return;
    }
    // Restore the serial port blocking state.
    if( fcntl( serialPortFd, F_SETFL, 0 ) < 0 ) {
        QMessageBox::warning(this,"Error 484", "Serial port blocking state is failed,\n Remove the UART from USB and try it again.");
        return ;
    }else{
        qDebug() << "SYSTEM : Serial port blocking state is successful.";
    }
    // Check the serial port wether terminal device.
    if( isatty(STDIN_FILENO) == 0 ) {
        QMessageBox::warning(this,"Error 485","Standard input is not a terminal device.");
        return;
    }else{
        qDebug() << "SYSTEM : The serial port device is terminal device.";
    }
    int_g_serialPortFd = serialPortFd;
    serialReadThread->setUartFd( serialPortFd );

    int baudIndex, databitsIndex, stopbitsIndex, parityIndex, flowctrlIndex;

    baudIndex = ui->comboBox_baudrate->currentIndex();
    switch(baudIndex ) {
    case CONFIG_BAUDRATE_1200_INDEX:
        baudIndex = CONFIG_BAUDRATE_1200_INDEX;
        break;
    case CONFIG_BAUDRATE_2400_INDEX:
        baudIndex = CONFIG_BAUDRATE_2400_INDEX;
        break;
    case CONFIG_BAUDRATE_4800_INDEX:
        baudIndex = CONFIG_BAUDRATE_4800_INDEX;
        break;
    case CONFIG_BAUDRATE_9600_INDEX:
        baudIndex = CONFIG_BAUDRATE_9600_INDEX;
        break;
    case CONFIG_BAUDRATE_19200_INDEX:
        baudIndex = CONFIG_BAUDRATE_19200_INDEX;
        break;
    case CONFIG_BAUDRATE_38400_INDEX:
        baudIndex = CONFIG_BAUDRATE_38400_INDEX;
        break;
    case CONFIG_BAUDRATE_57600_INDEX:
        baudIndex = CONFIG_BAUDRATE_57600_INDEX;
        break;
    case CONFIG_BAUDRATE_115200_INDEX:
        baudIndex = CONFIG_BAUDRATE_115200_INDEX;
        break;
    }


    stopbitsIndex = ui->comboBox_stopbits->currentIndex();
    switch ( stopbitsIndex ) {
    case CONFIG_STOPBIT_ONE_INDEX:
        stopbitsIndex = CONFIG_STOPBIT_ONE_INDEX;
        break;
    case CONFIG_STOPBIT_ONEANDHALF_INDEX:
        stopbitsIndex = CONFIG_STOPBIT_ONEANDHALF_INDEX;
        break;
    case CONFIG_STOPBIT_TWO_INDEX:
        stopbitsIndex = CONFIG_STOPBIT_TWO_INDEX;
        break;
    }

    parityIndex = ui->comboBox_checkdigit->currentIndex();

    switch( parityIndex ) {

    case CONFIG_PARITY_NONE_INDEX:
        parityIndex = CONFIG_PARITY_NONE_INDEX;
        break;

    case CONFIG_PARITY_EVEN_INDEX:
        parityIndex = CONFIG_PARITY_EVEN_INDEX;
        break;

    case CONFIG_PARITY_ODD_INDEX:
        parityIndex = CONFIG_PARITY_ODD_INDEX;
        break;

    case CONFIG_PARITY_SPACE_INDEX:
        parityIndex = CONFIG_PARITY_SPACE_INDEX;
        break;

    case CONFIG_PARITY_MARK_INDEX:
        parityIndex = CONFIG_PARITY_MARK_INDEX;
        break;

    }

    databitsIndex = ui->comboBox_databits->currentIndex();

    switch ( databitsIndex ) {
    case CONFIG_DATABITS_5_INDEX:
        databitsIndex   =   CONFIG_DATABITS_5_INDEX;
        break;

    case CONFIG_DATABITS_6_INDEX:
        databitsIndex   =   CONFIG_DATABITS_6_INDEX;
        break;

    case CONFIG_DATABITS_7_INDEX:
        databitsIndex   =   CONFIG_DATABITS_7_INDEX;
        break;

    case CONFIG_DATABITS_8_INDEX:
        databitsIndex   =   CONFIG_DATABITS_8_INDEX;
        break;
    }

    flowctrlIndex = ui->comboBox_flowctrl->currentIndex();
    switch ( flowctrlIndex ) {
    case CONFIG_FLOWCTRL_NONE_INDEX:
        flowctrlIndex   =   CONFIG_FLOWCTRL_NONE_INDEX;
        break;
    case CONFIG_FLOWCTRL_HARD_INDEX:
        flowctrlIndex   =   CONFIG_FLOWCTRL_HARD_INDEX;
        break;
    case CONFIG_FLOWCTRL_SOFT_INDEX:
        flowctrlIndex   =   CONFIG_FLOWCTRL_SOFT_INDEX;
        break;
    }

    if( SerialPortSetPara(serialPortFd, baudIndex,flowctrlIndex,databitsIndex, stopbitsIndex,parityIndex ) ) {
        QMessageBox::information(this,"info","The " +str_uartName +" serial port has been connected.");

        ui->comboBox_baudrate->setEnabled(false);
        ui->comboBox_checkdigit->setEnabled(false);
        ui->comboBox_databits->setEnabled(false);
        ui->comboBox_flowctrl->setEnabled(false);
        ui->comboBox_serialPort->setEnabled(false);
        ui->comboBox_stopbits->setEnabled(false);
        ui->pushButton_open->setEnabled(false);
        ui->pushButton_close->setEnabled(true);
        ui->pushButton_scan->setEnabled(false);
        ui->pushButton_send->setEnabled(true);
        // start rcv thread.
        serialReadThread->start();

    }else{
        return;
    }



}

bool Widget::SerialPortSetPara(int id, int baudrate, int flowCtrl, int databits, int stopbits, int parity)
{

    struct termios serialPortConfig;

    if( tcgetattr(id, &serialPortConfig ) != 0 ) {
        QMessageBox::warning(this, "Error 487", "This serial ID is error.");
        return false;
    }
    // step 1 :  config the serial control mode , protect the serial port can't be used by other device.
    serialPortConfig.c_cflag    |=      CLOCAL;
    serialPortConfig.c_cflag    |=      CREAD;

    // step 2 : set serial port baud rate.
    switch ( baudrate ) {

    case CONFIG_BAUDRATE_1200_INDEX:
        cfsetispeed( &serialPortConfig, B1200 );
        cfsetispeed( &serialPortConfig, B1200 );
        break;
    case CONFIG_BAUDRATE_2400_INDEX:
        cfsetispeed( &serialPortConfig, B2400 );
        cfsetispeed( &serialPortConfig, B2400 );
        break;
    case CONFIG_BAUDRATE_4800_INDEX:
        cfsetispeed( &serialPortConfig, B4800 );
        cfsetispeed( &serialPortConfig, B4800 );
        break;
    case CONFIG_BAUDRATE_9600_INDEX:
        cfsetispeed( &serialPortConfig, B9600 );
        cfsetispeed( &serialPortConfig, B9600 );
        break;
    case CONFIG_BAUDRATE_19200_INDEX:
        cfsetispeed( &serialPortConfig, B19200 );
        cfsetispeed( &serialPortConfig, B19200 );
        break;
    case CONFIG_BAUDRATE_38400_INDEX:
        cfsetispeed( &serialPortConfig, B38400 );
        cfsetispeed( &serialPortConfig, B38400 );
        break;
    case CONFIG_BAUDRATE_57600_INDEX:
        cfsetispeed( &serialPortConfig, B57600 );
        cfsetispeed( &serialPortConfig, B57600 );
        break;
    case CONFIG_BAUDRATE_115200_INDEX:
        cfsetispeed( &serialPortConfig, B115200 );
        cfsetispeed( &serialPortConfig, B115200 );
        break;
    default:
        qDebug() << "SYSTEM : Serial baud rate set compelet!";
        break;
    }

    // step 3 : set serial port flow ctrl.
    switch (flowCtrl ) {
    case CONFIG_FLOWCTRL_NONE_INDEX:
        serialPortConfig.c_cflag    &=      ~CRTSCTS;
        break;
    case CONFIG_FLOWCTRL_HARD_INDEX:
        serialPortConfig.c_cflag    |=      CRTSCTS;
        break;
    case CONFIG_FLOWCTRL_SOFT_INDEX:
        serialPortConfig.c_cflag    |=      IXON| IXOFF| IXANY;
    default:
        qDebug() << "SYSTEM : Serial port flow ctrl compelet!";
        break;
    }

    // step 4 : set serial port data bits.
    switch (databits) {
    case CONFIG_DATABITS_5_INDEX:
        serialPortConfig.c_cflag    |=      CS5;
        break;
    case CONFIG_DATABITS_6_INDEX:
        serialPortConfig.c_cflag    |=      CS6;
        break;
    case CONFIG_DATABITS_7_INDEX:
        serialPortConfig.c_cflag    |=      CS7;
        break;
    case CONFIG_DATABITS_8_INDEX:
        serialPortConfig.c_cflag    |=      CS8;
        break;
    default:
        break;
    }

    // step 5 : set serial port parity.
    switch (parity) {
    case CONFIG_PARITY_NONE_INDEX:
        serialPortConfig.c_cflag    &=      ~PARENB;
        serialPortConfig.c_iflag    &=      ~INPCK;
        break;
    case CONFIG_PARITY_ODD_INDEX:
        serialPortConfig.c_cflag    |=      (PARODD | PARENB);
        serialPortConfig.c_iflag    |=      INPCK;
        break;
    case CONFIG_PARITY_EVEN_INDEX:
        serialPortConfig.c_cflag    |=      PARENB;
        serialPortConfig.c_cflag    &=      ~PARODD;
        serialPortConfig.c_iflag    |=      INPCK;

        break;
    case CONFIG_PARITY_SPACE_INDEX:
        serialPortConfig.c_cflag    &=      ~PARENB;
        serialPortConfig.c_cflag    &=      ~CSTOPB;
        break;

    }
    // step 6 : set serial port stop bits.
    switch ( stopbits ) {
    case CONFIG_STOPBIT_ONE_INDEX:
        serialPortConfig.c_cflag &= ~CSTOPB;
        break;
    case CONFIG_STOPBIT_TWO_INDEX:
    case CONFIG_STOPBIT_ONEANDHALF_INDEX:
        serialPortConfig.c_cflag |= CSTOPB;
        break;
    }

    // step 7 : other configration.
    serialPortConfig.c_oflag        &=  ~OPOST;
    serialPortConfig.c_lflag        &=  ~( ICANON | ECHO | ECHOE | ISIG );
    serialPortConfig.c_cc[ VTIME ]  = 1;
    serialPortConfig.c_cc[ VMIN ]   = 1;

    tcflush(id, TCIFLUSH);
    if( tcsetattr(id, TCSANOW,&serialPortConfig) != 0 ) {
        QMessageBox::warning(this, "Error 490","The serial initial failed!");
        return false;
    }
    return true;
}

void Widget::on_pushButton_close_clicked()
{
    ::close( int_g_serialPortFd );
    ui->comboBox_baudrate->setEnabled(true);
    ui->comboBox_checkdigit->setEnabled(true);
    ui->comboBox_databits->setEnabled(true);
    ui->comboBox_flowctrl->setEnabled(true);
    ui->comboBox_serialPort->setEnabled(true);
    ui->comboBox_stopbits->setEnabled(true);
    ui->pushButton_open->setEnabled(true);
    ui->pushButton_close->setEnabled(false);
    ui->pushButton_scan->setEnabled(true);
    ui->pushButton_send->setEnabled(false);

    int_g_serialPortFd = 0;
    QMessageBox::information(this, "info" ,"The serial port has been closed.!");
}

bool Widget::UartSendStr(QString str)
{
    char *char_str;
    int sendLength;

    QByteArray temp = str.toLatin1();
    char_str = temp.data();

    sendLength = ::write(int_g_serialPortFd, char_str, str.size() );

    if( sendLength == str.size() ) {
        return true;
    }else {
        return false;
    }
}

void Widget::on_pushButton_send_clicked()
{
    UartSendStr( ui->textEdit_send->toPlainText() );
}

void Widget::on_pushButton_clear_clicked()
{
    serialReadThread->start();
}


void Widget::SLOT_HandleUartRcvStr( QString str )
{
    ui->textBrowser_rec->append(str);
}


