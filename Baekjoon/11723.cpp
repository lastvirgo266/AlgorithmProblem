#include<iostream>
#include<string>
#include<map>

using namespace std;
int S[21]{0};

inline void Add(short number){ S[number] = 1; }
inline void Remove(short number){ S[number] = 0; }
inline int Check(short number){ return (S[number]); }
inline void Toggle(short number){ S[number] = !S[number]; }
inline void All(){ fill_n(S, 21, 1); }
inline void Empty(){ fill_n(S, 21, 0); }

int main()
{
	int M;

	map<string, int> m;
	m.insert(pair<string, int>("add", 0));
	m.insert(pair<string, int>("remove", 1));
	m.insert(pair<string, int>("check", 2));
	m.insert(pair<string, int>("toggle", 3));
	m.insert(pair<string, int>("all", 4));
	m.insert(pair<string, int>("empty", 5));

	// Input Line //
	cin >> M;


	// Compute Line //
	while (M>=1)
	{
		string command = "";
		short number;
		cin >> command;

		//예외처리
		if (!(command.compare("all")) || !(command.compare("empty")));
			
		else
			cin >> number;

		switch (m[command])
		{

			case 0:
					Add(number);
					break;

			case 1:
					Remove(number);
					break;

			case 2:
					cout << Check(number) << endl;
					break;

			case 3:
					Toggle(number);
					break;

			case 4:
					All();
					break;

			case 5:
					Empty();
					break;
		}

		M--;


	}

	



}