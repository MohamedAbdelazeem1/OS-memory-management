/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "renderarea.h"
#include "mainwindow.h"
#include <QPainter>




//! [0]
RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{
    shape = Rect;
    antialiased = false;
    transformed = false;
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
}
//! [0]

//! [1]
QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}
//! [1]

//! [2]
QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}
//! [2]

//! [3]
void RenderArea::setShape(Shape shape)
{
    this->shape = shape;
}
//! [3]

//! [4]
void RenderArea::setPen(const QPen &pen)
{
    this->pen = pen;
}
//! [4]

//! [5]
void RenderArea::setBrush(const QBrush &brush)
{
    this->brush = brush;
}
//! [5]

//! [6]
void RenderArea::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
}
//! [6]

//! [7]
void RenderArea::setTransformed(bool transformed)
{
    this->transformed = transformed;
}
//! [7]

//! [8]
void RenderArea::paintEvent(QPaintEvent * /* event */)
{

    QRect rect(0, 0, width(), height()/4);

    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QBrush(Qt::green, Qt::BDiagPattern	));
    QFont font = painter.font();
    font.setPixelSize(22);
    painter.setFont(font);
    //painter.drawRect(rect);


    colorGenerator(10);

for(int i=0;i<segments.size();i++){

    if(segments[i][1]=="Hole"){
        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern	));
        painter.drawRect(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt));
        painter.drawText(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt),Qt::AlignCenter,"Hole");
    }
    else if(segments[i][1]=="NA"){
        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(QBrush(Qt::gray, Qt::SolidPattern	));
        painter.drawRect(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt));
        painter.drawText(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt),Qt::AlignCenter,"NA");
    }
    else{
       painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
       painter.setBrush(QBrush(getAndAssignColor(segments[i][0].toInt()), Qt::SolidPattern));
       painter.drawRect(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt));
       painter.drawText(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt),Qt::AlignCenter,"Process:"+segments[i][0]+" Segment:"+segments[i][1]);
    }
    painter.drawText(10,height()*segments[i][2].toInt()/memorySizeInt + 21,segments[i][2]);
    //painter.drawText(20,segments[i][2].toInt()+segments[i][3].toInt()-50,QString(segments[i][2].toInt()+segments[i][3].toInt()));

}



    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    //painter.drawRect(QRect(0,height()/4,width(),height()/2));

    pen = QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    brush = QBrush(Qt::yellow, Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    //painter.drawRect(QRect(0,height()/2,width(),height()*2/4));

    qDebug() <<height() ;



//    for (int x = 0; x < width(); x += 80) {
//        for (int y = 0; y < height(); y += 60) {
//            painter.save();
//            painter.translate(x, y);
////! [10] //! [11]
//            if (transformed) {
//                painter.translate(50, 50);
//                painter.rotate(60.0);
//                painter.scale(0.6, 0.9);
//                painter.translate(-50, -50);
//            }
////! [11]

////! [12]
//            switch (shape) {
//            case Line:
//                painter.drawLine(rect.bottomLeft(), rect.topRight());
//                break;
//            case Rect:
//                painter.drawRect(rect);
//                break;
//            case Path:
//                painter.drawPath(path);
//                break;
//            case Text:
//                painter.drawText(rect,
//                                 Qt::AlignCenter,
//                                 tr("Qt by\nThe Qt Company"));
//                break;
//            case Pixmap:
//                painter.drawPixmap(10, 10, pixmap);
//            }
////! [12] //! [13]
//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}


//! [13]
void RenderArea::draw(){
    QRect rect(0, 0, width(), height()/4);
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QBrush(Qt::green, Qt::BDiagPattern	));
    QFont font = painter.font();
    font.setPixelSize(22);
    painter.setFont(font);
    //painter.drawRect(rect);

    colorGenerator(10);

for(int i=0;i<segments.size();i++){

    if(segments[i][0]=="hole"){
        painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
        painter.setBrush(QBrush(Qt::black, Qt::BDiagPattern	));
        painter.drawRect(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt));
        painter.drawText(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt),Qt::AlignCenter,"Hole");
    }
    else{
       painter.setPen(QPen(Qt::blue, 3, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
       painter.setBrush(QBrush(getAndAssignColor(segments[i][0].toInt()), Qt::SolidPattern));
       painter.drawRect(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt));
       painter.drawText(QRect(0, height()*  segments[i][2].toInt() /memorySizeInt,width(),height()*  (segments[i][3].toInt())/memorySizeInt),Qt::AlignCenter,"Process:"+segments[i][0]+" Segment:"+segments[i][1]);
    }
    painter.drawText(10,height()*segments[i][2].toInt()/memorySizeInt + 21,segments[i][2]);
    //painter.drawText(20,segments[i][2].toInt()+segments[i][3].toInt()-50,QString(segments[i][2].toInt()+segments[i][3].toInt()));

}



    painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    //painter.drawRect(QRect(0,height()/4,width(),height()/2));

    pen = QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin);
    brush = QBrush(Qt::yellow, Qt::SolidPattern);

    painter.setPen(pen);
    painter.setBrush(brush);

    //painter.drawRect(QRect(0,height()/2,width(),height()*2/4));

    qDebug() <<height() ;



//    for (int x = 0; x < width(); x += 80) {
//        for (int y = 0; y < height(); y += 60) {
//            painter.save();
//            painter.translate(x, y);
////! [10] //! [11]
//            if (transformed) {
//                painter.translate(50, 50);
//                painter.rotate(60.0);
//                painter.scale(0.6, 0.9);
//                painter.translate(-50, -50);
//            }
////! [11]

////! [12]
//            switch (shape) {
//            case Line:
//                painter.drawLine(rect.bottomLeft(), rect.topRight());
//                break;
//            case Rect:
//                painter.drawRect(rect);
//                break;
//            case Path:
//                painter.drawPath(path);
//                break;
//            case Text:
//                painter.drawText(rect,
//                                 Qt::AlignCenter,
//                                 tr("Qt by\nThe Qt Company"));
//                break;
//            case Pixmap:
//                painter.drawPixmap(10, 10, pixmap);
//            }
////! [12] //! [13]
//        }
//    }

    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setPen(palette().dark().color());
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));
}
