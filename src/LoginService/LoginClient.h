#include <stdlib.h>
#include <string>
#include <cstdint>

#define string std::string

/*	LoginClient represents the client that will be used to authenticate a user
*	
*
*/

class LoginClient
{
public:
	enum AUTH_RESULT
	{
		AUTH_SUCCEEDED = 0,
		AUTH_FAILED,
		AUTH_BANNED,
		AUTH_LOCKED
	};

	LoginClient();
	~LoginClient();

	// getters & setters
	uint64_t getAccountId() { return mAccountId; }
	void setAccountId(uint64_t inAccId) { mAccountId = inAccId; }
	uint32_t getLoginClientId() { return mLoginClientId; }
	void setLoginClientId(uint32_t inLoginClientId) { mLoginClientId = inLoginClientId; }
	string getVersion() { return mVersion; }
	void setVersion(string inVersion) { mVersion = inVersion; }
	string getUserName() { return mUserName; }
	void setUserName(string inUser) { mUserName = inUser; }
	string getPassword() { return mPassword; } 
	void setPassword(string inPass) { mPassword = inPass; }
	string getAuthToken() { return mAuthToken; }
	void setAuthToken(string inToken) { mAuthToken = inToken; }

private:
	uint64_t mAccountId;
	uint32_t mLoginClientId;
	string mVersion;
	string mUserName;
	string mPassword;
	string mAuthToken;
	AUTH_RESULT mState;
}