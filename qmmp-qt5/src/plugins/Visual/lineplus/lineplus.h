/* =================================================
 * This file is part of the TTK Music Player qmmp plugin project
 * Copyright (c) 2015 - 2017 Greedysky Studio
 * All rights reserved!
 * Redistribution and use of the source code or any derivative
 * works are strictly forbiden.
   =================================================*/
#ifndef LINEPLUS_H
#define LINEPLUS_H

#include <QWidget>
#include <qmmp/visual.h>

class QTimer;
class QPainter;
class QPaintEvent;
class QHideEvent;
class QShowEvent;

class LinePlus : public Visual
{
    Q_OBJECT
public:
    LinePlus( QWidget *parent = 0);
    virtual ~LinePlus();

public slots:
    void start();
    void stop();

private slots:
    void timeout();
    void readSettings();
    void writeSettings();
    void changeColor();

private:
    void clear();
    virtual void hideEvent (QHideEvent *e);
    virtual void showEvent (QShowEvent *e);
    void paintEvent(QPaintEvent *e);
    void contextMenuEvent(QContextMenuEvent *e);

    void process();
    void draw(QPainter *p);

    QList<QColor> m_colors;
    QTimer *m_timer;
    double *m_intern_vis_data, *m_peaks;
    double m_peaks_falloff, m_analyzer_falloff;
    float m_left_buffer[QMMP_VISUAL_NODE_SIZE];
    float m_right_buffer[QMMP_VISUAL_NODE_SIZE];
    int *m_x_scale, m_cols, m_rows;
    bool m_running;

    QSize m_cell_size;

};

#endif