// TVSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

using namespace std;

CTVSet::CTVSet()
{
}

CTVSet::~CTVSet()
{
}

void CTVSet::TurnOn()
{
}

void CTVSet::TurnOff()
{
}

bool CTVSet::IsTurnedOn()const
{
	return m_isTurnedOn;
}

bool CTVSet::SelectChannel(int channelNumber)
{
	return false;
}

int CTVSet::GetSelectedChannelNumber()const
{
	if (!this->IsTurnedOn())
	{
		return 0;
	}

	return this->m_selectedChannelNumber;
}