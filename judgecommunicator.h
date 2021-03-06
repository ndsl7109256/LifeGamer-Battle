#ifndef JUDGECOMMUNICATOR_H
#define JUDGECOMMUNICATOR_H

#include <QObject>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QString>

class JudgeCommunicator : public QObject
{
    Q_OBJECT
public:
    explicit JudgeCommunicator(QObject *parent = nullptr);
    QNetworkReply *resultReply;

signals:

public slots:
    void sendMap(QString map);
    void sendResult(QString result);
    void waitResultFinished(int timeout);

private:
    QNetworkAccessManager *judgeServer;
    QUrl host;
};

#endif // JUDGECOMMUNICATOR_H
