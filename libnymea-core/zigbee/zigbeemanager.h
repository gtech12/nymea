/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*
* Copyright 2013 - 2020, nymea GmbH
* Contact: contact@nymea.io
*
* This file is part of nymea.
* This project including source code and documentation is protected by
* copyright law, and remains the property of nymea GmbH. All rights, including
* reproduction, publication, editing and translation, are reserved. The use of
* this project is subject to the terms of a license agreement to be concluded
* with nymea GmbH in accordance with the terms of use of nymea GmbH, available
* under https://nymea.io/license
*
* GNU General Public License Usage
* Alternatively, this project may be redistributed and/or modified under the
* terms of the GNU General Public License as published by the Free Software
* Foundation, GNU version 3. This project is distributed in the hope that it
* will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along with
* this project. If not, see <https://www.gnu.org/licenses/>.
*
* For any further details and any questions please contact us under
* contact@nymea.io or see our FAQ/Licensing Information on
* https://nymea.io/license/faq
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef ZIGBEEMANAGER_H
#define ZIGBEEMANAGER_H

#include <QObject>

#include <zigbeenetworkmanager.h>

namespace nymeaserver {

class ZigbeeManager : public QObject
{
    Q_OBJECT
public:
    explicit ZigbeeManager(QObject *parent = nullptr);

    bool available() const;
    bool enabled() const;

    ZigbeeNetwork *zigbeeNetwork() const;

    void createZigbeeNetwork(const QString &serialPort, qint32 baudrate, Zigbee::BackendType backend);

private:
    ZigbeeNetwork *m_zigbeeNetwork = nullptr;

signals:
    void zigbeeNetworkChanged(ZigbeeNetwork *zigbeeNetwork);

};

}

#endif // ZIGBEEMANAGER_H
