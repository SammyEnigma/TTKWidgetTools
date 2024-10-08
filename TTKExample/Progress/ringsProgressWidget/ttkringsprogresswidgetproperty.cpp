#include "ttkringsprogresswidgetproperty.h"
#include "ttkringsprogresswidget.h"
#include "ttktime.h"
#include <QTimer>

TTKRingsProgressWidgetProperty::TTKRingsProgressWidgetProperty(QWidget *parent)
    : TTKWidgetProperty(parent)
{
    TTK::initRandom();

    m_item = new TTKRingsProgressWidget(this);
    //
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(updateRender()));

    m_timer->setInterval(TTK_DN_S2MS / 2);
    //
    QtProperty *objectItem = m_groupManager->addProperty("QObject");
    //
    QtProperty *classNameItem = m_stringManager->addProperty("ClassName");
    objectItem->addSubProperty(classNameItem);
    m_stringManager->setValue(classNameItem, TTKObjectCast(TTKRingsProgressWidget*, m_item)->className());
    m_stringManager->setReadOnly(classNameItem, true);
    //
    QtProperty *geometryItem = m_rectManager->addProperty("Geometry");
    objectItem->addSubProperty(geometryItem);
    //
    QtProperty *activityItem = m_boolManager->addProperty("Activity");
    m_boolManager->setValue(activityItem, true);
    objectItem->addSubProperty(activityItem);
    //
    m_browser->addProperty(objectItem);
}

TTKRingsProgressWidgetProperty::~TTKRingsProgressWidgetProperty()
{
    delete m_timer;
}

void TTKRingsProgressWidgetProperty::boolPropertyChanged(QtProperty *property, bool value)
{
    if(property->propertyName() == "Activity")
    {
        if(value)
        {
            m_timer->start();
        }
        else
        {
            m_timer->stop();
        }
    }
}

void TTKRingsProgressWidgetProperty::updateRender()
{
    TTKRingsProgressWidget *widget = TTKObjectCast(TTKRingsProgressWidget*, m_item);
    widget->setValue(TTK::random(100) + 1);
}
