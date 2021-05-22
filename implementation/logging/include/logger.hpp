// Copyright (C) 2014-2017 Bayerische Motoren Werke Aktiengesellschaft (BMW AG)
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef VSOMEIP_LOGGER_HPP
#define VSOMEIP_LOGGER_HPP

#include <string>
#include <iostream>

#include <vsomeip/export.hpp>

namespace vsomeip {

class VSOMEIP_IMPORT_EXPORT logger {
public:
//    static std::shared_ptr<logger> get();

    virtual ~logger() {
    }

//    virtual boost::log::sources::severity_logger_mt<
//            boost::log::trivial::severity_level> & get_internal() = 0;
};

#define VSOMEIP_FATAL std::cout << std::endl << " FATAL " << std::endl
#define VSOMEIP_ERROR std::cout << std::endl<< " ERROR " << std::endl
#define VSOMEIP_WARNING std::cout << std::endl<< " WARNING " << std::endl
#define VSOMEIP_INFO std::cout << std::endl<< " INFO " << std::endl
#define VSOMEIP_DEBUG std::cout << std::endl << " DEBUG " << std::endl
#define VSOMEIP_TRACE std::cout << std::endl << " TRACE " << std::endl

} // namespace vsomeip

#endif // VSOMEIP_LOGGER_HPP
