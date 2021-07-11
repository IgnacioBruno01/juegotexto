#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<windows.h>
using namespace std;
struct Player
{
	char nombrePJ[10];
	int nivel;
	int hp;
	int MaxHP;
	int mana;
	int MaxMP;
	int ataque;
	int ataquemagico;
	int defensa;
	int defensaMagica;
	int velocidadMovimiento;
	int xpActual;
	int xpProximoNivel;
	bool muertePJ;
}Pj;
struct enemigos
{
	string nombre;
	int nivel;
	int hp;
	int MaxHP;
	int mana;
	int MaxMP;
	int ataque;
	int ataqueMagico;
	int defensa;
	int defensaMagica;
	int velocidadMovimiento;
	int xpDropeada;
};
enemigos Goblin;
enemigos Hobgoblin;
enemigos Goblin1;
enemigos Goblin2;
enemigos Goblin3;
Player InicializarPlayer(Player Pj, int nivel, int ataque, int ataquemagico,
	int defensa, int defensaMagica, int hp, int MaxHP, int mana, int MaxMP, int velocidadMovimiento,
	int xpActual, int xpProximoNivel);
enemigos CrearEnemigo(enemigos Enemigo, string nombre, int nivel,
	int ataque, int ataqueMagico, int defensa, int defensaMagica,
	int hp, int MaxHP, int mana, int MaxMP, int velocidadMovimiento, int xpDropeada);
