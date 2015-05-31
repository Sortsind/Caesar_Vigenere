#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int file_size(ifstream &file);
void entry_file(ifstream &file, char *text);

struct koord
{
	int a;
	int b;
};

int main(int argc, char *argv[])
{
	if (argc != 7)
	{
		cout << "Incorrect string! Enter arguments as: 1/2 - Caesar/Vigenere 1/2 - code/decode input output key input! \n";
		system("pause");
		return 0;
	}

	switch (*argv[1])
	{
	case '1':
	{
				switch (*argv[2])
				{
				case '1':
				{
							ifstream f;
							f.open(argv[3], ios::in);
							ofstream o;
							o.open(argv[4], ios::out);
							ifstream k;
							k.open(argv[5], ios::in);

							int key;
							int size = file_size(f);
							char *text = new char[size];
							entry_file(f, text);

							k >> key;
							key = (key + 256) % 256;

							for (int i = 0; i < size; i++)
								text[i] = text[i] + key;

							for (int i = 0; i < size; i++)
								o.put(text[i]);

							return 0;
				}
				case '2':
				{
							ifstream f;
							f.open(argv[4], ios::in);
							ifstream k;
							k.open(argv[5], ios::in);
							ofstream o;
							o.open(argv[6], ios::out);

							int key;
							int size = file_size(f);
							char *text = new char[size];
							entry_file(f, text);

							k >> key;
							key = (key + 256) % 256;

							for (int i = 0; i < size; i++)
								text[i] = text[i] - key;

							for (int i = 0; i < size; i++)
								o.put(text[i]);

							return 0;
				}
				}
	}
	case '2':
	{
			  char line[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
			  char tabula_recta[26][26];
			  int TmpRect = 0;
			  for (int i = 0; i < 26; i++)
			  {
				  for (int j = 0; j < 26; j++)
				  {
					  TmpRect = i + j;
					  if (TmpRect >= 26)
						  TmpRect = TmpRect % 26;
					  tabula_recta[i][j] = line[TmpRect];
				  }
			  }
			  switch (*argv[2])
			  {
			  case '1':
			  {
						ifstream file;
						file.open(argv[3], ios::in);
						ofstream file2;
						file2.open(argv[4], ios::out);
						ifstream k;
						k.open(argv[5], ios::in);

						int size = file_size(file);
						char *vhod = new char[size];
						entry_file(file, vhod);
						
						int size_key = file_size(k);
						char *key = new char[size];
						entry_file(k, key);

						for (int i = size_key; i < size; i++)
							key[i] = key[i - size_key];

						koord *nabor = new koord[size];

						for (int i = 0; i < size; i++)
						{
							for (int j = 0; j < 26; j++)
							{
								if (line[j] == vhod[i])
									nabor[i].a = j;
								if (line[j] == key[i])
									nabor[i].b = j;
							}
						}

						char *Coding = new char[size];
						for (int ii = 0; ii < size; ii++)
						{
							for (int i = 0; i < 26; i++)
							{
								if (i == nabor[ii].a)
								{
									for (int j = 0; j < 26; j++)
									{
										if (j == nabor[ii].b)
											Coding[ii] = tabula_recta[i][j];
									}
								}
							}
						}

						for (int i = 0; i < size; i++)
							file2.put(Coding[i]);

						return 0;
			  }
			  case '2':
			  {
						ifstream file;
						file.open(argv[4], ios::in);
						ofstream file2;
						file2.open(argv[6], ios::out);
						ifstream k;
						k.open(argv[5], ios::in);

						int size = file_size(file);
						char *vhod = new char[size];
						entry_file(file, vhod);

						int size_key = file_size(k);
						char *key = new char[size];
						entry_file(k, key);

						for (int i = size_key; i < size; i++)
							key[i] = key[i - size_key];

						koord *nabor = new koord[size];

						for (int i = 0; i < size; i++)
						{
							for (int j = 0; j < 26; j++)
							{
								if (line[j] == key[i])
									nabor[i].a = j;
							}
						}

						char *Coding = new char[size];
						for (int ii = 0; ii < size; ii++)
						{
							for (int i = 0; i < 26; i++)
							{
								if (i == nabor[ii].a)
								{
									for (int j = 0; j < 26; j++)
									{
										if (tabula_recta[i][j] == vhod[ii])
											Coding[ii] = j;
									}
								}
							}
						}

						for (int i = 0; i < size; i++)
						{
							for (int j = 0; j < 26; j++)
							{
								if (Coding[i] == j)
									file2.put(line[j]);
							}
						}

						return 0;
			  }
			  }
	}
	}
}

int file_size(ifstream &file)
{
	char ch;
	int i = 0;
	if (file)
	{
		while (file.get(ch))
			i++;
	}
	file.clear();
	file.seekg(0, ios::beg);
	return i;
}

void entry_file(ifstream &file, char *text)
{
	char ch;
	int i = 0;
	if (file)
	{
		while (file.get(ch))
		{
			text[i] = ch;
			i++;
		}
	}
}
