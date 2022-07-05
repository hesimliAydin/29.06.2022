#pragma once

namespace HeaderFiles
{
	struct LogIn
	{
		string username = "";
		string password = "";
		bool admin = false;

		LogIn() = default;

		LogIn(string username, string password) {
			this->username = username;
			this->password = password;
		}




	};
}


