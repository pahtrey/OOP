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
	enum m_channelRange
	{
		min = 1,
		max = 99
	};
	bool m_isTurnedOn = false;
	int m_selectedChannelNumber;
};