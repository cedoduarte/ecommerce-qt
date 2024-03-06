#ifndef COUNTRYCOMBOBOX_H
#define COUNTRYCOMBOBOX_H

#include <QComboBox>

class CountryComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit CountryComboBox(QWidget *parent = nullptr);
    virtual ~CountryComboBox();
private:
    void init();
};

#endif // COUNTRYCOMBOBOX_H
