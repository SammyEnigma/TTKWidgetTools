#ifndef TTKPERCENTMETERWIDGET_H
#define TTKPERCENTMETERWIDGET_H

/***************************************************************************
 * This file is part of the TTK Widget Tools project
 * Copyright (C) 2015 - 2025 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include <QWidget>
#include "ttkmoduleexport.h"

/*!
* @author Greedysky <greedysky@163.com>
*         feiyangqingyun <feiyangqingyun@163.com>
*/
class TTK_MODULE_EXPORT TTKPercentMeterWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKPercentMeterWidget)
public:
    explicit TTKPercentMeterWidget(QWidget *parent = nullptr);

    void setRange(double minValue, double maxValue);

    void setMinValue(double minValue);
    void setMaxValue(double maxValue);

    void setValue(double value);

    void setPrecision(int precision);
    void setScaleMajor(int scaleMajor);
    void setScaleMinor(int scaleMinor);
    void setStartAngle(int startAngle);
    void setEndAngle(int endAngle);

    void setArcColor(const QColor &arcColor);
    void setScaleColor(const QColor &scaleColor);
    void setScaleNumColor(const QColor &scaleNumColor);

    void setTitle(const QString &title);
    void setTextColor(const QColor &textColor);
    void setTitleColor(const QColor &titleColor);

    void setBaseColor(const QColor &baseColor);
    void setBackgroundColor(const QColor &backgroundColor);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;

    void drawArc(QPainter *painter);
    void drawCircle(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawValue(QPainter *painter);
    void drawTitle(QPainter *painter);

    double m_minValue;
    double m_maxValue;
    double m_value;
    int m_precision;
    int m_scaleMajor;
    int m_scaleMinor;
    int m_startAngle;
    int m_endAngle;

    QColor m_arcColor;
    QColor m_scaleColor;
    QColor m_scaleNumColor;
    QColor m_textColor;
    QColor m_titleColor;
    QColor m_baseColor;
    QColor m_backgroundColor;

    QString m_title;

};

#endif  // TTKPERCENTMETERWIDGET_H
