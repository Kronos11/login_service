// Copyright (c) 2010 ANH Studios. All rights reserved.
// Use of this source code is governed by a GPL-style license that can be
// found in the COPYING file.
#ifndef LOGINCLIENT_UNITTEST_H_
#define LOGINCLIENT_UNITTEST_H_

#include "LoginClient.h"
#include "LoginService.h"
#include <gtest.h>


namespace {

class LoginService_unittest : public testing::Test
{
public:
	LoginClient* client;
	virtual void SetUp()
	{
		client = new LoginClient();
		client->setAccountId(1);
		client->setLoginClientId(1);
		client->setUserName("Test");
		client->setPassword("swganh");
		client->setVersion("0.1.0");
	}
};

TEST_F(LoginService_unittest, handleLoginRequestSuccess)
{
	LoginService service;
	BaseEvent* ev;
	service.handleLoginRequest(client, ev);
}

TEST_F(LoginService_unittest, handleLoginRequestFailureByVersion)
{
	LoginService service;
	client->setVersion("x.x.x");
	BaseEvent* ev;
	service.handleLoginRequest(client, ev);
}
} //namespace

int main (int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
#endif