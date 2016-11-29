#pragma once
#include "stdafx.h"

class CTVSet
{
public:
	CTVSet();
	~CTVSet();

	void TurnOn();
	void TurnOff();
	bool IsTurnedOn()const;

	bool SelectChannel(int channelNumber);
	int GetSelectedChannelNumber()const;

private:
	bool m_isTurnedOn = false;
	int m_selectedChannelNumber = 1;
};