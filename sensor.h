#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>

class SENSOR:public QObject{
    Q_OBJECT
    Q_PROPERTY(QString ID       MEMBER ID               NOTIFY sensorChanged)
    Q_PROPERTY(QString Name     MEMBER Name             NOTIFY sensorChanged)
  public:
    SENSOR(QObject * parent=nullptr):QObject(parent){};
    SENSOR(const SENSOR & th):QObject(th.parent()){
        copy(th,*this);
    };
    SENSOR & operator=(const SENSOR &th){
        if(operator==(th)){
            return *this;
        }
        copy(th,*this);
        emit sensorChanged();
        return *this;
    }
    bool operator==(const SENSOR &th){
        return (ID==th.ID &&
                Name==th.Name
                );
    }
    QString ID;
    QString Name;
private:
    void copy(const SENSOR &from, SENSOR &to);
signals:
    void sensorChanged();
};


Q_DECLARE_METATYPE(SENSOR);

#endif // SENSOR_H
