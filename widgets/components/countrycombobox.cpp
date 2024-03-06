#include "countrycombobox.h"
#include "../../shared/constants.h"

CountryComboBox::CountryComboBox(QWidget *parent)
    : QComboBox(parent)
{
    init();
}

CountryComboBox::~CountryComboBox()
{
}

void CountryComboBox::init()
{
    for (const QString &countryName : Constants::COUNTRY_LIST)
    {
        addItem(countryName);
    }
}
