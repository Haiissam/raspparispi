#ifndef APIBORNESWIFI_H
#define APIBORNESWIFI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QList>
#include "icon.h"

#include "Abstract_API.h"

class ApiBornesWifi : public Abstract_API
{

    Q_OBJECT

public:
    ApiBornesWifi();
    API_index getId() override;
    QPixmap getPixmap() override;

private slots:
    void API_Call();
    void API_Results(QNetworkReply *reply);

public slots:
    void getInfo() override;

private:
    QNetworkAccessManager *API_AccessWifi;
    QNetworkReply *currentReply;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray arr;
    QList<GeoObj> m_list;

    double latitude;
    double longitude;

signals:
    void callFinished(QList<Abstract_API::GeoObj>, Abstract_API::API_index);
};

#endif // APIBORNESWIFI_H
