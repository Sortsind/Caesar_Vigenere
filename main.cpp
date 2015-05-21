#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct koord
{
	int a;
	int b;
};

int main(int argc, char *argv[])
{
	int a = 0;

	cout << "1. Caesar" << endl << "2. Vigenere" << endl;
	cin >> a;
	system("cls");
	switch(a)
	{
	case 1:
		{
			int a1 = 0;
			cout << "1. Code" <<  endl <<"2. Decode" << endl;
			cin >> a1;
			system("cls");
			switch(a1)
			{
			case 1:
				{
					cout << "Source code:" << endl;

					char text[100000];
					char ch;

					std::ifstream f("input.txt");
					int i = 0;
					if(f)
					{
						while(f.get(ch))
						{
							std::cout << ch;
							text[i]=ch;
							i++;
						}
					}

					int key = 0;

					cout << endl <<"Enter key:   ";
					cin>>key;
					key=(key+256)%256;

					f.seekg(0);
					
					int count = i;
					for(int i=0; i < count; i++)
					{
						text[i] = text[i] + key;
					}

					std::ofstream outfile("output.txt");
					for(int i=0; i < count; i++)
					{
						outfile.put(text[i]);
					}

					cout << "Coded string has been saved in output.txt";
					system("pause");
					return 0;
				}
			case 2:
				{
					cout << "Coded string" << endl;

					char text[100000];
					char ch;

					std::ifstream f("output.txt");
					int i = 0;
					if(f)
					{
						while(f.get(ch))
						{
							std::cout << ch;
							text[i] = ch;
							i++;
						}
					}

					int key = 0;

					cout << endl << "Enter key:   ";
					cin >> key;

					key=(key+256)%256;

					f.seekg(0);
					int count = i;

					for(int i = 0; i < count; i++)
					{
						text[i] = text[i] - key;
					}

					std::ofstream outfile("input!.txt");
					for(int i = 0; i < count; i++)
					{
						outfile.put(text[i]);
					}

					cout << "Source string has been saved in input!.txt";
					system("pause");
					return 0;
				}
			}
		}
	case 2: 
		{
			int a2 = 0;
			char key[300];
			char tmp[300];
			char line[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
			char tabula_recta[26][26];
			char vhod[300];
			int count = 0;
			int LenOfKey = 0;
			int ProverkaKey = 0;
			int ind = 1;
			cout << "1. Code" <<  endl <<"2. Decode" << endl;
			cin >> a2;
			system("cls");
			switch(a2)
			{
			case 1:
				{

					
					int TmpRect = 0;
					for(int i = 0; i < 26; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							TmpRect = i + j;
							if (TmpRect >= 26)
							{
								TmpRect = TmpRect % 26;
							}
							tabula_recta[i][j] = line[TmpRect];
						}
					}

					FILE *file;
					char *infile = "input.txt";
					file = fopen(infile,"r");

					char ch = 0;
					int i = 0;
					while(ch != EOF)
					{
						ch = getc(file);
						if (ch!='\n' && ch!=EOF)
						{
							vhod[i] = ch;
							i++;
						}
					}
					cout << "Length of file:   " << i << endl;
					count = i;

					
					char* a = 0;
					a = new char[i];

				
					fseek(file,0,SEEK_SET);

					cout << "Enter key:   ";
					cin >> key;
					LenOfKey = strlen(key);
					for (int i = 0; i < LenOfKey; i++)
					{
						tmp[i] = key[i];
					}

					while(ProverkaKey < count)
					{
						for (int i = 0; i < LenOfKey; i++)
						{
							key[i + ProverkaKey] = tmp[i];
						}
						ProverkaKey = ind*LenOfKey;
						ind++;
					}

				
					koord nabor[100];
					for(int i = 0; i < count; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							if (line[j] == vhod[i])
							{
								nabor[i].a = j;
								//cout << nabor[i].a << "  ";
							}
						}
					}

					for(int i = 0; i < count; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							if (line[j] == key[i])
							{
								nabor[i].b = j;
								//cout << nabor[i].b << "  ";
							}
						}
					}
					
					
					char Coding[100];
					for(int ii = 0; ii < count; ii++)
					{
						for(int i = 0; i < 26; i++)
						{
							if (i == nabor[ii].a)
							{
								for(int j = 0; j < 26; j++)
								{
									if (j == nabor[ii].b)
									{
										Coding[ii] = tabula_recta[i][j];
									}
								}
							}
						}
					}
					FILE *file2;
					char *outfile = "output.txt";
					file2 = fopen(outfile,"w");
					for(int i = 0; i < count; i++)
					{
						putc(Coding[i],file2);
					}
					cout << "Coded string has been saved in output.txt";
					system("pause");
					return 0;
				}
			case 2:
				{
					ind = 1;
					int TmpRect = 0;
					for(int i = 0; i < 26; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							TmpRect = i + j;
							if (TmpRect >= 26) TmpRect = TmpRect % 26;
							tabula_recta[i][j] = line[TmpRect];
						}
					}

					FILE *file;
					char *infile = "output.txt";
					file = fopen(infile,"r");

					char ch = 0;
					int i = 0;
					while(ch != EOF)
					{
						ch = getc(file);
						if (ch!='\n' && ch!=EOF)
						{
							vhod[i] = ch;
							i++;
						}
					}

					cout<<"Length of file:   "<<i;
					count = i;

					char* a = 0;
					a = new char[i];

					fseek(file,0,SEEK_SET);

					cout << endl << "Enter key:   ";
					cin >> key;
					LenOfKey = strlen(key);
					for (int i = 0; i < LenOfKey; i++)
					{
						tmp[i] = key[i];
					}

					while(ProverkaKey<count)
					{
						for (int i = 0; i < LenOfKey; i++)
						{
							key[i + ProverkaKey] = tmp[i];
						}
						ProverkaKey = ind*LenOfKey;
						ind++;
					}

				
					koord nabor[100];
					for(int i = 0; i < count; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							if (line[j] == key[i])
							{
								nabor[i].a = j;
							}
						}
					}

					char Coding[100];
					for(int ii = 0; ii < count; ii++)
					{
						for(int i = 0; i < 26; i++)
						{
							if (i == nabor[ii].a)
							{
								for(int j = 0; j < 26; j++)
								{
									if (tabula_recta[i][j] == vhod[ii])
									{
										Coding[ii] = j;
									}
								}
							}
						}
					}

					FILE *file2;
					char *outfile = "input!.txt";
					file2 = fopen(outfile,"w");
					for(int i = 0; i < count; i++)
					{
						for(int j = 0; j < 26; j++)
						{
							if (Coding[i]==j)
							{
								putc(line[j],file2);
							}
						}
					}
					cout << "Source string has been saved in input!.txt";
					system("pause");
					return 0;
				}
			}
		}
	}
}