void guardado();
void cargadoDeLaPartida();
void Creditos();
Player LVUp(int xpDropeada, Player Pj);
void GameOver();
Player EstadoDeBatalla(Player Pj, enemigos Enemigo);
vector<string> historia;
int opcion;
void main()
{
	setlocale(LC_ALL, "");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	Goblin = CrearEnemigo(Goblin, "Goblin Joven", 1, 6, 1, 4, 1, 50, 50, 7, 7, 8, 40);
	Goblin1 = CrearEnemigo(Goblin1, "Goblin Adulto", 2, 8, 2, 7, 2, 80, 80, 10, 10, 11, 70);
	Goblin2 = CrearEnemigo(Goblin, "Goblin Joven", 1, 6, 1, 4, 1, 40, 40, 7, 7, 8, 40);
	Goblin3 = CrearEnemigo(Goblin1, "Goblin Adulto", 2, 8, 2, 7, 2, 60, 60, 10, 10, 11, 70);
	Pj = InicializarPlayer(Pj, 1, 6, 2, 4, 2, 100, 100, 50, 50, 11, 0, 100);
	Hobgoblin = CrearEnemigo(Hobgoblin, "+Jefe de los goblins+ Hobgoblin Rakshaka",
		4, 11, 6, 8, 4, 200, 200, 50, 50, 13, 150);

	cout << "MENU" << endl;
	cout << "1: Nueva partida" << endl;
	cout << "2: Cargar partida" << endl;

	cin >> opcion;
	string menuanswer;
	ifstream menu;
	if (opcion == 1)
	{
		menu.open("inicio del juego.txt", ios::in);

		if (menu.fail() == false)
		{
			while (menu.eof() == false)
			{
				string text;
				getline(menu, text);
				historia.emplace_back(text);
			}
		}
		menu.close();
		SetConsoleTextAttribute(hConsole, 2);
		cout << historia[0] << endl;
		Sleep(70);
	}
	else if (opcion == 2)
	{
		cargadoDeLaPartida(); //Al cargar la partida se corrompe el string historia y crashea
	}
	cin.get();
	menu.open("historia del juego.txt", ios::in);
	if (menu.fail() == false)
	{
		while (menu.eof() == false)
		{
			string text;
			getline(menu, text);
			historia.emplace_back(text);
		}
	}
	menu.close();
	cin.get();
	SetConsoleTextAttribute(hConsole, 4);
	cout << "STAGE 1: La caberna de los goblins" << endl;
	cout << "" << endl;
	SetConsoleTextAttribute(hConsole, 5);
	cout << historia[1] << endl;
	Sleep(70);
	cout << "introduce tu nombre" << endl;
	cin >> Pj.nombrePJ;
	cout << historia[2] << Pj.nombrePJ << historia[3] << endl;
	Sleep(70);
	cout << "" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << historia[4] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[5] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[6] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[7] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[8] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[9] << endl;
	Sleep(70);
	cout << "" << endl;
	cout << historia[10] << endl;
	Sleep(70);
	cout << "" << endl;
	system("pause");
	system("cls");
	Pj = EstadoDeBatalla(Pj, Goblin);
	system("pause");
	system("cls");
	if (!Pj.muertePJ)
	{
		cout << "" << endl;
		cout << "" << endl;
		cout << historia[11] << endl;
		Sleep(70);
		cout << "" << endl;
		cout << historia[12] << endl;
		Sleep(70);
		Pj = EstadoDeBatalla(Pj, Goblin2);
		system("pause");
		system("cls");

		if (!Pj.muertePJ)
		{
			cout << "" << endl;
			cout << historia[13] << endl;
			Sleep(70);
			cout << historia[14] << endl;
			Sleep(70);
			cout << historia[15] << endl;
			Sleep(70);
			cout << historia[16] << endl;
			Sleep(70);
			bool tomaDeDecicion = true;
			do
			{
				cin >> opcion;
				cout << "" << endl;
				if (opcion == 1)
				{
					cout << "te sientas contra una de las paredes de la caverna " << endl;
					Pj.hp = Pj.MaxHP;
					cout << "tu hp se a llenado al maximo " << Pj.hp << endl;
					Pj.mana = Pj.MaxMP;
					cout << "tu mp se a llenado al maximo " << Pj.mana << endl;
					tomaDeDecicion = false;
					cout << historia[14] << endl;
					Sleep(70);
					cout << historia[15] << endl;
					Sleep(70);
					cout << historia[16] << endl;
					Sleep(70);
				}
				else if (opcion == 2)
				{
					tomaDeDecicion = true;
				}
				else if (opcion == 3)
				{
					guardado();
					tomaDeDecicion = false;
				}
				else
				{
					cout << "porfavor elige la opcion correcta" << endl;
					tomaDeDecicion = false;
				}
			} while (tomaDeDecicion == false);
			cout << historia[17] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 5);
			cout << historia[18] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 2);
			cout << historia[19] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 5);
			cout << historia[20] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 2);
			cout << historia[21] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 5);
			cout << historia[22] << endl;
			Sleep(70);
			cout << "" << endl;
			SetConsoleTextAttribute(hConsole, 7);
			cout << historia[23] << endl;
			Sleep(70);
			cout << "" << endl;
			cout << historia[24] << endl;
			Sleep(70);
			cout << "" << endl;
			Pj = EstadoDeBatalla(Pj, Goblin1);

			if (!Pj.muertePJ)
			{
				cout << "" << endl;
				cout << historia[25] << endl;
				Sleep(70);
				Pj = EstadoDeBatalla(Pj, Goblin3);
				if (!Pj.muertePJ)
				{
					cout << historia[14] << endl;
					Sleep(70);
					cout << historia[15] << endl;
					Sleep(70);
					cout << historia[16] << endl;
					Sleep(70);
					do
					{
						cin >> opcion;
						if (opcion == 1)
						{
							cout << "te sientas contra una de las paredes de la caverna " << endl;
							Pj.hp = Pj.MaxHP;
							cout << "tu hp se a llenado al maximo " << Pj.hp << endl;
							Pj.mana = Pj.MaxMP;
							cout << "tu mp se a llenado al maximo " << Pj.mana << endl;
							tomaDeDecicion = false;
							cout << historia[14] << endl;
							Sleep(70);
							cout << historia[15] << endl;
							Sleep(70);
							cout << historia[16] << endl;
							Sleep(70);
						}
						else if (opcion == 2)
						{
							tomaDeDecicion = true;
						}
						else if (opcion == 3)
						{
							guardado();
							tomaDeDecicion = false;
						}
						else
						{
							cout << "porfavor elige la opcion correcta" << endl;
							tomaDeDecicion = false;
						}
					} while (tomaDeDecicion == false);
					cout << historia[26] << endl;
					Sleep(70);
					cout << "" << endl;
					cout << historia[27] << endl;
					Sleep(70);
					Pj = EstadoDeBatalla(Pj, Hobgoblin);
					if (!Pj.muertePJ)
					{
						cout << "" << endl;
						cout << historia[28] << endl;
						Sleep(70);
						cout << "" << endl;
						cout << historia[29] << endl;
						Sleep(70);
						cout << "" << endl;
						cout << historia[30] << endl;
						Sleep(70);
						cout << "" << endl;
						cout << historia[31] << endl;
						Sleep(70);
						cout << "" << endl;
						cout << historia[32] << endl;
						Sleep(70);
						cout << "" << endl;
						cout << historia[33] << endl;
						Sleep(70);
						cout << "" << endl;
						Creditos();
					}
				}
			}
		}
	}
}
Player InicializarPlayer(Player Pj, int nivel, int ataque, int ataquemagico,
	int defensa, int defensaMagica, int hp, int MaxHP, int mana, int MaxMP,
	int velocidadMovimiento, int xpActual, int xpProximoNivel)
{
	Pj.nivel = nivel;
	Pj.ataque = ataque;
	Pj.ataquemagico = ataquemagico;
	Pj.defensa = defensa;
	Pj.defensaMagica = defensaMagica;
	Pj.hp = hp;
	Pj.MaxHP = MaxHP;
	Pj.mana = mana;
	Pj.MaxMP = MaxMP;
	Pj.velocidadMovimiento = velocidadMovimiento;
	Pj.xpActual = xpActual;
	Pj.xpProximoNivel = xpProximoNivel;
	Pj.muertePJ = false;
	return Pj;

}
enemigos CrearEnemigo(enemigos Enemigo, string nombre, int nivel,
	int ataque, int ataqueMagico, int defensa, int defensaMagica,
	int hp, int MaxHP, int mana, int MaxMP, int velocidadMovimiento, int xpDropeada)
{
	Enemigo.nombre = nombre;
	Enemigo.nivel = nivel;
	Enemigo.ataque = ataque;
	Enemigo.ataqueMagico = ataqueMagico;
	Enemigo.defensa = defensa;
	Enemigo.defensaMagica = defensaMagica;
	Enemigo.hp = hp;
	Enemigo.MaxHP = MaxHP;
	Enemigo.mana = mana;
	Enemigo.MaxMP = MaxMP;
	Enemigo.velocidadMovimiento = velocidadMovimiento;
	Enemigo.xpDropeada = xpDropeada;
	return Enemigo;
}
Player LVUp(int xpDropeada, Player Pj)
{
	Pj.xpActual += xpDropeada;
	if (Pj.xpActual >= Pj.xpProximoNivel)
	{
		int HP = 25;
		int Mana = 10;
		int velocidadM = 2;
		cout << "Subiste de nivel!" << endl;
		Pj.nivel++;
		Pj.xpProximoNivel *= 1.60;
		Pj.ataque++;
		Pj.ataquemagico++;
		Pj.defensa++;
		Pj.defensaMagica++;
		Pj.MaxHP += HP;
		Pj.MaxMP += Mana;
		Pj.velocidadMovimiento += velocidadM;
		Pj.hp = Pj.MaxHP;
		cout << "tu hp se a llenado al maximo " << Pj.hp << endl;
		Pj.mana = Pj.MaxMP;
		cout << "tu mp se a llenado al maximo " << Pj.mana << endl;
		cout << "al subir de nivel obtienes un aumento en\n. tu ataque +1 = " << Pj.ataque << "\n.tu ataque magico +1 = " << Pj.ataquemagico << "\n.tu denfensa +1 = " << Pj.defensa << "\n. tu defensa magica +1 = " << Pj.defensaMagica << "\n.tu mana maximo +10 =  " << Pj.MaxMP << "\n. tu hp maximo +25 = " << Pj.MaxHP << "\n. y tu velocidad de movimiento +2 = " << Pj.velocidadMovimiento << endl;
		do
		{
			cin.get();
		} while (cin.get() != '\n');
	}
	return Pj;
}
void guardado()
{
	ofstream menu;
	menu.open("partida.sav", ios::out | ios::binary);

	if (menu.fail() == false)
	{
		menu.write((char*)&Pj.nombrePJ, sizeof(Pj.nombrePJ));
		menu.write((char*)&Pj.nivel, sizeof(Pj.nivel));
		menu.write((char*)&Pj.ataque, sizeof(Pj.ataque));
		menu.write((char*)&Pj.ataquemagico, sizeof(Pj.ataquemagico));
		menu.write((char*)&Pj.defensa, sizeof(Pj.defensa));
		menu.write((char*)&Pj.defensaMagica, sizeof(Pj.defensaMagica));
		menu.write((char*)&Pj.hp, sizeof(Pj.hp));
		menu.write((char*)&Pj.mana, sizeof(Pj.mana));
		menu.write((char*)&Pj.MaxHP, sizeof(Pj.MaxHP));
		menu.write((char*)&Pj.velocidadMovimiento, sizeof(Pj.velocidadMovimiento));
		menu.write((char*)&Pj.xpActual, sizeof(Pj.xpActual));
		menu.write((char*)&Pj.xpProximoNivel, sizeof(Pj.xpProximoNivel));
		menu.write((char*)&historia, sizeof(historia));
	}
	menu.close();
}
Player EstadoDeBatalla(Player Pj, enemigos Enemigo)
{

	int EleccionDeBatalla;
	int DañoPJ = Pj.ataque * Pj.nivel * 2.5 - Enemigo.defensa;
	int DañoMagicoPJ = Pj.ataquemagico * Pj.nivel * 11 - Enemigo.defensaMagica;
	int DañoMagicoPJ2 = Pj.ataquemagico * Pj.nivel * 7 - Enemigo.defensaMagica;
	int DañoGoblin = Enemigo.ataque * Pj.nivel * 1.5 - Pj.defensa;
	enum EleccionDeCombate { ataque = 1, mana, escape, guardar };
	bool terminaCombate = true;
	do
	{
		int escapeRand = rand() % 100 + 1;
		int manaRand = rand() % 75;
		cout << "1: Ataque\n2.: Mana\n3.: Escape\n4: Guardar" << endl;
		cin >> EleccionDeBatalla;
		switch (EleccionDeBatalla)
		{
		case EleccionDeCombate::ataque:
			cout << "atacas" << endl;
			cout << "causas " << DañoPJ << " daño a " << Enemigo.nombre << endl;
			Enemigo.hp -= DañoPJ;
			cout << "el hp actual de " << Enemigo.nombre << "es " << Enemigo.hp << endl;
			if (Enemigo.hp >= 1)
			{
				Pj.hp -= DañoGoblin;
				cout << Enemigo.nombre << " te a atacado y causado" << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;

				if (Pj.hp <= 0)
				{
					GameOver();
					terminaCombate = false;
				}
			}
			else if (Enemigo.hp <= 0)
			{
				Enemigo.hp = 0;
				cout << "has derrotado a " << Enemigo.nombre << " y has obtenido " << Enemigo.xpDropeada << " XP" << endl;
				Pj = LVUp(Enemigo.xpDropeada, Pj);
				if (Enemigo.hp <= 0)
				{
					terminaCombate = false;
				}

			}
			break;
		case EleccionDeCombate::mana:
			int respuesta;
			cout << "1: Espada Flamigera (-25 mana)" << "\n. 2: Bola de fuego (-35 mana)" << endl;
			cin >> respuesta;
			switch (respuesta)
			{
			case 1:
				if (Pj.mana >= 25)
				{
					cout << "has utilizado Espada Flamigera" << endl;
					cout << "menos 25 MP" << endl;
					Pj.mana -= 25;
					cout << "mana actual = " << Pj.mana;
					if (manaRand >= 30)
					{
						cout << "has causado " << DañoMagicoPJ << " de daño a " << Enemigo.nombre << endl;
						Enemigo.hp -= DañoMagicoPJ;
						cout << "el hp actual de " << Enemigo.nombre << "es " << Enemigo.hp << endl;
						if (Enemigo.hp >= 1)
						{
							Pj.hp -= DañoGoblin;
							cout << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;
							if (Pj.hp <= 0)
							{
								GameOver();
								terminaCombate = false;
							}
						}
						else if (Enemigo.hp <= 0)
						{
							Enemigo.hp = 0;
							cout << "has derrotado a " << Enemigo.nombre << " y has obtenido " << Enemigo.xpDropeada << " XP" << endl;
							Pj = LVUp(Enemigo.xpDropeada, Pj);
							if (Enemigo.hp <= 0)
							{
								terminaCombate = false;
							}
						}
						else
						{
							Pj.hp -= DañoGoblin;
							cout << "Tu ataque fallo y " << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << "de daño, tu hp ahora es " << Pj.hp << endl;
						}
						break;
					}

				}
				else //Al no tener mana suficiente no pasa por este else if pero se salta al else if del case 2 (Pj.mana < 35)
				{
					cout << "Mana insuficiente, el ataque no se realiza" << endl;
					if (Enemigo.hp >= 1)
					{
						Pj.hp -= DañoGoblin;
						cout << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;
						if (Pj.hp <= 0)
						{
							GameOver();
							terminaCombate = false;
						}
					}
				}

			case 2:
				if (Pj.mana >= 35)
				{
					cout << "has utilizado bola de fuego" << endl;
					cout << "menos 35 MP" << endl;
					Pj.mana -= 35;
					cout << "mana actual = " << Pj.mana;
					if (manaRand >= 40)
					{
						cout << "has causado " << DañoMagicoPJ2 << "de daño a " << Enemigo.nombre << endl;
						Enemigo.hp -= DañoMagicoPJ2;
						cout << "el hp actual de " << Enemigo.nombre << "es " << Enemigo.hp << endl;
						if (Enemigo.hp >= 1)
						{
							Pj.hp -= DañoGoblin;
							cout << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;
							if (Pj.hp <= 0)
							{
								GameOver();
								terminaCombate = false;
							}
						}
						else if (Enemigo.hp <= 0)
						{
							Enemigo.hp = 0;
							cout << "has derrotado a " << Enemigo.nombre << " y has obtenido " << Enemigo.xpDropeada << " XP" << endl;
							Pj = LVUp(Enemigo.xpDropeada, Pj);
							if (Enemigo.hp <= 0)
							{
								terminaCombate = false;
							}
						}
					}
					else
					{
						Pj.hp -= DañoGoblin;
						cout << "Tu ataque fallo y " << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << "de daño, tu hp ahora es " << Pj.hp << endl;
						if (Pj.hp <= 0)
						{
							GameOver();
							terminaCombate = false;
						}
					}
				}
				else if (Pj.mana < 35)
				{
					cout << "Mana insuficiente, el ataque no se realiza" << endl;
					if (Enemigo.hp >= 1)
					{
						Pj.hp -= DañoGoblin;
						cout << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;
						if (Pj.hp <= 0)
						{
							GameOver();
							terminaCombate = false;
						}
					}
				}
			}
			break;

			break;
		case EleccionDeCombate::escape:
			cout << "intentas escapar" << endl;
			if (escapeRand >= 50)
			{
				cout << "has escapado con exito" << endl;
				terminaCombate = false;
			}
			else
			{
				Pj.hp -= DañoGoblin;
				cout << "no has podido escapar " << Enemigo.nombre << " te a atacado y causado " << DañoGoblin << " de daño, tu hp ahora es " << Pj.hp << endl;
				if (Pj.hp <= 0)
				{
					GameOver();
					terminaCombate = false;
				}
			}
			break;
		case EleccionDeCombate::guardar:
			cout << "guardando..." << endl;
			guardado();
			break;
		default: cout << "eleccion incorrecta, por favor elige una de las siguientes opciones" << "\.n" << endl;
			break;
		}
	} while (terminaCombate == true);
	return Pj;

}
void GameOver()
{
	if (Pj.hp <= 0)
	{
		Pj.hp = 0;
		cout << "has muerto" << "\n. Game Over" << endl;
		Pj.muertePJ == true;
		Creditos();
	}
}
void Creditos()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	cout << "Gracias por jugar Leveling Up.!!" << endl;
	cout << "hecho por Ignacio Bruno" << endl;
	cin.get();
}
void cargadoDeLaPartida()
{
	ifstream menu;
	menu.open("partida.sav", ios::in | ios::binary);

	if (menu.fail() == false)
	{
		menu.read((char*)&Pj.nombrePJ, sizeof(Pj.nombrePJ));
		menu.read((char*)&Pj.nivel, sizeof(Pj.nivel));
		menu.read((char*)&Pj.ataque, sizeof(Pj.ataque));
		menu.read((char*)&Pj.ataquemagico, sizeof(Pj.ataquemagico));
		menu.read((char*)&Pj.defensa, sizeof(Pj.defensa));
		menu.read((char*)&Pj.defensaMagica, sizeof(Pj.defensaMagica));
		menu.read((char*)&Pj.hp, sizeof(Pj.hp));
		menu.read((char*)&Pj.mana, sizeof(Pj.mana));
		menu.read((char*)&Pj.MaxHP, sizeof(Pj.MaxHP));
		menu.read((char*)&Pj.velocidadMovimiento, sizeof(Pj.velocidadMovimiento));
		menu.read((char*)&Pj.xpActual, sizeof(Pj.xpActual));
		menu.read((char*)&Pj.xpProximoNivel, sizeof(Pj.xpProximoNivel));
		menu.read((char*)&historia, sizeof(historia));
	}
	menu.close();
}