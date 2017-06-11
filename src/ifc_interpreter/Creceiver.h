#pragma once

class IFCWALKER_EXTERNAL Creceiver
{
public:
	Creceiver(void);
	~Creceiver(void);

	char* (*m_Function)(SdaiString Str);
};