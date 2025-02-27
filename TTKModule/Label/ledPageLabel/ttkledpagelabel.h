#ifndef TTKLEDPAGELABEL_H
#define TTKLEDPAGELABEL_H

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
class TTK_MODULE_EXPORT TTKLedPageLabel : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKLedPageLabel)
public:
    explicit TTKLedPageLabel(QWidget *parent = nullptr);

    void setForegroundColor(const QColor &color);
    void setBackgroundColor(const QColor &color);
    void setLineColor(const QColor&);

    void setScale(float scale);
    void setText(const QString &text);
    void setFontSize(int size);

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;

    void drawBackground(QPainter *painter);
    void drawText(QPainter *painter);
    void drawLine(QPainter *painter);

    QColor m_foregroundColor, m_backgroundColor, m_lineColor;
    QString m_text;
    float m_width, m_height, m_scale;
    int m_fontSize;

};

#endif // TTKLEDPAGELABEL_H
