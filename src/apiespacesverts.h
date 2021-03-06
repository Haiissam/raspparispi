#ifndef APIESPACESVERTS_H
#define APIESPACESVERTS_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QList>
#include "icon.h"

#include "Abstract_API.h"

class ApiEspacesVerts : public Abstract_API
{
    Q_OBJECT

public:
    ApiEspacesVerts();
    API_index getId() override;
    QPixmap getPixmap() override;

private slots:
    void API_Call();
    void API_Results(QNetworkReply *reply);

public slots:
    void getInfo() override;

private:
    QNetworkAccessManager *manApiEspacesVerts;
    QNetworkReply *reply;
    QJsonDocument document;
    QJsonObject jsonObject;
    QJsonArray jsonArray;
    QJsonValue val;
    QJsonObject jsObj;
    QJsonArray geoloc;
    QList<GeoObj> m_list;

    double longit;
    double lat;

signals:
    void callFinished(QList<Abstract_API::GeoObj>, Abstract_API::API_index);
};

#endif // APIESPACESVERTS_H
