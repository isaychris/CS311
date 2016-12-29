// ===============================================================
// HW#: HW7 - Hash
// Your name: Chris Banci
// Complier:  g++
// File type: hash implementation & client file.
//================================================================
#include<iostream>

using namespace std;

const int TABLE_SIZE = 128; // size of hash table.

// the class object that will be stored in an hash tables slot.
class HashEntry {
private:
	int key;		// the key to hash into an index.
	int value;		// the value to store at index.

public:

	// PURPOSE: Constructor for HashEntry
	// PARAMETERS: key = the key to store at index.
	//			   value = the value to store at index.
	HashEntry(int key, int value) {		
		this->key = key;
		this->value = value;
	}

	// PURPOSE: returns key in HashEntry
	int getKey() {		
		return key;
	}

	// PURPOSE: returns value in HashEntry
	int getValue() {	
		return value;
	}
};

// the class used to put new hash entries in hash table and retrieve.
class HashMap {
private:
	HashEntry **table;		// the hash table

public:

	// PURPOSE: Default constructor for HashMap.
	HashMap() {
		table = new HashEntry*[TABLE_SIZE];			// allocate memory for table

		// for each element
		for (int i = 0; i < TABLE_SIZE; i++)
			table[i] = NULL;						// set elements of table array to null
	}

	// PURPOSE: returns the value where key is.
	// PARAMETER: key = the index where the value is stored.
	// ALGORITHM: Keep probing until the key is found or when an empty slot is found.
	int get(int key) {
		////////////////////////////////////////////////
		int hash = (key % TABLE_SIZE); // hash the key to get an index.
		int probe = hash; // probe counter
		bool wrap = false; // boolean for to check if probe has wrapped around.
	
		// while hash is occupied
		while (table[hash] != NULL) {

			// if wrap true and probe is at hash, then it wasnt found, so return -1.
			if (wrap == true && probe == hash) {
				return -1;
			}

			// if the key at hash is equal to key, return the value of hash.
			if (table[hash]->getKey() == key) {
				return table[hash]->getValue();
			}
			
			// else, if key is not equal, keep probing.
			else {
				probe++;

				// if probe hits the last element, start from the beginning.
				if (probe == TABLE_SIZE - 1) {
					probe = 0;
					wrap = true;
				}
			}
		}

		// nothing was found, return -1.
		return -1;
	}

	// PURPOSE: inserts the value at key in the hash table.
	// PARAMETERS: key = the index to insert the value.
	//			   value = the value to insert at key.
	// ALGORITHM: Keep probing until an empty slot is found in array. 
	//			  Once a slot is found, insert a new hashentry.
	void put(int key, int value) {
		///////////////////////////////////////////////
		int hash = (key % TABLE_SIZE);  // hash the key to get an index.
		int probe = hash;				// probe counter

		// If index is empty, then insert new hash entry.
		if (table[hash] == NULL) {
			table[hash] = new HashEntry(key, value);
			//cout << table[hash]->getKey() << " | " << table[hash]->getValue() << endl;
		}

		// else if, index is not empty..
		else {

			//Linear Probing
			while (table[probe] != NULL) {
				probe++;

				// If probe hits the last element, start from the beginning.
				if (probe > TABLE_SIZE - 1) {
					probe = 0;
				}
			}

			// If index is empty, then insert new hash entry.
			if (table[probe] == NULL) {
				table[probe] = new HashEntry(key, value);
				// << table[probe]->getKey() << " | " << table[probe]->getValue() << endl;
			}
		}
	}

	//PURPOSE: Deconstructor for HashMap
	//ALGORITHM: deallocates the table and deletes the object.
	~HashMap() {
		// iteratate through table to delete all elements.
		for (int i = 0; i < TABLE_SIZE; i++)
			// if index is not null, delete.
			if (table[i] != NULL)
				delete table[i];
		delete[] table; // delete the object.
	}
};


// PURPOSE: To test the implementation of hash tables.
// ALGORITHM: Insert values into hash table, then the return value from get call.
int main()
{
	cout << "// Name: Chris Banci" << endl;
	cout << "// Assignment: HW7 - Hash" << endl;
	cout << "// Date: 12/04/16" << endl << endl;

	HashMap map;
	map.put(1, 1001);
	map.put(2, 1002);
	map.put(3, 1003);
	cout << map.get(1) << endl;
	cout << map.get(2) << endl;
	cout << map.get(3) << endl;
	cout << map.get(4) << endl;
	map.put(4, 1004);
	cout << map.get(4) << endl;
	return 0;
}