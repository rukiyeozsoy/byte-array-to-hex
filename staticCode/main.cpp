#include <QDebug>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>

const int BUFFER_SIZE = 3 * sizeof(qint32); // Buffer size boyutu

//qint32 değerini bir QByteArray'ya dönüştürme
void int32_Paketle(QByteArray& byteArray, qint32 value)
{
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << value;
}

//QByteArray türündeki veriyi hexadecimal string olarak temsil etme
QString byteArrayToHex(const QByteArray& byteArray)
{
    QString hexString;
    for (int i = 0; i < byteArray.size(); ++i) {
        hexString += QString("%1").arg(static_cast<quint8>(byteArray[i]), 2, 16, QChar('0'));
    }
    return hexString;
}

//qint32 türündeki verileri QByteArray'ya paketleme işlemi
//paketlenmiş veriyi hexadecimal formatta konsola basma
int main()
{
    QByteArray Buffer;
    Buffer.resize(BUFFER_SIZE);

    qint32 value1 = 3680;
    qint32 value2 = 50;
    qint32 value3 = -680;

    int32_Paketle(Buffer, value1);
    int32_Paketle(Buffer, value2);
    int32_Paketle(Buffer, value3);

    QString hexString = byteArrayToHex(Buffer);
    qDebug() << hexString;

    return 0;
}
