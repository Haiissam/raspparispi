#ifndef THEATRE_H
#define THEATRE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QVariantHash>
#include <QJsonObject>
#include "Abstract_API.h"
#include "addrtocoord.h"

class theatre : public Abstract_API
{
    Q_OBJECT

public:
    theatre();
    API_index getId() override;
    QPixmap getPixmap() override;

public slots:
    void getInfo() override;
    void theatreAPI_Call();
    void readJsonTheatre();

private:
    QNetworkAccessManager * manager;
    QNetworkRequest request;
    QNetworkReply * reply;
    addrToCoord *coordHelper;
    double longitude;
    double latitude;
    QList<GeoObj> m_list;

signals:
    void callFinished(QList<Abstract_API::GeoObj>, Abstract_API::API_index);

};

#endif // THEATRE_H
