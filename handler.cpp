#include "handler.h"

Handler::Handler(QObject *parent) : QObject(parent)
{

}



SENSOR *Handler::getSensor(int position){
    if(position<0 || position >= _sensors.count())
        return Q_NULLPTR;
    return _sensors.at(position);
}

QObject *Handler::getSensorObj(int position){
    if(position<0 || position >= _sensors.count())
        return Q_NULLPTR;
    return _sensors.at(position);
}

QList<SENSOR *> Handler::getSensors(){
    return _sensors;
}

QList<QObject *> Handler::getSensorsObj(){
    QList<QObject *> r;
    QList<SENSOR *>::const_iterator it;
    for(it=_sensors.constBegin();it!=_sensors.constEnd();it++){
        r.append(*it);
    }
    return r;
}

void Handler::appendSensor(){
    SENSOR * s=new SENSOR(this);
    s->ID="Test"+QString::number(_sensors.count());
    s->Name="Name"+QString::number(_sensors.count());
    _sensors.append(s);
    emit sensorChanged();
}
