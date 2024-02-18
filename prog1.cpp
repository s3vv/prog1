#include <iostream>
#include <fstream>
#include "linkedList.h"
#include "timer.h"

using std::cout;
using std::fstream;

template<class T>
linkedList<T>::~linkedList()
{
	while (size > 0)
	{
		remove();
	}
}

template<class T>
void linkedList<T>::insert(T item)
{
	node<T> * temp = new node<T>(item);
	temp -> next = head;
	head = temp;
	size++;
}

template<class T>
void linkedList<T>::remove()
{
	node<T> * temp;
	if (head != nullptr)
	{
		temp = head -> next;
		delete head;
		head = temp;
		size--;
	}
}

template <class T>
T linkedList<T>::cleanWord(T word)
{
	for (int x = 0; x<word.length(); x++)
	{
		if (!(isalnum(word[x]) || (word[x] == '\'')))
		{
			word.erase(word.begin() + x);
			x--;
		}
		if (isupper(word[x]))
		{
			word[x] = tolower(word[x]);
		}
	}
	return word;
}

template<class T>
bool linkedList<T>::find(T item)
{
	item = cleanWord(item);
	if (!isalpha(item[0]))
	{
		if(!(item[0] == '\0'))
		{
			notChecked++;
		}
		return false;
	}
	int com = 0;
	for (node<T> * temp = head; temp != nullptr; temp = temp -> next)
	{
		com++;
		if (item.compare(temp -> data) == 0)
		{
			goodCom += com;
			inDict++;
			return true;
		}
	}
	badCom += com;
	notInDict++;
	file << item << "\n";
	return false;
}

int main()
{
    fstream dict("dict.txt");
    fstream book("book.txt");
    Timer time;
    linkedList<string> strTest;
    string in;
    while(dict >> in)
	{   
        strTest.sort(in);
    }
    cout << "[+]\n";
    time.Start();
    string check;
    while(!book.eof())
	{
        book >> check;
        strTest.find(check, mispelledTxt);
    }
	time.Stop();
    dict.close();
    book.close();
    mispelledTxt.close();
    cout << "dictionary size " << strTest.getSize() << "\nDone checking and these are the results\n";
    cout << "finished in time: " << time.Time() << "\n";
    cout << "There are " << strTest.getInDict(1) << " words found in the dictionary\n";
    cout << "\t" << strTest.getCom(1) << " compares. Average: " << (strTest.getCom(1) / strTest.getInDict(1));
    cout << "\nThere are " << strTest.getInDict(0) << " words NOT found in the dictionary\n";
    cout << "\t" << strTest.getCom(0) << " compares. Average: " << (strTest.getCom(0) / strTest.getInDict(0));
    cout << "\nThere are " << strTest.getNotChecked() << " words not checked.\n";
    return 0;
}