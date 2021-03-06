#ifndef APIFONTAINES_H
#define APIFONTAINES_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>
#include"Abstract_API.h"

class apifontaines : public Abstract_API
{
    Q_OBJECT
public:
    apifontaines();
    API_index getId() override;
    QPixmap getPixmap()override;
private slots:
    void API_call();
    void API_results(QNetworkReply *reply);
    void getInfo()override;
private:
    QNetworkAccessManager *API_access;
    QNetworkReply *currentReply;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray arr;
    QList<GeoObj>m_list;
    double latitude;
    double longitude;
    QString modele;
    QString adresse;
    QString ouv_hiver;
    QString sdf;
    QString en_service;
    int drink;

    signals:
    void callFinished(QList<Abstract_API::GeoObj>, Abstract_API::API_index);

};

#endif // APIFONTAINES_H
