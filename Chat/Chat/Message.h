#pragma once

#include <cstdio>
#include <cstdlib>
#include <cstring>

const int HEADER_LENGTH = 4;
const int MAX_BODY_LENGTH = 512;

class Message
{
	char data[HEADER_LENGTH + MAX_BODY_LENGTH];
	std::size_t messageBodyLength;
public:
	const char* getData() const;
	char* getData();
	std::size_t getLength() const;
	const char* getBody() const;
	char* getBody();
	std::size_t bodyLength() const;
	void bodyLength(std::size_t);
	bool decodeHeader();
	void encodeHeader();
	Message();
	~Message();

	const static int HEADER_LENGTH = 4;
	const static int MAX_BODY_LENGTH = 512;
};

