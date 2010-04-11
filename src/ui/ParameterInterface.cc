#include "ParameterInterface.h"
#include "UASManager.h"
#include "ui_ParameterInterface.h"

ParameterInterface::ParameterInterface(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::parameterWidget)
{
    m_ui->setupUi(this);
    connect(UASManager::instance(), SIGNAL(UASCreated(UASInterface*)), this, SLOT(addUAS(UASInterface*)));
}

ParameterInterface::~ParameterInterface()
{
    delete m_ui;
}

/**
 *
 * @param uas System to add to list
 */
void ParameterInterface::addUAS(UASInterface* uas)
{
    m_ui->vehicleComboBox->addItem(uas->getUASName());
    //if (!paramViews.contains(uas))
    //{
        //uasViews.insert(uas, new UASView(uas, this));
        //listLayout->addWidget(uasViews.value(uas));

    //}
}

/**
 *
 * @param uas System which has the component
 * @param component id of the component
 * @param componentName human friendly name of the component
 */
void ParameterInterface::addComponent(UASInterface* uas, int component, QString componentName)
{

}

void ParameterInterface::receiveParameter(UASInterface* uas, int component, QString parameterName, float value)
{
  // Insert parameter into map

  // Refresh view
}

/**
 * @param uas system
 * @param component the subsystem which has the parameter
 * @param parameterName name of the parameter, as delivered by the system
 * @param value value of the parameter
 */
void ParameterInterface::setParameter(UASInterface* uas, int component, QString parameterName, float value)
{

}

/**
 * @param
 */
void ParameterInterface::commitParameter(UASInterface* uas, int component, QString parameterName, float value)
{

}

/**
 *
 */


void ParameterInterface::changeEvent(QEvent *e)
{
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}