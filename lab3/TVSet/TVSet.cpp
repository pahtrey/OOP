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
	this->m_isTurnedOn = true;
}

void CTVSet::TurnOff()
{
	this->m_isTurnedOn = false;
}

bool CTVSet::IsTurnedOn()const
{
	return this->m_isTurnedOn;
}

bool CTVSet::SelectChannel(int channelNumber)
{
	if (!this->IsTurnedOn())
	{
		return false;
	}

	this->m_selectedChannelNumber = channelNumber;

	return true;
}

int CTVSet::GetSelectedChannelNumber()const
{
	if (!this->IsTurnedOn())
	{
		return 0;
	}

	return this->m_selectedChannelNumber;
}