#ifndef BASE_MODEL
#define BASE_MODEL

#include <QObject>
#include <QAbstractListModel>

class ISoapModel : public QAbstractListModel
{

public:
    virtual ~ISoapModel() = default;
    virtual void load() = 0;
};

#endif //
