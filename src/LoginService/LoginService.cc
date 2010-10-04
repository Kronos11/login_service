// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.

#include "LoginService.h"
#include "anh\event_dispatcher.h"

LoginService::LoginService()
{
	// load version

}
LoginService::~LoginService()
{
	//unload
}
void LoginService::handleLoginRequest(LoginClient* client, BaseEvent* bEvent)
{
	// verify client and event
	if (!client && bEvent)
	{
		// send error
		return;
	}
	// connect to symphony web-api
}

void LoginService::handleDeleteCharacter(LoginClient* client, BaseEvent* bEvent)
{

}