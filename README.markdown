Login Service
=============

##Design Directions##

The following are a list of general ideas that have been noted for the direction of this project. These are subject to change during the initial design and implementation phases of the project. This document will be fleshed out along the way as concrete decisions on the design are made.

*   ###Application lifetime controlled via the server_directory library###

    The server directory library allows a process (in this case the login service) to participate within a multi-clustered environment. The library provides an easy facility to check the cluster's current status and the current global timestamp. These two pieces of data can be used to move the whole cluster forward at a standard pace and to assist in cluster controlled startup/shutdown.

*   ###Authentication via web api###

    Several services outside of just the basic client login need to be able to authenticate with the service. These include the web based portal (used for signup and account management) and the client launcher (assists with managing multiple client instances/versions). By exposing authentication as part of the web api it makes it easy for any external application to login with the appropriate information and receive an authentication token. This authentication token can then be used in subsequent requests to access information such as cluster status and character data.

    The web api will be built as a symfony plugin/bundle and should be easy enough to port to other languages. This allows us to bypass reinventing the wheel for things like input validation and data caching. Consider using this type of api for all data access so that the web server can serve as the data layer/cache layer between the server and whatever external data store is used.

*   ###Convert packets to game events/messages###

    Incoming network messages should be converted to game events. By doing this many options are opened up as custom "listeners" can be added in the future which can monitor various statistics. Ideas for a current set of statics to track for the login server would be consecutive failed logins, number of successful logins, frequency of player logins, etc.
