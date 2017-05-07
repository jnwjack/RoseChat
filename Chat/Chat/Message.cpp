#include "Message.h"

const char* Message::getData() const
{
	return data;
}

char* Message::getData()
{
	return data;
}

std::size_t Message::getLength() const
{
	return HEADER_LENGTH + messageBodyLength;
}

const char* Message::getBody() const
{
	return data + HEADER_LENGTH;
}

char* Message::getBody()
{
	return data + HEADER_LENGTH;
}

std::size_t Message::bodyLength() const
{
	return messageBodyLength;
}

void Message::bodyLength(std::size_t newLength)
{
	messageBodyLength = newLength;
	if (messageBodyLength > MAX_BODY_LENGTH)
		messageBodyLength = MAX_BODY_LENGTH;
}

bool Message::decodeHeader()
{
	char header[HEADER_LENGTH + 1] = "";
	strncat_s(header, data, HEADER_LENGTH);
	messageBodyLength = std::atoi(header);
	if (messageBodyLength > MAX_BODY_LENGTH)
	{
		messageBodyLength = 0;
		return false;
	}
	return true;
}

void Message::encodeHeader()
{
	char header[HEADER_LENGTH + 1] = "";
	sprintf_s(header, "%4d", static_cast<int>(messageBodyLength));
	std::memcpy(data, header, HEADER_LENGTH);
}


Message::Message() : messageBodyLength(0)
{
}


Message::~Message()
{
}
