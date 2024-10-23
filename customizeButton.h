#ifndef CUSTOMIZEBUTTON_H
#define CUSTOMIZEBUTTON_H

#include <QPushButton>
#include <QIcon>

class CustomizeButton : public QPushButton {
    Q_OBJECT
public:
    explicit CustomizeButton(const QString &iconPath, const QString &hoverIconPath, const QString &toggledIconPath, const QString &pressedIconPath, QWidget *parent = nullptr);

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QIcon defaultIcon;
    QIcon hoverIcon;
    QIcon toggledIcon;
    QIcon pressedIcon; // Icon for pressed state
    bool isToggled = false; // Track the toggle state
};

#endif // CUSTOMBUTTON_H
