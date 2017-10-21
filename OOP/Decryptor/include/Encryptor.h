#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <string>

using namespace std;

class Encryptor
{
	private:
		string sEncrypted;
		string sDecrypted;
	public:
		//Constructor
		Encryptor()
		{
			sEncrypted = "";
			sDecrypted = "";
		}
		//Destructor
		virtual ~Encryptor() { }
        //Methods
		string decipher(string sCiphered, int iKey)
		{
            string sResult;
            char cAux;

			for (int i = 0; i < sCiphered.length(); i++)
			{
                sResult+=" ";
			}

            for (int j = 0; j < sCiphered.length(); j++)
			{
                cAux = sCiphered[j] - iKey;

                if (cAux >= 32)
				{
                    sResult[j] = cAux;
				}
				else
				{
					cAux = ((sCiphered[j] - 32) + 127) - iKey;

					if (cAux < 127)
					{
						sResult[j] = cAux;
					}
				}
			}

			return sResult;
		}

		string cipher(string sUnEncrypted, int iKey)
		{
            string sResult;

			for (int i = 0; i < sUnEncrypted.length(); i++)
			{
                sResult+=" ";
			}

			for (int j = 0; j < sUnEncrypted.length(); j++)
			{
                if( (sUnEncrypted[j] + iKey) > 126)
				{
                    sResult[j] = 32 + ((sUnEncrypted[j] + iKey) - 127);
				}
				else
				{
                    sResult[j] = sUnEncrypted[j] + iKey;
				}
			}

			return sResult;
		}
};

#endif // ENCRYPTOR_H
