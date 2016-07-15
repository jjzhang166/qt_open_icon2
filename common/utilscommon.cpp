#include "utilscommon.h"

namespace utilscommon {

/**
 * @brief setShadow 设置窗体阴影效果
 * @param w 窗体指针
 * @param blurRadius 阴影清晰度，越小越清晰
 * @param dx x方向阴影位置和偏移量，正值在右方，值越大偏移越大
 * @param dy y方向阴影位置和偏移量，正值在下方，值越大偏移越大
 * @return
 */
void setShadow(QWidget *w, qreal blurRadius, qreal dx, qreal dy)
{
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(blurRadius);
    shadow->setColor(QColor(0, 0, 0, 160));
    shadow->setOffset(dx, dy);
    w->setGraphicsEffect(shadow);
}

/**
 * @brief 从文件读出内容并转为QString
 * @param path 文件路径
 * @return 正确返回内容，错误返回QString()
 */
QString readFile(const QString &path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qDebug()<<"open "<<path<<" err";
        return QString();
    }else{
        return QLatin1String(file.readAll());
    }
}

}
