#ifndef TTKROUNDPROGRESSWIDGET_H
#define TTKROUNDPROGRESSWIDGET_H

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
 */
class TTK_MODULE_EXPORT TTKRoundProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKRoundProgressWidget)
    Q_PROPERTY(float m_value READ value WRITE setValue)
public:
    enum SwitchFlags
    {
        Null        = 0x0000,
        DefaultText = 0x0001,
        LinearColor = 0x0004,
        DecorateDot = 0x0008,
        OutterCirle = 0x000E,
        Animation   = 0x0010,
        All         = 0xFFFF
    };

    enum class InnerDefaultTextStyle
    {
        Percent     = 0x0001,
        Value       = 0x0002,
        ValueAndMax = 0x0004
    };

    explicit TTKRoundProgressWidget(QWidget *parent = nullptr);

    void setdefault(int startAngle, bool clockWise);
    void setOutterBarWidth(float width);
    void setInnerBarWidth(float width);

    void setRange(float min, float max);
    void setText(float value);

    void setOutterColor(const QColor &outterColor);
    void setInnerColor(const QColor &startColor, const QColor &endColor);
    void setInnerColor(const QColor &startColor);

    void setDefaultTextColor(const QColor &textColor);

    void setControlFlags(int flags);
    void setPrecision(int precision);

    void setInnerDefaultTextStyle(InnerDefaultTextStyle style);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;

    void drawOutterBar(QPainter *painter);
    void drawInnerBar(QPainter *painter);
    void drawDot(QPainter *painter);
    void drawText(QPainter *painter);

    void setValue(float value);
    inline float value() const { return m_value; }

    int m_startAngle;
    bool m_clockWise;
    float m_outterBarWidth, m_innerBarWidth;
    float m_dotX, m_dotY;
    float m_min, m_max, m_value;

    QColor m_outterColor, m_startColor, m_endColor, m_textColor;
    int m_precision;
    float m_squareStart, m_squareWidth;

    quint32 m_controlFlags;
    InnerDefaultTextStyle m_innerDefaultTextStyle;

};

#endif // TTKROUNDPROGRESSWIDGET_H
