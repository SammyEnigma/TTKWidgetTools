#ifndef TTKSPLASHSCREEN_H
#define TTKSPLASHSCREEN_H

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

#include <QSplashScreen>
#include "ttkmoduleexport.h"

class QProgressBar;

/*!
 * @author Greedysky <greedysky@163.com>
 */
class TTK_MODULE_EXPORT TTKSplashScreen : public QSplashScreen
{
    Q_OBJECT
    TTK_DECLARE_MODULE(TTKSplashScreen)
public:
    explicit TTKSplashScreen();
    explicit TTKSplashScreen(int mstime);
    explicit TTKSplashScreen(const QPixmap &pixmap, int mstime);
    ~TTKSplashScreen();

    void setWidget(QWidget *main);
    QWidget *widget();

    void setElapseTime(int mstime);
    void setPixmap(const QPixmap &pixmap);

    void start();

Q_SIGNALS:
    void finish();

private Q_SLOTS:
     void updateProgress();

private:
     virtual void mousePressEvent(QMouseEvent *event) override final;

     int m_elapseTime;
     QTimer *m_timer;
     QWidget *m_mainWidget;
     QProgressBar *m_progressBar;

};

#endif // TTKSPLASHSCREEN_H
