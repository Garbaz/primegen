/**INFO:
 * This is a simple programm to generate a list of primes using the sieve of eratosthenes.
 * NOTE: This piece of software is NOT optimized in any way. If time is an important factor to you,
 * this specific implementation of the algorithm isn't for you. Furthermore this may be filled with
 * "bad-habit-code"; So don't use this as an orientation to write your own software! I would rather
 * recommend to you to go online search for better examples of (pseudo-)code of this algorithm.
 * And yes I know that this isn't the fastest algorithm avaible to generate prime-number lists, but
 * this one is easy to code, understand and use. If you are interested in a better/faster way of generating
 * prime numbers I would suggest to search for the "sieve of atkin".
 * 
 * "Designed" and coded by Garbaz based on an explenation of the algorithm from wikipedia.
 * (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
 * 
 * [I am to blame for any misconceptions, bad coding habits and english mistakes]
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

vector<int> primeList(long unsigned int limit);

int main(int argc, char* argv[])
{
	
	if(argc == 2)
	{
		string arg1 = argv[1];
		if(arg1 == "-h" || arg1 == "--help")
		{
			cout << "\nThis is a simple programm to generate a list of primes using the sieve of eratosthenes.\n" << endl;
			cout << "Usage:\t\"" << argv[0] << " NUMBER SEPERATIONTYPE\"\n" << endl;
			cout << "|Possible seperation types:" << endl;
			cout << "|\"TN10\" : Tabuator seperated, new line after every 10 numbers\n"
				 << "|\"TN5\" : Same as TN10, but new line after every 5 numbers\n"
				 << "|\"SPACE\" : Simply a space between the numbers. No tabs or new lines\n" << endl;
			cout << "or:\t\"" << argv[0] << " OPTION\"\n" << endl;
			cout << "|Possible Options:" << endl;
			cout << "|\"-h\" : Shows this help message.\n"
				 << "|\"--help\" : Shows this help message.\n" << endl;
			cout << "To print the result to a textfile just add \"> file.txt\" at the end.\n" << endl;
			cout << "NOTE: This piece of software is NOT optimized in any way. If time is an important factor to you, " <<
					"this specific implementation of the algorithm isn't for you. In general I would recommend everybody " <<
					"to write all algorithms themselfs, or at least the simple ones.\n" << endl;
			return 0;
		}
	}
	else if(argc == 3)
	{
		string arg2 = argv[2];
		long unsigned int limit = atoi(argv[1]);
		
		vector<int> primes = primeList(limit);
		
		if(arg2 == "TN10")
		{
			for(long unsigned int i = 0; i < primes.size(); i++)
			{
				if(i % 10 == 0)
				{
					if(i>0) cout << "\n";
				}
				else
				{
					cout << "\t";
				}
				cout << primes[i];
			}
		}
		else if(arg2 == "TN5")
		{
			for(long unsigned int i = 0; i < primes.size(); i++)
			{
				if(i % 5 == 0)
				{
					if(i>0) cout << "\n";
				}
				else
				{
					cout << "\t";
				}
				cout << primes[i];
			}
		}
		else if(arg2 == "SPACE")
		{
			for(long unsigned int i = 0; i < primes.size(); i++)
			{
				cout << primes[i] << " ";
			}
		}
		
		cout << endl;
	}
	else
	{
		cerr << "Expected \t\"" << argv[0] << " NUMBER SEPERATIONTYPE\"" << endl;
		cerr << "or\t\t\"" << argv[0] << " OPTION\"" << endl;
		cerr << "Too many or not enough arguments!" << endl;
		cerr << "Type \"" << argv[0] << " --help\" for further information." << endl;
		return -1;
	}
	
	return 0;
}

vector<int> primeList(long unsigned int limit)
{
	limit++;
	bool marked[limit];
	
	for(long unsigned int i = 0; i < limit; i++)
	{
		marked[i] = false;
	}
	
	int p = 2;
	
	for(;;)
	{
		
		for(long unsigned int i = 2*p; i < limit; i+=p)
		{
			marked[i] = true;
		}
		
		int lastP = p;
		
		for(long unsigned int i = p+1; i < limit/2; i++)
		{
			if(!marked[i])
			{
				p = i;
				break;
			}
		}
		
		if(lastP == p)
		{
			vector<int> retVal;
			for(long unsigned int i = 2; i < limit; i++)
			{
				if(!marked[i])
				{
					retVal.push_back(i);
				}
				
			}
			return retVal;
		}
	}
}
