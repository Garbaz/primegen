#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> v, unsigned int tableWidth);
vector<int> primeList(long unsigned int limit);

int main()
{
	vector<int> primes = primeList(100);
	
	
	printVector(primes, 4);
}

void printVector(vector<int> v, unsigned int tableWidth)
{
	unsigned int c = 0;
	
	for(long unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\t";
		c++;
		if(c >= tableWidth){
			cout << endl;
			c = 0;
		}
	}
	cout << "\n----------------------------" << endl;
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
		
		vector<int> tmpVec;
		
		
		for(long unsigned int i = 2; i < limit; i++)
		{
//			cout << i <<" marked ? " << marked[i] << endl;
			if(!marked[i])
			{
				tmpVec.push_back(i);
			}
		}
		
		cout << "before p=" << p << " applied the vector looked like this:\n" << endl;
		printVector(tmpVec, 10);
		
		for(long unsigned int i = 2*p; i < limit; i+=p)
		{
			marked[i] = true;
//			cout << "Marked " << i << endl;
		}
		
		int lastP = p;
		
		for(long unsigned int i = p+1; i < limit/2; i++)
		{
			if(!marked[i])
			{
				p = i;
//				cout << "p = " << i << endl;
				break;
			}
		}
		
		if(lastP == p)
		{
//			cout << "last p (" << lastP << ") is equal tu current p" << endl;
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
