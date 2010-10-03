#include "LoginClient.h"
#include <list>
#include <map>

class LoginService
{
public:
	LoginService();
	~LoginService();

	/**
	 *	Handles the Login Request from the client
	 *	
	 */
	void handleLoginRequest();
	/**
	 *	Handles the request from the client to Delete Character
	 *
	 */
	void handleDeleteCharacter();

private:
	/**
	 *	Checks to make sure the client is valid
	 *	\param[out] bool The result of the check
	 *  \param[in] LoginClient The Client sending the message
	 */
	bool isValidClient(LoginClient* client);
	/**
	 *	Calls the symphony service to create the Login Auth Token
	 *	\param[in] user The user
	 *	\param[in] pass the Password for the user
	 */
	string generateAuthToken(const string& user, const string& pass);
	/**
	 *	Sends the Galaxy List to the Client
	 *
	 */
	void sendGalaxyList();
	/**
	 *	Sends the Cluster Status to the Client
	 *
	 */
	void sendClusterStatus();
	/**
	 *	Sends appropriate error message to the Client
	 *
	 */
	void sendLoginErrorMessage();
	/**
	 *	Gets the Character List to send back to the LoginClient
	 *
	 */
	string getCharacterList();
	/**
	 *	Gets the cluster status from the Server Directory
	 *
	 */

	
public:
	uint32_t mLastClusterPule;
}