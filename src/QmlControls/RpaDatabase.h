#ifndef RPADATABASE_H
#define RPADATABASE_H

#include <QSqlRecord>
#include <QSqlField>
#include <QtSql>
#include <QObject>
#include <QSqlDatabase>
#include <QTableView>

class RpaDatabase : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit RpaDatabase(QObject *parent = nullptr);

    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void callSql(QString queryString);

    Q_INVOKABLE void addData(const QString &TYPE,const QString &MODEL_NAME, const QString &DRONE_NAME, const QString &UIN);

    Q_INVOKABLE void existingUIN(const QString &uin);


private :
    void generateRoleNames();
    QHash<int, QByteArray> m_roleNames;


signals:
    void uin_record_found();

};

#endif // RPADATABASE_H
