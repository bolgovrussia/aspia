//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#ifndef CLIENT__STATUS_WINDOW_PROXY_H
#define CLIENT__STATUS_WINDOW_PROXY_H

#include "base/macros_magic.h"
#include "client/status_window.h"

#include <memory>

namespace base {
class TaskRunner;
} // namespace base

namespace client {

class StatusWindowProxy : public std::enable_shared_from_this<StatusWindowProxy>
{
public:
    StatusWindowProxy(std::shared_ptr<base::TaskRunner> ui_task_runner,
                      StatusWindow* status_window);
    ~StatusWindowProxy();

    void dettach();

    void onStarted(const std::u16string& address, uint16_t port);
    void onStopped();
    void onConnected();
    void onDisconnected(net::Channel::ErrorCode error_code);
    void onAccessDenied(net::ClientAuthenticator::ErrorCode error_code);

private:
    std::shared_ptr<base::TaskRunner> ui_task_runner_;
    StatusWindow* status_window_;

    DISALLOW_COPY_AND_ASSIGN(StatusWindowProxy);
};

} // namespace client

#endif // CLIENT__STATUS_WINDOW_PROXY_H
