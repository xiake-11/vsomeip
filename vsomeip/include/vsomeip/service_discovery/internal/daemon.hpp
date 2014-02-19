//
// daemon.hpp
//
// Author: 	Lutz Bichler
//
// This file is part of the BMW Some/IP implementation.
//
// Copyright © 2013, 2014 Bayerische Motoren Werke AG (BMW).
// All rights reserved.
//

#ifndef	 VSOMEIP_DAEMON_DAEMON_HPP
#define VSOMEIP_DAEMON_DAEMON_HPP

#include <boost/asio/io_service.hpp>
#include <boost/asio/local/stream_protocol.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>

#include <vsomeip/primitive_types.hpp>
#include <vsomeip/endpoint.hpp>
#include <vsomeip/receiver.hpp>
#include <vsomeip/service_discovery/service_entry.hpp>
#include <vsomeip/service_discovery/internal/service_info.hpp>
#include <vsomeip/service_discovery/internal/service_registry.hpp>

namespace vsomeip {

class service;

namespace service_discovery {

class daemon : public receiver {
public:
	static daemon * get_instance();

	void init(int a_argc, char **a_argv);
	void start();
	void stop();

	void receive(const message_base *_message);

private:
	daemon();
	void run_service();
	void consume_request(const entry &, endpoint *);
	void send_offer_service(service_info *, endpoint *);

	void set_loggers(const std::string& _logger_configuration);

private:
	service_registry *registry_;
	std::string registry_path_;

	vsomeip::service *tcp_daemon_;
	vsomeip::service *udp_daemon_;

	int port_;
	bool is_service_discovery_mode_;
	bool is_virtual_mode_;
	bool is_running_;

	// Loggers
	bool use_console_;
	bool use_file_;
	bool use_dlt_;

	boost::log::sources::severity_logger<
		boost::log::trivial::severity_level > log_;
	boost::log::trivial::severity_level loglevel_;

	boost::asio::io_service is_;
	boost::asio::local::stream_protocol::acceptor acceptor_;
};

} // namespace service_discovery
} // namespace vsomeip

#endif // VSOMEIP_DAEMON_DAEMON_HPP
