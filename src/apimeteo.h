#ifndef APIMETEO_H
#define APIMETEO_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QList>

#include "Abstract_API.h"
#include "meteo.h"
#include "pollution.h"
#include "prevision.h"
#include "indiceuv.h"



class ApiMeteo : public Abstract_API
{
    Q_OBJECT

public:
    ApiMeteo();
    int getId() override;
    QPixmap getPixmap() override;

private slots:
    void API_Call();
    void API_Results(QNetworkReply *reply);
    void getInfo() override;

private:
    QNetworkAccessManager *API_Access;
    QNetworkReply *currentReply;
    QJsonDocument doc;
    QJsonObject obj;
    QJsonArray arr;
    QList<GeoObj> m_list;
    meteo *m_meteo;
    Pollution *p_pollution;
    IndiceUV *i_indice;
    Prevision *pm_prevision;

    double longitude;
    double latitude;
  signals:
    void callFinished(QList<Abstract_API::GeoObj>);

};


#endif // APIMETEO_H