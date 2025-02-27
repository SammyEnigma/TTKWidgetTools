#ifndef TTKLOADINGPROGRESSWIDGET_H
#define TTKLOADINGPROGRESSWIDGET_H

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

#include <QTimer>
#include <QWidget>
#include "ttkmoduleexport.h"

struct TTK_MODULE_EXPORT Position
{
    double x;
    double y;
};

/*!
* @author Greedysky <greedysky@163.com>
*/
class TTK_MODULE_EXPORT TTKLoadingProgressWidget : public QWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKLoadingProgressWidget)
public:
    explicit TTKLoadingProgressWidget(QWidget *parent = nullptr);

    void setDotCount(int count);
    void setDotColor(const QColor &color);

    void setMaxDiameter(float max);
    void setMinDiameter(float min);

    void start();
    void stop();

    virtual QSize sizeHint() const override final;

private:
    virtual void paintEvent(QPaintEvent *event) override final;
    virtual void resizeEvent(QResizeEvent *event) override final;

    void drawDot(QPainter *painter);

    int m_index, m_count;
    QColor m_dotColor;
    float m_minDiameter, m_maxDiameter;

    int m_interval;
    QTimer m_timer;

    QList<float> m_ranges;
    QList<Position> m_dots;

};

#endif // TTKLOADINGPROGRESSWIDGET_H
