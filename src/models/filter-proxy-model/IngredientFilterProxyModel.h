#ifndef INGREDIENTFILTERPROXYMODEL_H
#define INGREDIENTFILTERPROXYMODEL_H

#include <QObject>
#include <QSortFilterProxyModel>
#include "model_roles.h"

class IngredientFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString searchText READ searchText WRITE setSearchText NOTIFY searchTextChanged)

public:
    explicit IngredientFilterProxyModel(QObject *parent = nullptr)
        : QSortFilterProxyModel(parent)
    {
        setFilterCaseSensitivity(Qt::CaseInsensitive);
    }

    QString searchText() const { return _searchText; }

    void setSearchText(const QString &text)
    {
        if (_searchText == text)
            return;

        _searchText = text;
        invalidateFilter();
        emit searchTextChanged();
    }

signals:
    void searchTextChanged();

protected:
    /** Поиск по имени */
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override
    {
        if (_searchText.trimmed().isEmpty())
            return true;

        QModelIndex index = sourceModel()->index(sourceRow, 0, sourceParent);
        QString name = sourceModel()->data(index, Roles::NameRole).toString();

        return name.contains(_searchText, Qt::CaseInsensitive);
    }

    /** Сортировка по имени */
    bool lessThan(const QModelIndex &source_left, const QModelIndex &source_right) const override
    {
        QString leftName  = sourceModel()->data(source_left, Roles::NameRole).toString();
        QString rightName = sourceModel()->data(source_right, Roles::NameRole).toString();
        return QString::localeAwareCompare(leftName, rightName) < 0;
    }

private:
    QString _searchText;
};

#endif //
