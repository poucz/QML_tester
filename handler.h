#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>

#include "sensor.h"

class Handler : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QList<SENSOR *> sensors   MEMBER ID               NOTIFY sensorChanged)
    Q_PROPERTY(QList<SENSOR *> sensors   READ getSensors    NOTIFY sensorChanged)
    Q_PROPERTY(QList<QObject *> sensorsObj  READ getSensorsObj NOTIFY sensorChanged)

public:
    explicit Handler(QObject *parent = nullptr);

    Q_INVOKABLE SENSOR * getSensor(int position);
    Q_INVOKABLE QObject * getSensorObj(int position);

    Q_INVOKABLE QList<SENSOR *> getSensors();
    Q_INVOKABLE QList<QObject *> getSensorsObj();


    Q_INVOKABLE void appendSensor();
private:
    QList<SENSOR *> _sensors;
signals:
    void sensorChanged();
};

#endif // HANDLER_H

