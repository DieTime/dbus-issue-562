#include <QCoreApplication>
#include <QDBusAbstractAdaptor>
#include <QDBusConnection>
#include <QDBusMessage>
#include <QDBusReply>
#include <QDebug>

class Example : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "dev.glazkov.DBusIssue562")

public:
    Example(QObject *parent = nullptr)
        : QObject(parent)
    {}

public slots:
    void CallUnknownMethod() {
        QDBusConnection::systemBus().call(QDBusMessage::createMethodCall(
            "org.freedesktop.DBus",
            "/org/freedesktop/DBus",
            "org.freedesktop.DBus",
            "UnknownMethod"
        ));
    }
};

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QDBusConnection conn = QDBusConnection::systemBus();

    Example example;

    if (!conn.registerObject("/", &example, QDBusConnection::ExportAllSlots)) {
        qWarning() << "Failed to register dbus object" << conn.lastError().message();
        return 1;
    }

    if (!conn.registerService("dev.glazkov.DBusIssue562")) {
        qWarning() << "Failed to register dbus service name:" << conn.lastError().message();
        return 1;
    }

    return app.exec();
}

#include "main.moc"
