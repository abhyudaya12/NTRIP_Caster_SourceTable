#include <QtCore>
#include <QtNetwork>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    QString userAgent = "MountPointScript";
    QString server = "rts2.ngii.go.kr";
    int port = 2101;

    qDebug() << "herre1";
    QTcpSocket socket;
    qDebug() << "herre2";
    socket.connectToHost(server, port);

    if (!socket.waitForConnected(5000)) {
        qDebug() << "Connection failed!";
        return -1;
    }

    qDebug() << "herre3";
    QString requestHeader = "GET / HTTP/1.0\r\n"
        "User-Agent: NTRIP Client/1.0\r\n"
        "Connection: close\r\n"
        "\r\n";

    qDebug() << "**********************";
    qDebug() << "*  request_header    *";
    qDebug() << "**********************";
    qDebug() << requestHeader;

    socket.write(requestHeader.toUtf8());
    if (!socket.waitForBytesWritten(5000)) {
        qDebug() << "Writing to socket failed!";
        return -1;
    }

    QByteArray response;
    while (socket.waitForReadyRead(5000)) {
        response.append(socket.readAll());
    }

    qDebug() << "**********************";
    qDebug() << "*     response       *";
    qDebug() << "**********************";
    qDebug() << response;

    socket.close();
    return 0;
}