#pragma once
#include <boost\asio.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::tcp;	// LEFT OFF FIXING THIS CLASS

class Participant
{
	tcp::socket socket;
	std::string address;
public:
	std::string getAddress();
	void send(std::string);
	Participant(tcp::socket*);
	~Participant();
};

