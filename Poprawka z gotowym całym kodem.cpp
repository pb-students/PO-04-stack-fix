
///author: Najlepszy Wyraz Twarzy

///Błąd powoduje zatrzymanie się programu podczas przywoływania drugi raz funkcji f() (w moim kodzie zlokalizowany w funkcji Zadanie2())
///Z tego co się domyślam jest to spowodowane tym że funkcja f() wraz z usunięciem swojej wewnętrznej zmiennej automatycznej s uwuwa też
///   zmienną s.numbers z funkcji Zadanie2() (co sugeruje błąd jaki wyrzuca debugger podczas debugowania, a mianowicie podczas usuwania
///   this.numbers w destruktorze klasy StosDynamiczny)

#include <iostream>

using namespace std;

class StosDynamiczny
{
	int* numbers;
	int size;
	int topIndex = -1;

public:
#pragma region >>> Constructors and Destructors <<<

	StosDynamiczny(const StosDynamiczny& stos)
	{
		numbers = stos.numbers;
		size = stos.size;
		topIndex = stos.topIndex;
		cout << "Skonstruowalem (a raczej skopiowalem) stos <" << hex << &*this << "> o rozmiarze: " << dec << size << "\n";
	}
	StosDynamiczny(int _size)
	{
		size = _size;
		numbers = new int[_size];
		cout << "Skonstruowalem stos <" << hex << &*this << "> o rozmiarze: " << dec << size << "\n";
	}
	StosDynamiczny()
	{
		numbers = new int[16];
		cout << "Skonstruowalem stos <" << hex << &*this << "> o rozmiarze: "<< dec << 16 << " skoro nic nie podales...\n";
	}
	~StosDynamiczny()
	{
		//delete[] numbers;
		cout << "Zniszczylem stos <" << hex << &*this << ">.\n";
	}

#pragma endregion

#pragma region >>> Core Methods <<<

	bool Empty()
	{
		return (topIndex == -1);
	}
	bool Full()
	{
		return (topIndex == size - 1);
	}

	int Top()
	{
		if (!Empty())
			return numbers[topIndex];
		return INT32_MIN;
	}
	void Pop()
	{
		if (!Empty())
			topIndex--;
		else
			topIndex = -1;
	}
	void Push(int number)
	{
		if (Full())
			Expand();
		numbers[++topIndex] = number;
	}

	void Destroy()
	{
		delete[] numbers;
	}

#pragma endregion

#pragma region >>> Side Methods <<<

	void Expand()
	{
		size += 16;
		int* newArray = new int[size];
		for (int i = 0; i < size - 16; i++)
			newArray[i] = numbers[i];
		delete numbers;
		numbers = newArray;
	}

	int GetSize()
	{
		return size;
	}

#pragma endregion

};

void f(StosDynamiczny s, int a)
{
	s.Push(a);
}

void Zadanie2()
{

#pragma region Do not touch

	StosDynamiczny s;
	s.Push(0);
	f(s, 1);
	f(s, 2);
	while (!s.Empty()) {
		cout << s.Top() << "\n"; //<- "\n"- quality of life
		s.Pop();
	}

#pragma endregion

}

int main()
{
	Zadanie2();

	//StosDynamiczny test;
	//test.Push(27);
	//cout << test.Top();

	return 0;
}
