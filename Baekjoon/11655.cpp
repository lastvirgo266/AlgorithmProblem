#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

inline char Rot(char alp)
{
	if ((alp >= 'a' && alp <= 'z') || (alp >= 'A' && alp <= 'Z'))
	{
		if (((int)alp >= 65) && ((int)alp<= 90))
			return ((alp + 13 - 65) % 26) + 65;


		else
			return ((alp + 13 - 97) % 26) + 97;



	}

	else
		return alp;


}

int main()
{

	string word;
	getline(cin, word);


	for (int i = 0; i < word.size(); i++)
		printf("%c", Rot(word[i]));



	return 0;



}