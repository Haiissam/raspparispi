#include "Abstract_API.h"


Abstract_API::Abstract_API(QObject *parent) : QObject(parent)
{

}

// Aide au Debug, si nécessaire. Cette fonction peut être customisée

void Abstract_API::debug(QList <GeoObj> list)
{
    for (auto i : list) {
        qDebug() << i.longitude;
        qDebug() << i.latitude;
        qDebug() << i.pixmap;
        //qDebug() << i.id;
    }
}



//void Abstract_API::debug(QList <GeoObj> list, API_index id)
//{
//    for (auto i : list) {
//        qDebug() << i.longitude;
//        qDebug() << i.latitude;
//        qDebug() << i.pixmap;
//    }
//    id = EVENEMENTS;
//}

