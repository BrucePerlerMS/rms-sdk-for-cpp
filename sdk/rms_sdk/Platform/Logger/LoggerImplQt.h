/*
 * ======================================================================
 * Copyright (c) Microsoft Open Technologies, Inc.  All rights reserved.
 * Licensed under the MIT License.
 * See LICENSE.md in the project root for license information.
 * ======================================================================
*/

#ifndef _LOGGERQTIMPL_H_
#define _LOGGERQTIMPL_H_

#include "Logger.h"
#include <fstream>

class LoggerImplQt : public Logger {
public:
    ~LoggerImplQt();

protected:
    virtual void append(const std::string& prefix, const std::string& record) override;

private:
    LoggerImplQt();
    friend class Logger;
    std::ofstream stream_;
};

#endif // _LOGGERQTIMPL_H_