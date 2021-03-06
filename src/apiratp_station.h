#ifndef APIRATP_STATION_H
#define APIRATP_STATION_H

#include "Abstract_API.h"
#include "apiratp_global.h"
#include "stoppoint.h"
#include "transport.h"
#include "uiratp.h"

#include <QDialog>
#include <QDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ApiRatp_Station : public Abstract_API
{
public:
    ApiRatp_Station();
    API_index getId() override;
    QPixmap getPixmap() override;

    Uiratp *uiratp;

    QNetworkAccessManager *managerStation;
    QNetworkRequest *requestStation;
    QNetworkReply *replyStation;

    void DoStationRequest();
private:
    void PeriStifJson();

public slots:
    void getInfo() override;

private slots:
    void replyFinishedStation();
    QJsonDocument LoadJson(QString fileName);

};

#endif // APIRATP_STATION_H
