#include "customizeButton.h"

#include <QDebug>

CustomizeButton::CustomizeButton(const QString &iconPath, const QString &hoverIconPath, const QString &toggledIconPath, const QString &pressedIconPath, QWidget *parent)
    : QPushButton(parent), defaultIcon(iconPath), hoverIcon(hoverIconPath), toggledIcon(toggledIconPath), pressedIcon(pressedIconPath) {
    setIcon(defaultIcon);
}

void CustomizeButton::enterEvent(QEnterEvent *event) {
    setIcon(hoverIcon);
    QPushButton::enterEvent(event);
}

void CustomizeButton::leaveEvent(QEvent *event) {
    setIcon(defaultIcon);
    QPushButton::leaveEvent(event);
}

void CustomizeButton::mousePressEvent(QMouseEvent *event) {
    setIcon(pressedIcon); // Set the pressed icon when the mouse is pressed
    qDebug() << "pressed";
    isToggled = !isToggled; // Toggle the state
    QPushButton::mousePressEvent(event);
}

void CustomizeButton::mouseReleaseEvent(QMouseEvent *event) {
    if (isToggled) {
        setIcon(toggledIcon); // Show the toggled icon if the button is in the toggled state
    } else {
        setIcon(defaultIcon); // Show the default icon when the mouse is released
    }
    QPushButton::mouseReleaseEvent(event);
}
