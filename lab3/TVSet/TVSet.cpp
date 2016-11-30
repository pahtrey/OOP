// TVSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TVSet.h"

using namespace std;

CTVSet::CTVSet():m_selectedChannelNumber(m_channelRange::min)
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

	if (channelNumber < this->m_channelRange::min || channelNumber > this->m_channelRange::max)
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