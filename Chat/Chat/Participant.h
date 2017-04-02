#pragma once
#include <boost\asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;	// LEFT OFF FIXING THIS CLASS

class Participant
{
	const char *address;
	tcp::resolver::iterator endpointIterator;
public:
	std::string getAddress();
	tcp::resolver::iterator getIterator();
	//void send(std::string);
	//Participant(tcp::socket*);
	Participant(const char*, const char*, boost::asio::io_service*);
	~Participant();
};

