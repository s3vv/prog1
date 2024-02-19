#ifndef LINKEDLIST_
#define LINKEDLIST_

#include <fstream>
#include "node.h"

using std::fstream;

template<class T>
class linkedList
{
	private:
		node<T> * head;
		node<T> * misspelled;
		int size;
		long long int goodCom;
		long long int badCom;
		int inDict;
		int notInDict;
		int notChecked;
	public:
		linkedList()
		{
			head = nullptr;
			size = 0;
			goodCom = 0;
			badCom = 0;
			inDict = 0;
			notInDict = 0;
			notChecked = 0;
		}
		~linkedList();
		
		void insert(T item);
		void insert_misspelled(T item);
		void remove();
		bool find(T item);
		void write_file(fstream &file);
		int getSize()
		{
			return size;
		}
		bool isEmpty()
		{
			if (size == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		T cleanWord(T word);
		long int getCom(bool check)
		{
			if (check)
			{
				return goodCom;
			}
			else
			{
				return badCom;
			}
		}
		int getInDict(bool check)
		{
			if (check)
			{
				return inDict;
			}
			else
			{
				return notInDict;
			}
		}
		int getNotChecked()
		{
			return notChecked;
		}
};

#endif