//
// Created by Liam Ross on 15/02/2023.
//

#ifndef LOGGER_RECORD_H
#define LOGGER_RECORD_H

#include <map>
#include <sstream>
#include <iomanip>
#include <typeinfo>
#include "Time.h"
#include "Formatter.h"
#include "Color.h"

namespace logger {
    class Formatter;

    enum Severity : unsigned short {
        start,
        end,
        info,
        debug,
        warning,
        error,
        fatal
    };

    class Record {
        friend std::ostream& operator<<(std::ostream& os, const Record& record);

    private:
        std::string clasName;
        Time t;
        std::string message;
        Severity severity;

    public:
        Record(const std::string& message, Severity severity);
        Record(const std::string& message, Severity severity, const std::string& className);

        static std::string getSeverityText(Severity s) ;
        static std::string getColor(Severity s) ;

        std::string getClassName() const;
        Time getTime() const;
        std::string getMessage() const;
        Severity getSeverity() const;
    };
}


#endif //LOGGER_RECORD_H
